/*
 * Copyright 2021, 2024-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/* -------------------------------------------------------------------------- */
/*                                  Includes                                  */
/* -------------------------------------------------------------------------- */
#include <stdbool.h>

#include "fsl_common.h"
#include "fwk_config.h"
#include "fwk_platform_ics.h"
#include "fwk_platform.h"
#include "fwk_platform_sensors.h"
#include "fwk_platform_lowpower.h"
#include "FunctionLib.h"
#include "fsl_adapter_rpmsg.h"
#include "fwk_rf_sfc.h"
#include "fwk_debug.h"

#if defined(gPlatformIcsUseWorkqueueRxProcessing_d) && (gPlatformIcsUseWorkqueueRxProcessing_d > 0)
#include "fwk_workq.h"
#include "fsl_component_generic_list.h"
#include "fsl_component_mem_manager.h"
#include "fwk_hal_macros.h"
#endif

/* -------------------------------------------------------------------------- */
/*                               Private macros                               */
/* -------------------------------------------------------------------------- */

/* -------------------------------------------------------------------------- */
/*                                Private types                               */
/* -------------------------------------------------------------------------- */

#if defined(gPlatformIcsUseWorkqueueRxProcessing_d) && (gPlatformIcsUseWorkqueueRxProcessing_d > 0)
typedef struct
{
    list_element_t node;
    uint32_t       len;
    uint8_t       *data;
} rx_data_t;

typedef struct
{
    fwk_work_t   work;
    list_label_t pending;
} rx_work_t;
#endif

/* -------------------------------------------------------------------------- */
/*                              Public prototypes                             */
/* -------------------------------------------------------------------------- */

/* declared here to avoid including ble_controller header file */
extern uint32_t Controller_HandleNbuApiReq(uint8_t *api_return, uint8_t *data, uint32_t data_len);
extern bool     Controller_EnableSecurityFeature();

/* -------------------------------------------------------------------------- */
/*                             Private prototypes                             */
/* -------------------------------------------------------------------------- */

static int                       PLATFORM_FwkSrvSendPacket(eFwkSrvMsgType msg_type, void *msg, uint16_t msg_lg);
static hal_rpmsg_return_status_t PLATFORM_FwkSrv_RxCallBack(void *param, uint8_t *data, uint32_t len);
static bool                      FwkSrv_MsgTypeInExpectedSet(uint8_t msg_type);

static void PLATFORM_RxNbuVersionRequest(uint8_t *data, uint32_t len);
static void PLATFORM_RxXtal32MTrimIndication(uint8_t *data, uint32_t len);
static void PLATFORM_RxNbuApiRequest(uint8_t *data, uint32_t len);
static void PLATFORM_RxTemperatureIndication(uint8_t *data, uint32_t len);
static void PLATFORM_RxHostChipRevision(uint8_t *data, uint32_t len);
static void PLATFORM_RxNbuSecureModeRequest(uint8_t *data, uint32_t len);
static void PLATFORM_RxNbuWakeUpDelayLpoCycle(uint8_t *data, uint32_t len);
static void PLATFORM_RxNbuFrequencyConstraint(uint8_t *data, uint32_t len);
static void PLATFORM_RxNbuSfcConfig(uint8_t *data, uint32_t len);
static void PLATFORM_RxEnableFroNotification(uint8_t *data, uint32_t len);
static void PLATFORM_RxRngReseed(uint8_t *data, uint32_t len);

#if defined(gPlatformIcsUseWorkqueueRxProcessing_d) && (gPlatformIcsUseWorkqueueRxProcessing_d > 0)
static void PLATFORM_RxWorkHandler(fwk_work_t *work);
#endif

/* -------------------------------------------------------------------------- */
/*                         Private memory declarations                        */
/* -------------------------------------------------------------------------- */

static RPMSG_HANDLE_DEFINE(fwkRpmsgHandle);
const static hal_rpmsg_config_t fwkRpmsgConfig = {
    .local_addr  = 100,
    .remote_addr = 110,
};

static void (*PLATFORM_RxCallbackService[gFwkSrvHost2NbuLast_c - gFwkSrvHost2NbuFirst_c - 1U])(uint8_t *data,
                                                                                               uint32_t len) = {
    PLATFORM_RxNbuVersionRequest,
    PLATFORM_RxXtal32MTrimIndication,
    PLATFORM_RxNbuApiRequest,
    PLATFORM_RxTemperatureIndication,
    PLATFORM_RxHostChipRevision,
    PLATFORM_RxNbuSecureModeRequest,
    PLATFORM_RxNbuWakeUpDelayLpoCycle,
    PLATFORM_RxNbuFrequencyConstraint,
    PLATFORM_RxNbuSfcConfig,
    PLATFORM_RxEnableFroNotification,
    PLATFORM_RxRngReseed,
};

#if defined(gPlatformIcsUseWorkqueueRxProcessing_d) && (gPlatformIcsUseWorkqueueRxProcessing_d > 0)
static rx_work_t rx_work = {
    .work.handler = PLATFORM_RxWorkHandler,
};
#endif

static seed_ready_event_callback_t seed_ready_callback = (seed_ready_event_callback_t)NULL;

/* -------------------------------------------------------------------------- */
/*                              Public functions                              */
/* -------------------------------------------------------------------------- */

int PLATFORM_FwkSrvInit(void)
{
    int result = 0;

    static bool_t mFwkSrvInit = FALSE;

    do
    {
        if (mFwkSrvInit == TRUE)
        {
            result = 1;
            break;
        }

#if defined(gPlatformIcsUseWorkqueueRxProcessing_d) && (gPlatformIcsUseWorkqueueRxProcessing_d > 0)
        LIST_Init(&rx_work.pending, 0U);
        (void)WORKQ_InitSysWorkQ();
#endif

        if (kStatus_HAL_RpmsgSuccess !=
            HAL_RpmsgInit((hal_rpmsg_handle_t)fwkRpmsgHandle, (hal_rpmsg_config_t *)&fwkRpmsgConfig))
        {
            result = -1;
            break;
        }

        if (kStatus_HAL_RpmsgSuccess !=
            HAL_RpmsgInstallRxCallback((hal_rpmsg_handle_t)fwkRpmsgHandle, PLATFORM_FwkSrv_RxCallBack, NULL))
        {
            result = -2;
            break;
        }

        /* Flag initialization on module */
        mFwkSrvInit = TRUE;
    } while (false);

    return result;
}

int PLATFORM_SendNbuVersionIndication(void)
{
    return PLATFORM_FwkSrvSendPacket(gFwkSrvNbuVersionIndication_c, (void *)&nbu_version, sizeof(NbuInfo_t));
}

int PLATFORM_NotifyNbuInitDone(void)
{
    return PLATFORM_FwkSrvSendPacket(gFwkSrvNbuInitDone_c, (void *)NULL, 0);
}

int PLATFORM_NotifyNbuMemFull(unsigned short poolId, uint16_t bufferSize)
{
    NbuDbgMemInfo_t memInfo = {0}; /* useless but rids of Coverity UNINIT - reserved field remained uninitialized */
    memInfo.poolId          = poolId;
    memInfo.bufferSize      = bufferSize;

    return PLATFORM_FwkSrvSendPacket(gFwkSrvNbuMemFullIndication_c, (void *)&memInfo, sizeof(memInfo));
}

int PLATFORM_FwkSrvSetLowPowerConstraint(uint8_t mode)
{
    return PLATFORM_FwkSrvSendPacket(gFwkSrvHostSetLowPowerConstraint_c, (void *)&mode, sizeof(mode));
}

int PLATFORM_FwkSrvReleaseLowPowerConstraint(uint8_t mode)
{
    return PLATFORM_FwkSrvSendPacket(gFwkSrvHostReleaseLowPowerConstraint_c, (void *)&mode, sizeof(mode));
}

int PLATFORM_NotifyNbuIssue(void)
{
    return PLATFORM_FwkSrvSendPacket(gFwkSrvNbuIssueIndication_c, (void *)NULL, 0);
}

int PLATFORM_NotifyNbuEvent(NbuEvent_t *event)
{
    int ret = 0;

    do
    {
        if (event == NULL)
        {
            ret = -3; /* Invalid param */
            break;
        }

        /* returns 0 if success, -1 if no memory available, -2 if sending error */
        ret = PLATFORM_FwkSrvSendPacket(gFwkSrvNbuEventIndication_c, (void *)event, (uint16_t)sizeof(NbuEvent_t));
    } while (false);

    return ret;
}

int PLATFORM_NotifySecurityEvents(uint32_t securityEventBitmask)
{
    return PLATFORM_FwkSrvSendPacket(gFwkSrvNbuSecurityEventIndication_c, (void *)&securityEventBitmask,
                                     sizeof(uint32_t));
}

void PLATFORM_FwkSrvFreeRxPacket(void *pPacket)
{
    HAL_RpmsgFreeRxBuffer(fwkRpmsgHandle, (uint8_t *)pPacket - 4U);
}

int PLATFORM_FwkSrvFroInfo(uint16_t freq, int16_t ppm_mean, int16_t ppm, uint16_t fro_trim)
{
    uint8_t tab[8];
    tab[0] = (uint8_t)freq;
    tab[1] = (uint8_t)(freq >> 8U);
    tab[2] = (uint8_t)ppm_mean;
    tab[3] = (uint8_t)(ppm_mean >> 8U);
    tab[4] = (uint8_t)ppm;
    tab[5] = (uint8_t)(ppm >> 8U);
    tab[6] = (uint8_t)fro_trim;
    tab[7] = (uint8_t)(fro_trim >> 8U);
    return (PLATFORM_FwkSrvSendPacket(gFwkSrvFroNotification_c, tab, (uint16_t)sizeof(tab)));
}

int PLATFORM_RequestRngSeedToHost(void)
{
    return PLATFORM_FwkSrvSendPacket(gFwkSrvNbuRequestRngSeed_c, (void *)NULL, 0);
}

int PLATFORM_FwkSrvRequestNewTemperature(uint32_t periodic_interval_ms)
{
    return PLATFORM_FwkSrvSendPacket(gFwkSrvNbuRequestNewTemperature_c, (void *)&periodic_interval_ms,
                                     sizeof(uint32_t));
}

void PLATFORM_RegisterSetNewSeed(seed_ready_event_callback_t cb)
{
    seed_ready_callback = cb;
}

/* -------------------------------------------------------------------------- */
/*                              Private functions                             */
/* -------------------------------------------------------------------------- */
#if defined(gPlatformIcsUseWorkqueueRxProcessing_d) && (gPlatformIcsUseWorkqueueRxProcessing_d > 0)
static void PLATFORM_RxWorkHandler(fwk_work_t *work)
{
    list_element_t *node;
    rx_data_t      *rx_data;
    (void)work;

    node = LIST_RemoveHead(&rx_work.pending);

    while (node != NULL)
    {
        rx_data = CONTAINER_OF(node, rx_data_t, node);
        PLATFORM_RxCallbackService[rx_data->data[0] - gFwkSrvHost2NbuFirst_c - 1U](rx_data->data, rx_data->len);
        (void)MEM_BufferFree(rx_data);
        node = LIST_RemoveHead(&rx_work.pending);
    }
}
#endif

static int PLATFORM_FwkSrvSendPacket(eFwkSrvMsgType msg_type, void *msg, uint16_t msg_lg)
{
    uint8_t *buf    = NULL;
    int      result = 0;
    uint32_t sz     = ((uint32_t)msg_lg + 1);

    PWR_DBG_LOG("fwk Send Pkt %x type=%d sz=%d", msg, msg_type, msg_lg);

    /* Request SOC XBAR access */
    PLATFORM_RemoteActiveReqWithoutDelay();

    do
    {
        buf = HAL_RpmsgAllocTxBuffer((hal_rpmsg_handle_t)fwkRpmsgHandle, sz);
        if (NULL == buf)
        {
            result = -1;
            break;
        }
        buf[0] = (uint8_t)msg_type;
        if (msg != NULL && msg_lg != 0)
        {
            FLib_MemCpy(&buf[1], (uint8_t *)msg, msg_lg);
        }

        if (kStatus_HAL_RpmsgSuccess != HAL_RpmsgNoCopySend((hal_rpmsg_handle_t)fwkRpmsgHandle, buf, (uint32_t)sz))
        {
            result = -2;
            break;
        }
    } while (false);

    /* Release SOC XBAR access */
    PLATFORM_RemoteActiveRel();

    return result;
}

static hal_rpmsg_return_status_t PLATFORM_FwkSrv_RxCallBack(void *param, uint8_t *data, uint32_t len)
{
    hal_rpmsg_return_status_t res = kStatus_HAL_RL_RELEASE;
    uint8_t                   msg_type;

    msg_type = data[0];

    PWR_DBG_LOG("fwk Rcv Pkt %x type=%d sz=%d", data, msg_type, len - 1U);

    if (FwkSrv_MsgTypeInExpectedSet(msg_type))
    {
#if defined(gPlatformIcsUseWorkqueueRxProcessing_d) && (gPlatformIcsUseWorkqueueRxProcessing_d > 0)
        bool process_now = false;
        do
        {
            rx_data_t *rx_data = MEM_BufferAlloc(sizeof(rx_data_t) + len);

            if (rx_data == NULL)
            {
                /* allocation failed - process in the ISR to avoid losing the data
                 * TODO: use the error callback mechanism to forward the error to the application */
                process_now = true;
                break;
            }

            rx_data->data = (uint8_t *)rx_data + sizeof(rx_data_t);
            rx_data->len  = len;
            (void)memcpy(rx_data->data, data, len);
            (void)LIST_AddTail(&rx_work.pending, &rx_data->node);
            if (WORKQ_Submit(&rx_work.work) < 0)
            {
                process_now = true;
                break;
            }
        } while (false);

        if (process_now == true)
#endif
        {
            PLATFORM_RxCallbackService[msg_type - gFwkSrvHost2NbuFirst_c - 1U](data, len);
        }
    }
    return res;
}

static bool FwkSrv_MsgTypeInExpectedSet(uint8_t msg_type)
{
    return (msg_type > gFwkSrvHost2NbuFirst_c && msg_type < gFwkSrvHost2NbuLast_c);
}

static void PLATFORM_RxNbuVersionRequest(uint8_t *data, uint32_t len)
{
    (void)data;
    (void)len;
    (void)PLATFORM_SendNbuVersionIndication();
}

static void PLATFORM_RxXtal32MTrimIndication(uint8_t *data, uint32_t len)
{
    (void)len;
    PLATFORM_SetXtal32MhzTrim(data[1]);
}

static void PLATFORM_RxNbuApiRequest(uint8_t *data, uint32_t len)
{
    uint32_t nb_returns;
    uint8_t  ind[1U + NBU_API_MAX_RETURN_PARAM_LENGTH]; /* rpmsg status + API status + API outputs */
    uint16_t ind_len;

    /* execute the API */
    nb_returns = Controller_HandleNbuApiReq(&ind[1], data + 1U, len - 1U);
    assert((nb_returns > 0U) && (nb_returns <= NBU_API_MAX_RETURN_PARAM_LENGTH));

    /* indication message: 1 byte rpmsg status followed by 4 bytes api status */
    if (nb_returns != 0)
    {
        ind[0U] = 1U; // rpmsg success, API could still fail
        ind_len = 1U + nb_returns;
    }
    else
    {
        ind[0U] = 0U; // rpmsg failure: API does not exist etc.
        ind_len = 1U;
    }
    (void)PLATFORM_FwkSrvSendPacket(gFwkSrvNbuApiIndication_c, (void *)&ind[0U], ind_len);
}

static void PLATFORM_RxTemperatureIndication(uint8_t *data, uint32_t len)
{
    /* data[0] is the API id */
    /* data[1-4] is the temperature as signed 32 bits - little endian */
    int32_t temperature = *((int32_t *)&data[1]);
    PLATFORM_SaveTemperatureValue(temperature);
}

static void PLATFORM_RxHostChipRevision(uint8_t *data, uint32_t len)
{
    PLATFORM_SetChipRevision(data[1]);
}

static void PLATFORM_RxNbuSecureModeRequest(uint8_t *data, uint32_t len)
{
#if defined(DEBUG)
    bool rmpsg_status;

    /* execute the API */
    rmpsg_status = Controller_EnableSecurityFeature();
    assert(rmpsg_status);
    (void)rmpsg_status;
#else  /*defined(DEBUG)*/
    (void)Controller_EnableSecurityFeature();
#endif /*defined(DEBUG)*/
}

static void PLATFORM_RxNbuWakeUpDelayLpoCycle(uint8_t *data, uint32_t len)
{
#if !defined(FPGA_TARGET) || (FPGA_TARGET == 0)
    PLATFORM_SetWakeupDelay(data[1]);
#endif
}

static void PLATFORM_RxNbuFrequencyConstraint(uint8_t *data, uint32_t len)
{
    PLATFORM_SetFrequencyConstraintFromHost(data[1]);
}

static void PLATFORM_RxNbuSfcConfig(uint8_t *data, uint32_t len)
{
#if !defined(FPGA_TARGET) || (FPGA_TARGET == 0)
    sfc_config_t sfc_config;
    uint32_t     data_len     = len - 1U;
    uint32_t     size_to_copy = (data_len < sizeof(sfc_config_t)) ? data_len : sizeof(sfc_config_t);

    memset(&sfc_config, 0U, sizeof(sfc_config_t));
    memcpy(&sfc_config, (sfc_config_t *)&data[1], size_to_copy);
    SFC_UpdateConfig((const sfc_config_t *)&sfc_config);
#endif
}

static void PLATFORM_RxEnableFroNotification(uint8_t *data, uint32_t len)
{
#if !defined(FPGA_TARGET) || (FPGA_TARGET == 0)
    SFC_EnableNotification(data[1]);
#endif
}

static void PLATFORM_RxRngReseed(uint8_t *data, uint32_t len)
{
    if (seed_ready_callback != NULL && len > 1U)
    {
        (void)seed_ready_callback(&data[1]);
    }
}
