"""
Handles LPC55S6x specific clock signals
"""

import logging
import helpers

# List of registers to power off clock sources, LPC55S69 specific. This
# information is not in SDK source data.
PDOWN_REGS = {
    "XTAL32M": ("PMC::PDRUNCFG0", ["PDEN_LDOXO32M", "PDEN_XTAL32M"]),
    "XTAL32K": ("PMC::PDRUNCFG0", ["PDEN_XTAL32K"]),
    "fro_32k": ("PMC::PDRUNCFG0", ["PDEN_FRO32K"]),
}

def handle_soc_signals(peripheral_map, signal, level, proc_name):
    """
    Handles "special case" signals for the LPC55S6x series
    @param peripheral_map: peripheral map used to resolve reset values
    @param signal: signal to parse and output devicetree for
    @param level: indentation level of output devicetree
    @param proc_name: Processor name
    Returns string describing devicetree for this node, or empty string
    if the signal is not handled
    """
    if "FRGCTRL" in signal["id"]:
        # Special case- generate a compatible for the FRG node
        frgdiv = signal["children"][0]
        # Determine the div register and bitfield width
        (reg_expr, _) = frgdiv["source"].find("divide").get('expr').split("+")
        (reg, bitfield) = reg_expr.split('[')
        # Strip trailing "] " from bitfield
        bitfield = bitfield[:-2]
        (reg_offset, width, offset) = helpers.get_addr_and_bitfield(peripheral_map,
                                                        reg, bitfield)
        dts = "\n"
        dts += helpers.indent_string(f"{signal['id'].lower()}: ", level)
        dts += f"{signal['id'].lower().replace('_','-')}@{reg_offset:x} {{\n"
        dts += helpers.indent_string(f"compatible = \"nxp,syscon-flexfrg\";\n", level + 1)
        dts += helpers.indent_string(f"#clock-cells = <1>;\n", level + 1)
        # Write register offset and width
        dts += helpers.indent_string(f"/* {reg}[{bitfield}] */\n", level + 1)
        dts += helpers.indent_string(f"reg = <0x{reg_offset:x} 0x{width:x}>;\n", level + 1)
        # Generate children of frgdiv
        dts += helpers.generate_children(peripheral_map, frgdiv, level, proc_name)
        dts += helpers.indent_string("};\n", level)
        return dts
    elif "RTCCLK1" in signal["id"]:
        # Generate node for RTC clock divider
        (add_factor, reg_expr) = signal["source"].find("divide").get('expr').split("+")
        (reg, bitfield) = reg_expr.split('[')
        # Strip trailing "] " from bitfield
        bitfield = bitfield[:-1]
        (reg_offset, width, offset) = helpers.get_addr_and_bitfield(peripheral_map,
                                                        reg, bitfield)
        dts = "\n"
        dts += helpers.indent_string(f"{signal['id'].lower()}: ", level)
        dts += f"{signal['id'].lower().replace('_','-')}@{reg_offset:x} {{\n"
        dts += helpers.indent_string(f"compatible = \"nxp,syscon-rtcclk\";\n", level + 1)
        dts += helpers.indent_string(f"#clock-cells = <1>;\n", level + 1)
        # Write register offset and width
        dts += helpers.indent_string(f"/* {reg}[{bitfield}] */\n", level + 1)
        dts += helpers.indent_string(f"reg = <0x{reg_offset:x} 0x{width:x}>;\n", level + 1)
        dts += helpers.indent_string(f"offset = <0x{offset:x}>;\n", level + 1)
        dts += helpers.indent_string(f"add-factor = <{add_factor}>;\n", level + 1)
        # Generate children
        dts += helpers.generate_children(peripheral_map, signal, level, proc_name)
        dts += helpers.indent_string("};\n", level)
        return dts
    elif "PDEC" in signal["id"]:
        # PLL PDEC scalers
        reg_expr = signal["source"].find("conditional_block/case/divide").get('expr')
        (reg, bitfield) = reg_expr.split('[')
        # Strip trailing "] " from bitfield
        bitfield = bitfield[:-1]
        return helpers.generate_node_with_compat(peripheral_map, signal, level,
                                                 proc_name, "nxp,lpc55sxx-pll-pdec",
                                                 1, reg, bitfield)
    elif signal["type"] == "pll":
        if signal['id'] == "PLL0":
            (reg_offset, width, offset) = helpers.get_addr_and_bitfield(peripheral_map,
                    "SYSCON::PLL0CTRL", "SELR")
            dts = "\n"
            dts += helpers.indent_string(f"{signal['id'].lower()}: ", level)
            dts += f"{signal['id'].lower().replace('_','-')}@{reg_offset:x} {{\n"
            # PLL0, with spread spectrum generator
            dts += helpers.indent_string(f"compatible = \"nxp,lpc55sxx-pll0\";\n", level + 1)
            dts += helpers.indent_string(f"reg = <0x{reg_offset:x} 0x20>;\n", level + 1)
            dts += helpers.indent_string(f"#clock-cells = <9>;\n", level + 1)
        elif signal['id'] == "PLL1":
            # PLL1, standard fractional PLL
            (reg_offset, width, offset) = helpers.get_addr_and_bitfield(peripheral_map,
                    "SYSCON::PLL1CTRL", "SELR")
            dts = "\n"
            dts += helpers.indent_string(f"{signal['id'].lower()}: ", level)
            dts += f"{signal['id'].lower().replace('_','-')}@{reg_offset:x} {{\n"
            dts += helpers.indent_string(f"compatible = \"nxp,lpc55sxx-pll1\";\n", level + 1)
            dts += helpers.indent_string(f"reg = <0x{reg_offset:x} 0x20>;\n", level + 1)
            dts += helpers.indent_string(f"#clock-cells = <6>;\n", level + 1)
        else:
            logging.warning("Unmatched PLL ID %s", signal["id"])
            return ""
        # Generate children
        dts += helpers.generate_children(peripheral_map, signal, level, proc_name)
        dts += helpers.indent_string("};\n", level)
        return dts
    elif signal["id"] in PDOWN_REGS:
        # Clock source signal that supports being powered off
        signal_xml = signal["source"]
        enable_xml = signal_xml.find("configuration_element/item/assigns/assign")
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
        dts += helpers.indent_string(f"compatible = \"nxp,syscon-clock-source\";\n", level + 1)
        dts += helpers.indent_string(f"offset = <0x{offset:x}>;\n", level + 1)
        dts += helpers.indent_string(f"#clock-cells = <1>;\n", level + 1)
        (pdown_periph, pdown_bitfields) = PDOWN_REGS[signal['id']]
        pdown_bitmask = 0
        for field in pdown_bitfields:
            (_, _, pdown_offset) = helpers.get_addr_and_bitfield(
                peripheral_map, pdown_periph, field
            )
            pdown_bitmask |= (0x1 << pdown_offset)
        # Write register name as comment
        dts += helpers.indent_string(f"/* {pdown_periph}[{' | '.join(pdown_bitfields)}] */\n", level + 1)
        dts += helpers.indent_string(f"pdown-mask = <0x{pdown_bitmask:x}>;\n", level + 1)
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
        # Generate children
        dts += helpers.generate_children(peripheral_map, signal, level, proc_name)
        dts += helpers.indent_string("};\n", level)
        return dts
    else:
        return ""
