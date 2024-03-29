#!/usr/bin/env python3
import xml.etree.ElementTree as ET
from collections import namedtuple
import logging
import argparse
import os
import sys
import datetime
import pathlib

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

def get_addr_and_bitfield(peripheral_map, reg_expr, bitfield):
    """
    Helper function to get the register address, bitfield width, and bitfield
    offset for register expression
    @param peripheral_map: map of peripheral names to peripheral objects
    @param reg_expr: expression describing register, formatted as PERIPHERAL::REGISTER
    @param bitfield: name of bitfield to read from
    @return tuple of (register address, bitfield width, bitfield offset)
    """
    # Read the bitfield and register expression (peripheral + reg)
    (periph, reg) = reg_expr.split("::")
    # Get register offset and bitfield
    reg_addr = peripheral_map[periph].get_reg_addr(reg)
    bitfield_offset = (peripheral_map[periph].get_register(reg).
                        get_bit_field_offset(bitfield))
    bitfield_width = (peripheral_map[periph].get_register(reg).
                        get_bit_field_width(bitfield))
    return (reg_addr, bitfield_width, bitfield_offset)

def parse_freq(freq):
    """
    Helper function to parse human readable frequency expression into
    an integer frequency
    @param freq: frequency expression to parse
    """
    freq_base = int(freq.split()[0])
    freq_unit = freq.split()[1]
    if freq_unit == "GHz":
        freq_base *= 1000000000
    elif freq_unit == "MHz":
        freq_base *= 1000000
    elif freq_unit == "KHz":
        freq_base *= 1000000
    elif freq_unit == "Hz":
        pass
    else:
        logging.warning("Unmatched frequency unit %s", freq_unit)
    return freq_base

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
        enable_type = output_map.find("enable")
        if (enable_type is not None) and (enable_type.get("cond_expr") is not None):
            # This output signal can be disabled with a register, so it should
            # be treated like a clock gate
            signal_type = "clock_enable"
            # Use the output map XML as the signal source
            xml = output_map
        else:
            signal_type = "output_clock_signal"
            xml = signal_xml
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
        for child in signal_xml.find("value_map"):
            mux_idx = child.get("ctrl_value")
            while (len(signal["parents"])) != int(mux_idx):
                # There are gaps in some <value_map> definitions.
                # These gaps also map to no clock selected in the register,
                # so just fill the parent list with NO_CLOCK elements
                signal["parents"].append(signal_map["NO_CLOCK"])
            if child.tag == "input":
                input_id = child.get("signal")
                (new_component, input_xml) = resolve_input_id(active_component,
                                                            input_id)
                logging.debug("%s[%s] => %s", signal_xml.get("id"),
                            mux_idx, input_xml.get("id"))
                # Define input signal
                input_signal = define_signal(new_component, input_xml)
                # Add signal to clock selection. Note that we intentionally
                # don't add MUX nodes as children of signals, since we
                # treat MUX nodes like parents in the devicetree
                signal["parents"].append(input_signal)
            elif child.tag == "no_clock":
                # Special "no clock" selection index
                signal["parents"].append(signal_map["NO_CLOCK"])
                logging.debug("%s[%s] => NONE", signal_xml.get("id"), mux_idx)
            else:
                logging.warning("Unhandled mux input type %s", child.tag)
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

def handle_special_signals(peripheral_map, signal, level):
    """
    Handles "special case" signals, which need generation different than
    what can be handled in the standard signal output function
    @param peripheral_map: peripheral map used to resolve reset values
    @param signal: signal to parse and output devicetree for
    @param level: indentation level of output devicetree
    Returns string describing devicetree for this node, or empty string
    if the signal is not handled
    """
    indent_str = ""
    for i in range(level):
        indent_str += "\t"

    if "FRGCTRL" in signal["id"]:
        # Special case- generate a compatible for the FRG node
        frgdiv = signal["children"][0]
        # Determine the div register and bitfield width
        (reg_expr, _) = frgdiv["source"].find("divide").get('expr').split("+")
        (reg, bitfield) = reg_expr.split('[')
        # Strip trailing "] " from bitfield
        bitfield = bitfield[:-2]
        (reg_offset, width, offset) = get_addr_and_bitfield(peripheral_map,
                                                        reg, bitfield)
        dts = f"\n{indent_str}{signal['id'].lower()}: "
        dts += f"{signal['id'].lower().replace('_','-')}@{reg_offset:x} {{\n"
        dts += f"{indent_str}\tcompatible = \"nxp,syscon-flexfrg\";\n"
        # Write register offset and width
        dts += f"{indent_str}\t/* {reg}[{bitfield}] */;\n"
        dts += f"{indent_str}\treg = <0x{reg_offset:x}>;\n"
        dts += f"{indent_str}}};\n"
        # Do not generate children
        return dts
    elif "RTCCLK1" in signal["id"]:
        # Generate node for RTC clock divider
        (add_factor, reg_expr) = signal["source"].find("divide").get('expr').split("+")
        (reg, bitfield) = reg_expr.split('[')
        # Strip trailing "] " from bitfield
        bitfield = bitfield[:-1]
        (reg_offset, width, offset) = get_addr_and_bitfield(peripheral_map,
                                                        reg, bitfield)
        dts = f"\n{indent_str}{signal['id'].lower()}: "
        dts += f"{signal['id'].lower().replace('_','-')}@{reg_offset:x} {{\n"
        dts += f"{indent_str}\tcompatible = \"nxp,syscon-rtcclk\";\n"
        # Write register offset and width
        dts += f"{indent_str}\t/* {reg}[{bitfield}] */;\n"
        dts += f"{indent_str}\treg = <0x{reg_offset:x}>;\n"
        dts += f"{indent_str}\tmask-width = <{width}>;\n"
        dts += f"{indent_str}\toffset = <{offset}>;\n"
        dts += f"{indent_str}\tadd-factor = <{add_factor}>;\n"
        # Generate children
        for child in signal['children']:
            dts += output_signal(peripheral_map, child, level + 1)
        dts += f"{indent_str}}};\n"
        return dts
    else:
        return ""

def output_signal(peripheral_map, signal, level):
    """
    Outputs signal definitions into devicetree format
    @param peripheral_map: peripheral map used to resolve reset values
    @param signal: signal to parse and output devicetree for
    @param level: indentation level of output devicetree
    Returns string describing devicetree for this node
    """
    indent_str = ""
    for i in range(level):
        indent_str += "\t"
    if signal["type"] == "output_clock_signal":
        dts = ""
        # Generate children
        for child in signal['children']:
            dts += output_signal(peripheral_map, child, level)
        return dts

    # Handle special signal cases
    dts = handle_special_signals(peripheral_map, signal, level)
    if dts != "":
        return dts

    if signal["type"] == "clock_source":
        # Get the address and offset of the bit that enables
        # the clock source
        signal_xml = signal["source"]
        enable_xml = signal_xml.find("configuration_element/item/assigns/assign")
        if enable_xml is not None:
            bitfield = enable_xml.get("bit_field")
            periph_reg = enable_xml.get("register")
            (reg_addr, width, offset) = get_addr_and_bitfield(peripheral_map,
                                                            periph_reg,
                                                            bitfield)
            if width != 1:
                logging.warning("Clock source register %s has width >1", periph_reg)
        else:
            # Fallback to empty values
            reg_addr = 0
            offset = 0
        # Now that we know register, write the node definition
        dts = f"\n{indent_str}{signal['id'].lower()}: "
        dts += f"{signal['id'].lower().replace('_','-')}@{reg_addr:x} {{\n"
        dts += f"{indent_str}\tcompatible = \"nxp,syscon-clock-source\";\n"
        if enable_xml is not None:
            # Write register name as comment
            dts += f"{indent_str}\t/* {periph_reg}[{bitfield}] */\n"
        dts += f"{indent_str}\treg = <0x{reg_addr:x}>;\n"
        dts += f"{indent_str}\toffset = <{offset}>;\n"

        # Get clock frequency
        if ((signal_xml.find("internal_source") is not None)and
                (signal_xml.find("internal_source").find("fixed_frequency") is not None)):
            freq = signal_xml.find("internal_source").find("fixed_frequency").get("freq")
            freq_base = parse_freq(freq)
        elif ((signal_xml.find("external_source") is not None) and
                (signal_xml.find("external_source").get("default_freq") is not None)):
            # External clock frequency, with default value
            freq = signal_xml.find("external_source").get("default_freq")
            freq_base = parse_freq(freq)
            dts += f"{indent_str}\t/* External clock source (default {freq}) */\n"
        else:
            # External clock frequency, set by user
            freq_base = 0
            dts += f"{indent_str}\t/* External clock source */\n"
        dts += f"{indent_str}\tfrequency = <{freq_base}>;\n"
    elif signal["type"] == "clock_enable":
        # Get the address and offset of the bit that enables
        # the clock source
        signal_xml = signal["source"]
        enable_xml = signal_xml.find("configuration_element/item/assigns/assign")
        if enable_xml is not None:
            bitfield = enable_xml.get("bit_field")
            periph_reg = enable_xml.get("register")
            (reg_addr, width, offset) = get_addr_and_bitfield(peripheral_map,
                                                            periph_reg,
                                                            bitfield)
            if width != 1:
                logging.warning("Clock gate register %s has width >1", periph_reg)
        else:
            # Fallback to empty values
            reg_addr = 0
            offset = 0
        # Now that we know register, write the node definition
        dts = f"\n{indent_str}{signal['id'].lower()}: "
        dts += f"{signal['id'].lower().replace('_','-')}@{reg_addr:x} {{\n"
        dts += f"{indent_str}\tcompatible = \"nxp,syscon-clock-gate\";\n"
        if enable_xml is not None:
            # Write register name as comment
            dts += f"{indent_str}\t/* {periph_reg}[{bitfield}] */\n"
        dts += f"{indent_str}\treg = <0x{reg_addr:x}>;\n"
        dts += f"{indent_str}\toffset = <{offset}>;\n"
    elif signal["type"] == "no_clock":
        dts = f"\n{indent_str}{signal['id'].lower()}: {signal['id'].lower().replace('_','-')} {{\n"
        dts += f"{indent_str}\tcompatible = \"no-clock\";\n"
    elif signal["type"] == "clock_select":
        # Determine the mux register and bitfield width
        reg_expr = signal["source"].find("value_map").get('expr')
        (reg, bitfield) = reg_expr.split('[')
        # Strip trailing "]" from bitfield
        bitfield = bitfield[:-1]
        (reg_offset, width, offset) = get_addr_and_bitfield(peripheral_map,
                                                        reg, bitfield)
        # Write node with register address
        dts = f"\n{indent_str}{signal['id'].lower()}: "
        dts += f"{signal['id'].lower().replace('_','-')}@{reg_offset:x} {{\n"
        dts += f"{indent_str}\tcompatible = \"nxp,syscon-clock-mux\";\n"
        # Write register address, mask, and width
        dts += f"{indent_str}\t/* {reg}[{bitfield}] */\n"
        dts += f"{indent_str}\treg = <0x{reg_offset:x}>;\n"
        dts += f"{indent_str}\tmask-width = <{width}>;\n"
        dts += f"{indent_str}\toffset = <{offset}>;\n"
        # Add input sources
        input_str = f"{indent_str}\tinput-sources = <"
        source_names = []
        for i in range(len(signal["parents"])):
            source = signal["parents"][i]
            if source["type"] == "output_clock_signal":
                # Use the parent of the source as the true clock input
                source_id = source["parents"][0]["id"].lower()
            else:
                source_id = source["id"].lower()
            input_str += f"&{source_id} "
            source_names.append(source_id)
            if (len(input_str) > 60) and (i < (len(signal["parents"]) - 1)):
                # More signals to define, move to a newline
                input_str = input_str[:-1] + "\n"
                dts += input_str
                input_str = f"{indent_str}\t\t\t"
        # Strip tailing space, add >;
        dts += input_str[:-1] + ">;\n"
    elif signal["type"] == "prescaler":
        if signal["source"].find("divide") is not None:
            # Determine the div register and bitfield width
            (_, reg_expr) = signal["source"].find("divide").get('expr').split("+")
            (reg, bitfield) = reg_expr.split('[')
            # Strip trailing "]" from bitfield
            bitfield = bitfield[:-1]
            (reg_offset, width, offset) = get_addr_and_bitfield(peripheral_map,
                                                            reg, bitfield)
            dts = f"\n{indent_str}{signal['id'].lower()}: "
            dts += f"{signal['id'].lower().replace('_','-')}@{reg_offset:x} {{\n"
            dts += f"{indent_str}\tcompatible = \"nxp,syscon-clock-div\";\n"
            # Write register offset and width
            dts += f"{indent_str}\t/* {reg}[{bitfield}] */;\n"
            dts += f"{indent_str}\treg = <0x{reg_offset:x}>;\n"
            dts += f"{indent_str}\tmask-width = <{width}>;\n"
            if offset != 0:
                logging.warning("Clock divider %s has invalid offset", reg_expr)
        else:
            logging.warning("Prescaler %s has unknown type, skipping", signal["id"])
            # Skip DTS generation
            return ""
    elif signal["type"] == "pll":
        dts = f"\n{indent_str}{signal['id'].lower()}: {signal['id'].lower().replace('_','-')} {{\n"
        # Integer-n pll (F_vco = F_in * (NUM / DIV))
        dts += f"{indent_str}\tcompatible = \"nxp,clock-pll\";\n"
        dts += f"{indent_str}\tstatus=\"disabled\";\n"
    elif signal["type"] == "fnpll":
        dts = f"\n{indent_str}{signal['id'].lower()}: {signal['id'].lower().replace('_','-')} {{\n"
        # Fractional-n pll (F_vco = F_in * (N + (NUM / DIV))
        dts += f"{indent_str}\tcompatible = \"nxp,clock-frac-pll\";\n"
        dts += f"{indent_str}\tstatus=\"disabled\";\n"
    else:
        logging.warning("Unmatched signal type %s", signal["type"])
    # Generate children
    for child in signal['children']:
        dts += output_signal(peripheral_map, child, level+1)
    dts += f"{indent_str}}};\n"
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
    # Unknown processor family
    return "UNKNOWN"


def main():
    args = parse_args()

    temp_dir = datapack_utils.extract_pack(args.data_pack)
    data_version = datapack_utils.get_pack_version(temp_dir.name)
    print(f"Found data pack version {data_version}")
    if round(data_version) != 13:
        print("Warning: This tool is only verified for data pack version 13, "
            "other versions may not work")

    proc_name = datapack_utils.get_processor_name(temp_dir.name)
    if not args.dts_output:
        # Get SOC name from datapack
        args.dts_output = proc_name.lower() + "_clocks.dtsi"
    if not args.controller:
        args.controller = processor_to_clock_node(proc_name)

    if args.controller == "UNKNOWN":
        print("Warning- script has not been tested with this SOC. You can"
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
    dts += "\n\t/* Root clock sources */"
    for root in root_clocks:
        dts += output_signal(peripheral_map, root, 1)
    dts += "\n\t/* Clock muxes */"
    for mux in clock_muxes:
        dts += output_signal(peripheral_map, mux, 1)
    dts += "};\n"
    f = open(args.dts_output, "w")
    f.write(dts)
    f.close()
    print(f"DTS written to {args.dts_output}")

if __name__ == "__main__":
    main()
