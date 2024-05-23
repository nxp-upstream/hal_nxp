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
        # FIRC_48 and FIRC_144 are both "clock sources" that really act more
        # like gates, which source their clock frequency from the FIRC block
        # We generate these nodes under the FIRC clock node, so skip generation
        # here.
        return "\n"
    elif signal["id"] == "PLL":
        # USB PLL
        return helpers.generate_node_with_compat(peripheral_map, signal, level,
                                                 proc_name, "nxp,mcxn9x-usb-pll",
                                                 1, "SCG0::SPLLCSR", None)
    elif signal["id"] == "FIRC":
        # Fast Internal Reference Clock. We generate firc_48m and firc_144m
        # as children of this node.
        (reg_addr, width, _) = helpers.get_addr_and_bitfield(peripheral_map,
                                                        "SCG0::FIRCCSR",
                                                        None)
        # Now that we know register, write the node definition
        dts = "\n"
        dts += helpers.indent_string(f"{signal['id'].lower()}: ", level)
        dts += f"{signal['id'].lower().replace('_','-')}@{reg_addr:x} {{\n"
        dts += helpers.indent_string(f"compatible = \"nxp,mcxn9x-firc\";\n", level + 1)
        dts += helpers.indent_string(f"#clock-cells = <1>;\n", level + 1)
        # Write register name as comment
        dts += helpers.indent_string(f"/* SCG0::FIRCCSR */\n", level + 1)
        dts += helpers.indent_string(f"reg = <0x{reg_addr:x} 0x{width:x}>;\n", level + 1)
        dts += helpers.generate_children(peripheral_map, signal, level, proc_name)
        # Hardcode FIRC_48M and FIRC_144M nodes. Both are clock gates,
        # but FIRC_48M routes from a fixed divider of 3
        dts += "\n"
        dts += helpers.indent_string(f"firc_144m: firc-144m@{reg_addr:x} {{\n", level + 1)
        dts += helpers.indent_string("compatible = \"nxp,syscon-clock-gate\";\n", level + 2)
        dts += helpers.indent_string("#clock-cells = <1>;\n", level + 2)
        dts += helpers.indent_string("/* SCG0::FIRCCSR[FIRC_FCLK_PERIPH_EN] */\n", level + 2)
        (reg_addr, width, offset) = helpers.get_addr_and_bitfield(peripheral_map,
                                                        "SCG0::FIRCCSR",
                                                        "FIRC_FCLK_PERIPH_EN")
        dts += helpers.indent_string(f"reg = <0x{reg_addr:x} 0x{width:x}>;\n", level + 2)
        dts += helpers.indent_string(f"offset = <0x{offset:x}>;\n", level + 2)
        dts += helpers.indent_string("};\n", level + 1)
        dts += "\n"
        dts += helpers.indent_string(f"firc_div3: firc-div3m {{\n", level + 1)
        dts += helpers.indent_string("compatible = \"fixed-divider\";\n", level + 2)
        dts += helpers.indent_string("#clock-cells = <0>;\n", level + 2)
        dts += helpers.indent_string("divider = <3>;\n", level + 2)
        dts += helpers.indent_string(f"#address-cells = <1>;\n", level + 2)
        dts += helpers.indent_string(f"#size-cells = <1>;\n", level + 2)
        dts += "\n"
        dts += helpers.indent_string(f"firc_48m: firc-48m@{reg_addr:x} {{\n", level + 2)
        dts += helpers.indent_string("compatible = \"nxp,syscon-clock-gate\";\n", level + 3)
        dts += helpers.indent_string("#clock-cells = <1>;\n", level + 3)
        dts += helpers.indent_string("/* SCG0::FIRCCSR[FIRC_SCLK_PERIPH_EN] */\n", level + 3)
        (reg_addr, width, offset) = helpers.get_addr_and_bitfield(peripheral_map,
                                                        "SCG0::FIRCCSR",
                                                        "FIRC_SCLK_PERIPH_EN")
        dts += helpers.indent_string(f"reg = <0x{reg_addr:x} 0x{width:x}>;\n", level + 3)
        dts += helpers.indent_string(f"offset = <0x{offset:x}>;\n", level + 3)
        dts += helpers.indent_string("};\n", level + 2)
        dts += helpers.indent_string("};\n", level + 1)
        dts += helpers.indent_string("};\n", level)
        return dts
    elif signal["id"] == "PLL0":
        # APLL
        return helpers.generate_node_with_compat(peripheral_map, signal, level,
                                                 proc_name, "nxp,mcxn9x-pll",
                                                 6, "SCG0::APLLCSR", None)
    elif signal["id"] == "PLL1":
        # SPLL
        return helpers.generate_node_with_compat(peripheral_map, signal, level,
                                                 proc_name, "nxp,mcxn9x-pll",
                                                 6, "SCG0::SPLLCSR", None)
    elif "PDIV" in signal["id"]:
        # PLL PDIV scalers
        reg_expr = signal["source"].find("conditional_block/case/divide").get('expr')
        (reg, bitfield) = reg_expr.split('[')
        # Strip trailing "] " from bitfield
        bitfield = bitfield[:-1]
        # MCX source data defines these registers as "xPLLPDEC"
        reg = reg.replace("PDIV", "PDEC")
        return helpers.generate_node_with_compat(peripheral_map, signal, level,
                                                 proc_name, "nxp,mcxn9x-pll-pdec",
                                                 1, reg, bitfield)
    elif "TRIMDIV" in signal["id"]:
        # TRIMDIV scalers for FIRC and SIRC
        reg_expr = signal["source"].find("divide").get('expr')
        (reg, bitfield) = reg_expr.split('[')
        # Trim 1+ from register
        reg = reg[2:]
        # Trim ] from bitfield
        bitfield = bitfield[:-1]
        return helpers.generate_node_with_compat(peripheral_map, signal, level,
                                                 proc_name, "nxp,mcxn9x-irc-trimdiv",
                                                 1, reg, bitfield)
    else:
        return ""
