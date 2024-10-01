"""
Implements handlers for generating common clock signals. These
signals are shared across all multiple SOC lines.
"""
import helpers
import logging
import re

# Regex helper to extract register and bitfield from expression like
# the following: SYSCON0::FROHFDIV[DIV]+1, or 1+SYSCON0::TRACECLKDIV[DIV]
re_div_expr = re.compile(r'(\d\+([\w\d:]+)\[(\w+)\])|(([\w\d:]+)\[(\w+)\]\+\d)')

def output_clock_enable(peripheral_map, signal, level):
    """
    Outputs a devicetree description for a clock enable
    @param peripheral_map: peripheral map used to resolve reset values
    @param signal: signal to parse and output devicetree for
    @param level: indentation level of output devicetree
    Returns string describing devicetree for this node
    """
    # Get the address and offset of the bit that enables
    # the clock source
    signal_xml = signal["source"]
    enable_xml = signal_xml.find("configuration_element/item/assigns/assign")
    if enable_xml is not None:
        bitfield = enable_xml.get("bit_field")
        periph_reg = enable_xml.get("register")
        (reg_addr, width, offset) = helpers.get_addr_and_bitfield(peripheral_map,
                                                        periph_reg,
                                                        bitfield)
        if width != 1:
            logging.warning("Clock gate register %s has width >1", periph_reg)
    else:
        # Fallback to empty values
        reg_addr = 0
        offset = 0
    # Now that we know register, write the node definition
    dts = "\n"
    dts += helpers.indent_string(f"{signal['id'].lower()}: ", level)
    dts += f"{signal['id'].lower().replace('_','-')}@{reg_addr:x} {{\n"
    dts += helpers.indent_string(f"compatible = \"nxp,syscon-clock-gate\";\n", level + 1)
    dts += helpers.indent_string(f"#clock-cells = <1>;\n", level + 1)
    if enable_xml is not None:
        # Write register name as comment
        dts += helpers.indent_string(f"/* {periph_reg}[{bitfield}] */\n", level + 1)
    dts += helpers.indent_string(f"reg = <0x{reg_addr:x} 0x{width:x}>;\n", level + 1)
    dts += helpers.indent_string(f"offset = <0x{offset:x}>;\n", level + 1)
    return dts

def output_clock_source(peripheral_map, signal, level):
    """
    Outputs a devicetree description for a clock source
    @param peripheral_map: peripheral map used to resolve reset values
    @param signal: signal to parse and output devicetree for
    @param level: indentation level of output devicetree
    Returns string describing devicetree for this node
    """
    # Get the address and offset of the bit that enables
    # the clock source
    signal_xml = signal["source"]
    enable_xml = signal_xml.find("configuration_element/item/assigns/assign")
    if enable_xml is not None:
        bitfield = enable_xml.get("bit_field")
        periph_reg = enable_xml.get("register")
        (reg_addr, width, offset) = helpers.get_addr_and_bitfield(peripheral_map,
                                                        periph_reg,
                                                        bitfield)
        if width != 1:
            logging.warning("Clock source register %s has width >1", periph_reg)
        # Now that we know register, write the node definition
        dts = "\n"
        dts += helpers.indent_string(f"{signal['id'].lower()}: ", level)
        dts += f"{signal['id'].lower().replace('_','-')}@{reg_addr:x} {{\n"
        dts += helpers.indent_string(f"compatible = \"clock-source\";\n", level + 1)
        dts += helpers.indent_string(f"gate-offset = <0x{offset:x}>;\n", level + 1)
        dts += helpers.indent_string(f"#clock-cells = <1>;\n", level + 1)
        # Write register name as comment
        dts += helpers.indent_string(f"/* {periph_reg}[{bitfield}] */\n", level + 1)
        dts += helpers.indent_string(f"reg = <0x{reg_addr:x} 0x{width:x}>;\n", level + 1)
        # Get clock frequency
        if ((signal_xml.find("internal_source") is not None)and
                (signal_xml.find("internal_source").find("fixed_frequency") is not None)):
            freq = signal_xml.find("internal_source").find("fixed_frequency").get("freq")
            freq_base = helpers.parse_freq(freq)
        elif ((signal_xml.find("external_source") is not None) and
                (signal_xml.find("external_source").get("default_freq") is not None)):
            # External clock frequency, with default value
            freq = signal_xml.find("external_source").get("default_freq")
            freq_base = helpers.parse_freq(freq)
            dts += helpers.indent_string(f"/* External clock source (default {freq}) */\n", level + 1)
        elif signal_xml.find("external_source") is not None:
            # External clock frequency, no default value
            dts += helpers.indent_string(f"/* External clock source */\n", level + 1)
            freq_base = 0
        else:
            logging.warning("Unrecognized source type %s, skipping", signal["id"])
            return ""
        dts += helpers.indent_string(f"frequency = <{freq_base}>;\n", level + 1)
    else:
        # Use a fixed clock source
        dts = "\n"
        dts += helpers.indent_string(f"{signal['id'].lower()}: ", level)
        dts += f"{signal['id'].lower().replace('_','-')} {{\n"
        dts += helpers.indent_string(f"compatible = \"fixed-clock-source\";\n", level + 1)
        dts += helpers.indent_string(f"#clock-cells = <0>;\n", level + 1)
        dts += helpers.indent_string(f"/* External clock source */\n", level + 1)
        dts += helpers.indent_string(f"frequency = <0>;\n", level + 1)
    return dts

def output_no_clock(signal, level):
    """
    Outputs node description for the "no_clock" node, a special node
    indicating the mux is mapped to no input.
    @param signal: signal to parse and output devicetree for
    @param level: indentation level of output devicetree
    Returns string describing devicetree for this node
    """
    dts = "\n"
    dts += helpers.indent_string(f"{signal['id'].lower()}: ", level)
    dts += f"{signal['id'].lower().replace('_','-')} {{\n"
    dts += helpers.indent_string(f"/* Dummy node- indicates no clock source was selected */\n", level + 1)
    dts += helpers.indent_string(f"compatible = \"fixed-clock-source\";\n", level + 1)
    dts += helpers.indent_string(f"#clock-cells = <0>;\n", level + 1)
    dts += helpers.indent_string(f"frequency = <0>;\n", level + 1)
    return dts

def output_clock_select(peripheral_map, signal, level):
    """
    Outputs signal definitions for clock selectors into devicetree format
    @param peripheral_map: peripheral map used to resolve reset values
    @param signal: signal to parse and output devicetree for
    @param level: indentation level of output devicetree
    Returns string describing devicetree for this node
    """
    # Determine the mux register and bitfield width
    reg_expr = signal["source"].find("value_map").get('expr')
    (reg, bitfield) = reg_expr.split('[')
    # Strip trailing "]" from bitfield
    bitfield = bitfield[:-1]
    (reg_offset, width, offset) = helpers.get_addr_and_bitfield(peripheral_map,
                                                    reg, bitfield)
    # Write node with register address
    dts = "\n"
    dts += helpers.indent_string(f"{signal['id'].lower()}: ", level)
    dts += f"{signal['id'].lower().replace('_','-')}@{reg_offset:x} {{\n"
    dts += helpers.indent_string(f"compatible = \"nxp,syscon-clock-mux\";\n", level + 1)
    dts += helpers.indent_string(f"#clock-cells = <1>;\n", level + 1)
    # Write register address, mask, and width
    dts += helpers.indent_string(f"/* {reg}[{bitfield}] */\n", level + 1)
    dts += helpers.indent_string(f"reg = <0x{reg_offset:x} 0x{width:x}>;\n", level + 1)
    dts += helpers.indent_string(f"offset = <0x{offset:x}>;\n", level + 1)
    if "MAINCLKSEL" in signal['id']:
        # Main clock selects are safe muxes, add this property
        dts += helpers.indent_string(f"safe-mux;\n", level + 1)
    # Add input sources
    input_str = helpers.indent_string(f"input-sources = <", level + 1)
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
            input_str = helpers.indent_string("", level + 3)
    # Strip tailing space, add >;
    dts += input_str[:-1] + ">;\n"
    return dts

def output_clock_prescaler(peripheral_map, signal, level):
    if signal["source"].find("divide") is not None:
        div_expr = signal["source"].find("divide").get('expr')
        if div_expr.isdigit():
            # Fixed divider
            dts = "\n"
            dts += helpers.indent_string(f"{signal['id'].lower()}: ", level)
            dts += f"{signal['id'].lower().replace('_','-')} {{\n"
            dts += helpers.indent_string(f"compatible = \"fixed-clock-divider\";\n", level + 1)
            dts += helpers.indent_string(f"#clock-cells = <0>;\n", level + 1)
            dts += helpers.indent_string(f"divider = <{int(div_expr, 0)}>;\n", level + 1)
        else:
            # Determine the div register and bitfield width
            match = re_div_expr.match(div_expr)
            if match.group(2):
                # Formatted like 1+reg_expr
                (reg, bitfield) = (match.group(2), match.group(3))
            elif match.group(4):
                # Formatted like reg_expr+1
                (reg, bitfield) = (match.group(5), match.group(6))
            (reg_offset, width, offset) = helpers.get_addr_and_bitfield(peripheral_map,
                                                            reg, bitfield)
            dts = "\n"
            dts += helpers.indent_string(f"{signal['id'].lower()}: ", level)
            dts += f"{signal['id'].lower().replace('_','-')}@{reg_offset:x} {{\n"
            dts += helpers.indent_string(f"compatible = \"nxp,syscon-clock-div\";\n", level + 1)
            dts += helpers.indent_string(f"#clock-cells = <1>;\n", level + 1)
            # Write register offset and width
            dts += helpers.indent_string(f"/* {reg}[{bitfield}] */\n", level + 1)
            dts += helpers.indent_string(f"reg = <0x{reg_offset:x} 0x{width:x}>;\n", level + 1)
            if offset != 0:
                logging.warning("Clock divider %s[%s] has invalid offset", reg, bitfield)
    elif signal["source"].find("multiply") is not None:
        mult_expr = signal["source"].find("multiply").get("expr")
        if mult_expr.isdigit():
            # Fixed multiplier
            dts = "\n"
            dts += helpers.indent_string(f"{signal['id'].lower()}: ", level)
            dts += f"{signal['id'].lower().replace('_','-')} {{\n"
            dts += helpers.indent_string(f"compatible = \"fixed-clock-multiplier\";\n", level + 1)
            dts += helpers.indent_string(f"#clock-cells = <0>;\n", level + 1)
            dts += helpers.indent_string(f"multiplier = <{int(mult_expr, 0)}>;\n", level + 1)
        else:
            logging.warning("Variable multiplier on prescaler %s, not supported", signal["id"])
    else:
        logging.warning("Prescaler %s has unknown type, skipping", signal["id"])
        # Skip DTS generation
        return ""
    return dts
