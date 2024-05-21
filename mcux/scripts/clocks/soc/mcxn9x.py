"""
Handles MCXN9X specific clock signals
"""

import logging
import helpers

def handle_soc_signals(peripheral_map, signal, level, proc_name):
    """
    Handles "special case" signals for the MCXN9X series
    @param peripheral_map: peripheral map used to resolve reset values
    @param signal: signal to parse and output devicetree for
    @param level: indentation level of output devicetree
    @param proc_name: Processor name
    Returns string describing devicetree for this node, or empty string
    if the signal is not handled
    """
    if signal["id"] == "PFD_FRAC_DIV":
        # PFD variable divider for *18 PLL multiplier.
        reg_expr = signal["source"].find("divide").get("expr")
        (reg, bitfield) = reg_expr.split('[')
        # Strip trailing "] " from bitfield
        bitfield = bitfield[:-1]
        return helpers.generate_node_with_compat(peripheral_map, signal, level,
                                                 proc_name, "nxp,mcxn9x-pfd-frac",
                                                 1, reg, bitfield)
    elif signal["id"] == "FIRC_48M" or signal["id"] == "FIRC_144M":
        # 48 MHz/144 MHz internal reference clock gate
        signal_xml = signal["source"]
        enable_xml = signal_xml.find("configuration_element/item/assigns/assign")
        bitfield = enable_xml.get("bit_field")
        periph_reg = "SCG0::" + enable_xml.get("register")
        (reg_addr, width, offset) = helpers.get_addr_and_bitfield(peripheral_map,
                                                        periph_reg,
                                                        bitfield)
        if width != 1:
            logging.warning("Clock source register %s has width >1", periph_reg)
        # Now that we know register, write the node definition
        dts = "\n"
        dts += helpers.indent_string(f"{signal['id'].lower()}: ", level)
        dts += f"{signal['id'].lower().replace('_','-')}@{reg_addr:x} {{\n"
        dts += helpers.indent_string(f"compatible = \"nxp,syscon-clock-gate\";\n", level + 1)
        dts += helpers.indent_string(f"offset = <0x{offset:x}>;\n", level + 1)
        dts += helpers.indent_string(f"#clock-cells = <1>;\n", level + 1)
        # Write register name as comment
        dts += helpers.indent_string(f"/* {periph_reg}[{bitfield}] */\n", level + 1)
        dts += helpers.indent_string(f"reg = <0x{reg_addr:x} 0x{width:x}>;\n", level + 1)
        dts += helpers.indent_string("}\n", level)
        return dts
    else:
        return ""
