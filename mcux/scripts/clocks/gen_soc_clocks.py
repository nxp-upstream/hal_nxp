#!/usr/bin/env python3
import xml.etree.ElementTree as ET
from collections import namedtuple
import logging
import argparse
import os
import sys
import datetime
import pathlib
import helpers
import common_clocks
import soc_clocks

# Add shared utils to path
SHARED_DIR = os.path.join(os.path.dirname(os.path.abspath(__file__)), os.pardir)
sys.path.append(SHARED_DIR)

from lib import datapack_utils, registers


HELPSTR="""
Generates SOC clock devicetree from NXP MCUX configuration files

Given a processor data pack, generates the SOC level clock control DTSI
definitions required for Zephyr. This tool is intended to be used with the
configuration data downloaded from NXP's MCUXpresso SDK builder
"""

NXP_COPYRIGHT=f"""/*
 * Copyright {datetime.date.today().year} NXP
 *
 * SPDX-License-Identifier: Apache-2.0
 */\n
"""

signal_map = {"NO_CLOCK":
        {"id" : "NO_CLOCK",
        "type": "no_clock",
        "source": None,
        "parents": [],
        "children": []}
}

# Contains XML source data for clock component file
ClockComponent = namedtuple("ClockComponent", [
    "interface", # <interface> XML tag within component
    "implementation", # <implementation> XML tag within component
    "input_map" # <signal_map> XML tag in TOP.xml for this component instance
    ])

# Maps component names to ClockComponent tuples
clock_components = {}
# Root clocks: <clock_source> tag in XML
root_clocks = [signal_map["NO_CLOCK"]]
# Clock muxes, treated as roots in DTS: <clock_select> tag in XML
clock_muxes = []

def resolve_input_id(active_component, input_id):
    """
    Helper function, which will resolve an input ID to the xml component for
    that signal.
    @param active_component: current clock component being processed
    @param input_id: ID of clock signal we must resolve to XML element
    Returns a tuple of (input_component, input_xml), where:
    input_component: clock component storing input signal XML definition
    input_xml: XML component for the input signal
    """
    if input_id.endswith(".clk"):
        # Signal defined in this XML component
        signal_id = input_id.split(".")[0]
        # Reuse current component
        input_component = active_component
        input_implementation = input_component.implementation
        input_xml = next(x for x in input_implementation if x.get("id") == signal_id)
    elif "." in input_id:
        # Signal defined as output_clock in another component
        component = input_id.split(".")[0]
        signal_id = input_id.split(".")[1]
        # Select new component
        input_component = clock_components[component]
        input_interface = input_component.interface
        # Locate <output_clock> XML definition
        outputs = input_interface.findall("output_clock_signal")
        input_xml = next(x for x in outputs if x.get("id") == signal_id)
    elif next((x for x in active_component.input_map if
            x.get("component_signal") == input_id), None) is not None:
        # Signal is defined as an input_clock to this component
        input_ops = (x for x in active_component.input_map if x.get("component_signal") == input_id)
        true_id = next(input_ops).get("signal")
        # True ID can be parsed in the same way output clock ID can
        component = true_id.split(".")[0]
        signal_id = true_id.split(".")[1]
        input_component = clock_components[component]
        input_interface = input_component.interface
        # Locate <output_clock> XML definition
        outputs = input_interface.findall("output_clock_signal")
        input_xml = next(x for x in outputs if x.get("id") == signal_id)
    else:
        # Signal is defined as an output clock in this component
        input_component = active_component
        input_interface = input_component.interface
        outputs = input_interface.findall("output_clock_signal")
        input_xml = next(x for x in outputs if x.get("id") == input_id)

    return (input_component, input_xml)

def define_signal(active_component, signal_xml):
    """
    @param active_component: current clock component being processed
    @param signal_xml: xml data for signal to define
    """
    # if signal is in map
    if signal_xml.get("id") in signal_map:
        # base, case return existing signal
        return signal_map[signal_xml.get("id")]
    # if signal is clock source
    if signal_xml.tag == "clock_source":
        # base case, add signal id to map
        signal = {"id" : signal_xml.get("id"),
                "type": signal_xml.tag,
                "source": signal_xml,
                "parents": [],
                "children": []}
        logging.debug("ROOT: %s", signal["id"])
        signal_map[signal_xml.get("id")] = signal
        root_clocks.append(signal)
        return signal
    # recursive case, parse input signals
    # read input clock signals
    if signal_xml.tag == "output_clock_signal":
        # Find implementation input clock
        output_maps = active_component.implementation.findall("map_output")
        output_map = next(x for x in output_maps if x.get("id") == signal_xml.get("id"))
        configuration = output_map.find("configuration_element")
        signal_type = "output_clock_signal"
        xml = signal_xml
        if configuration is not None:
            for item in configuration.findall("item"):
                if item.get("id") == "Enable":
                    # This output signal can be disabled with a register, so it should
                    # be treated like a clock gate
                    signal_type = "clock_enable"
                    # Use the output map XML as the signal source
                    xml = output_map
        input_id = output_map.find("input").get("signal")
        (new_component, input_xml) = resolve_input_id(active_component, input_id)
        logging.debug("%s => %s", signal_xml.get("id"), input_xml.get("id"))
        # Define input signal
        input_signal = define_signal(new_component, input_xml)
        # Define this signal
        signal = {"id" : signal_xml.get("id"),
                "type": signal_type,
                "source": xml,
                "parents": [input_signal],
                "children": []}
        signal_map[signal_xml.get("id")] = signal
        input_signal["children"].append(signal)
        return signal
    elif ((signal_xml.tag == "prescaler") or
            (signal_xml.tag == "clock_enable") or
            (signal_xml.tag == "pll") or
            (signal_xml.tag == "fnpll")):
        input_id = signal_xml.find("input").get("signal")
        (new_component, input_xml) = resolve_input_id(active_component, input_id)
        logging.debug("%s => %s", signal_xml.get("id"), input_xml.get("id"))
        # Define input signal
        input_signal = define_signal(new_component, input_xml)
        # Define this signal
        signal = {"id" : signal_xml.get("id"),
                "type": signal_xml.tag,
                "source": signal_xml,
                "parents": [input_signal],
                "children": []}
        signal_map[signal_xml.get("id")] = signal
        input_signal["children"].append(signal)
        return signal
    elif signal_xml.tag == "clock_select":
        # Clock select muxes need each input signal to be parsed and defined
        signal = {"id" : signal_xml.get("id"),
                "type": signal_xml.tag,
                "source": signal_xml,
                "parents": [],
                "children": []}
        signal_map[signal_xml.get("id")] = signal
        mux_sources = {}
        for child in signal_xml.find("value_map"):
            mux_idx = int(child.get("ctrl_value"))
            if child.tag == "input":
                input_id = child.get("signal")
                (new_component, input_xml) = resolve_input_id(active_component,
                                                            input_id)
                logging.debug("%s[%d] => %s", signal_xml.get("id"),
                            mux_idx, input_xml.get("id"))
                # Define input signal
                input_signal = define_signal(new_component, input_xml)
            elif child.tag == "no_clock":
                logging.debug("%s[%d] => NONE", signal_xml.get("id"), mux_idx)
                input_signal = signal_map["NO_CLOCK"]
            else:
                logging.warning("Unhandled mux input type %s", child.tag)
            mux_sources[mux_idx] = input_signal
        # Now, generate mux array
        mux_array = []
        for idx in range(max(mux_sources.keys()) + 1):
            if idx in mux_sources:
                mux_array.append(mux_sources[idx])
            else:
                # Assume gaps in mux mapping select no clock input
                mux_array.append(signal_map["NO_CLOCK"])
        # Now, optimize the mux array list by stripping any extra "no_clock"
        # references from the end of the array.
        while mux_array[-2] == signal_map["NO_CLOCK"]:
            mux_array.pop()
        # Set signal parents. Note we do not set multiplexers as children of
        # nodes, since we treat them as root clock nodes in the devicetree
        signal["parents"] = mux_array
        clock_muxes.append(signal)
        return signal
    else:
        logging.warning("Unhandled signal tag <%s>", signal_xml.tag)
        signal = {"id" : signal_xml.get("id"),
                "type": signal_xml.tag,
                "source": signal_xml,
                "parents": [],
                "children": []}
        return signal

def output_signal(peripheral_map, signal, level, proc_name):
    """
    Outputs signal definitions into devicetree format
    @param peripheral_map: peripheral map used to resolve reset values
    @param signal: signal to parse and output devicetree for
    @param level: indentation level of output devicetree
    @param proc_name: Processor name, used for special case signals handling
    Returns string describing devicetree for this node
    """
    if signal["type"] == "output_clock_signal":
        dts = ""
        if len(signal['children']) == 0:
            # Generate output clock
            dts = "\n"
            signal_id = signal['id']
            if '.' in signal_id:
                signal_id = signal_id.split('.')[1]
            dts += helpers.indent_string(f"{signal_id.lower()}: ", level)
            dts += f"{signal_id.lower().replace('_','-')} {{\n"
            dts += helpers.indent_string(f"compatible = \"clock-output\";\n", level + 1)
            dts += helpers.indent_string(f"#clock-cells = <1>;\n", level + 1)
            dts += helpers.indent_string("};\n", level)
        # Generate children
        for child in signal['children']:
            dts += output_signal(peripheral_map, child, level, proc_name)
        return dts

    # Handle special signal cases
    dts = soc_clocks.handle_soc_signals(peripheral_map, signal, level, proc_name)
    if dts != "":
        return dts

    if signal["type"] == "clock_source":
        dts = common_clocks.output_clock_source(peripheral_map, signal, level)
    elif signal["type"] == "clock_enable":
        dts = common_clocks.output_clock_enable(peripheral_map, signal, level)
    elif signal["type"] == "no_clock":
        dts = common_clocks.output_no_clock(signal, level)
    elif signal["type"] == "clock_select":
        dts = common_clocks.output_clock_select(peripheral_map, signal, level)
    elif signal["type"] == "prescaler":
        dts = common_clocks.output_clock_prescaler(peripheral_map, signal, level)
    else:
        logging.warning("Unmatched signal type %s", signal["type"])
    dts += helpers.generate_children(peripheral_map, signal, level, proc_name)
    dts += helpers.indent_string("};\n", level)
    return dts

def parse_args():
    parser = argparse.ArgumentParser(
            prog="clock-gen.py",
            description=HELPSTR,
            epilog=("Example: ./gen_soc_clocks.py LPCXpresso55S69_ConfigTools_data.zip"))
    parser.add_argument('--copyright', action='store_true',
                        help='Enable default NXP copyright')
    parser.add_argument("data_pack", metavar="DATA_PACK", type=str,
                        help="Path to downloaded data package zip")
    parser.add_argument('--dts-output', metavar = 'DTS_OUT', type=str,
                        help='Output file for clock devicetree')
    parser.add_argument("--controller", metavar='CTRL', type=str,
                        help="clock controller node label for SOC.")
    parser.add_argument("--debug", action="store_true",
                        help="Enable debug logging")
    return parser.parse_args()

def processor_to_clock_node(processor_name):
    """
    Returns clock node name for processor, or UNKNOWN if
    processor is unknown
    """
    # Select family of pin controller based on SOC type
    if "IMXRT1" in processor_name:
        return 'ccm'
    if "IMXRT5" in processor_name:
        return 'syscon'
    if "LPC55" in processor_name:
        return 'syscon'
    if "MCX" in processor_name:
        return 'syscon'
    # Unknown processor family
    return "UNKNOWN"


def main():
    args = parse_args()

    temp_dir = datapack_utils.extract_pack(args.data_pack)
    data_version = datapack_utils.get_pack_version(temp_dir.name)
    print(f"Found data pack version {data_version}")
    if round(data_version) != 15:
        print("Warning: This tool is only verified for data pack version 15, "
            "other versions may not work")

    proc_name = datapack_utils.get_processor_name(temp_dir.name)
    if not args.dts_output:
        # Get SOC name from datapack
        args.dts_output = proc_name.lower() + "_clocks.dtsi"
    if not args.controller:
        args.controller = processor_to_clock_node(proc_name)

    if args.controller == "UNKNOWN":
        print("Warning- script has not been tested with this SOC. You can "
                "manually specify the controller type if you'd like to proceed")
        sys.exit(255)

    # Find the clock TOP.xml file, and register definition file
    clock_dir = f"{temp_dir.name}/processors/{proc_name}/ksdk2_0/clocks"
    top = ET.parse(f"{clock_dir}/TOP.xml")
    top_root = top.getroot()

    proc_root = pathlib.Path(temp_dir.name) / 'processors'
    search_pattern = "*/ksdk2_0/*/registers"
    register_dir = next(proc_root.glob(search_pattern))
    peripheral_map = registers.load_peripheral_map(register_dir)

    # Set log level
    if args.debug:
        logging.getLogger().setLevel(logging.DEBUG)
    else:
        logging.getLogger().setLevel(logging.WARNING)

    # Build map of all clock components
    for child in top_root.find("component").find("implementation").findall("component_instance"):
        component = ET.parse(f"{clock_dir}/{child.get('file')}").getroot()
        interface = component.find("interface")
        implementation = component.find("implementation")
        input_map = child.find("signal_map")
        clock_components[child.get("id")] = ClockComponent(interface,
                                                    implementation, input_map)

    clock_components["TOP"] = ClockComponent(top_root.find("component").find("interface"),
                        top_root.find("component").find("implementation"), None)
    # Locate all output clock signals
    for child in top_root.find('component').find('interface'):
        logging.debug("TOP %s", child.get("id"))
        # Build clock tree recursively (top up)
        define_signal(clock_components["TOP"], child)

    # Parse all root clocks top down, and generate devicetree
    if args.copyright:
        dts = NXP_COPYRIGHT
    else:
        dts = ""
    dts += "/* Generated from NXP MCUX clock data */\n"
    dts += f"&{args.controller} {{\n"
    dts += f"\t#address-cells = <1>;\n"
    dts += f"\t#size-cells = <1>;\n"
    dts += "\n\t/* Root clock sources */"
    for root in root_clocks:
        dts += output_signal(peripheral_map, root, 1, proc_name)
    dts += "\n\t/* Clock muxes */"
    for mux in clock_muxes:
        dts += output_signal(peripheral_map, mux, 1, proc_name)
    dts += "};\n"
    f = open(args.dts_output, "w")
    f.write(dts)
    f.close()
    print(f"DTS written to {args.dts_output}")

if __name__ == "__main__":
    main()
