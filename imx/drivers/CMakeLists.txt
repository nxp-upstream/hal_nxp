zephyr_include_directories(.)

if(CONFIG_SOC_MCIMX7D_M4)
zephyr_library_sources(
  ccm_imx7d.c
  ccm_analog_imx7d.c
)
endif()

if(CONFIG_SOC_MCIMX6X_M4)
zephyr_library_sources(
  ccm_imx6sx.c
  ccm_analog_imx6sx.c
)
zephyr_library_sources_ifdef(CONFIG_ADC_VF610   adc_imx6sx.c)
endif()

zephyr_library_sources_ifdef(CONFIG_COUNTER_IMX_EPIT	epit.c)
zephyr_library_sources_ifdef(CONFIG_GPIO_IMX		gpio_imx.c)
zephyr_library_sources_ifdef(CONFIG_I2C_IMX		i2c_imx.c)
zephyr_library_sources_ifdef(CONFIG_IPM_IMX		mu_imx.c)
zephyr_library_sources_ifdef(CONFIG_UART_IMX		uart_imx.c)
