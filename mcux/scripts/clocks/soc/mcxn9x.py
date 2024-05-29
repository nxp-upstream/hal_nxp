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
    if signal["id"] == "FIRC_48M" or signal["id"] == "FIRC_144M":
        # FIRC_48 and FIRC_144 are both "clock sources" that really act more
        # like gates, which source their clock frequency from the FIRC block
        # We generate these nodes under the FIRC clock node, so skip generation
        # here.
        return "\n"
    elif signal["id"] == "PLL":
        # USB PLL
        return helpers.generate_node_with_compat(peripheral_map, signal, level,
                                                 proc_name, "nxp,mcxn9xx-usb-pll",
                                                 1, "SCG0::SPLLCSR", None)
    elif signal["id"] == "PFD_FRAC_MUL":
        # Generate the PFD fractional divider node, but skip the fixed 18x
        # multiplier node
        pfd_div = signal["children"][0]
        reg_expr = pfd_div["source"].find("divide").get("expr")
        (reg, bitfield) = reg_expr.split('[')
        # Strip trailing "] " from bitfield
        bitfield = bitfield[:-1]
        return helpers.generate_node_with_compat(peripheral_map, pfd_div,
                                                 level, proc_name,
                                                 "nxp,mcxn9xx-pfd-frac", 1,
                                                 reg, bitfield)
    elif signal["id"] == "FIRC":
        # FIRC (fast internal reference clock). This is best described like so:
        # - 144MHz clock source
        #   - 144 MHz clock gate
        #   - Fixed divide by 3
        #     - 48 MHz clock gate
        # - FIRC node, which multiplexes between 144MHz and 48MHz clock source
        (reg_addr, width, offset) = helpers.get_addr_and_bitfield(peripheral_map,
                                                        "SCG0::FIRCCSR",
                                                        "FIRCEN")
        # Write 144MHz clock source
        dts = "\n"
        dts += helpers.indent_string("firc_source: ", level)
        dts += f"firc-source@{reg_addr:x} {{\n"
        dts += helpers.indent_string(f"compatible = \"clock-source\";\n", level + 1)
        dts += helpers.indent_string(f"gate-offset = <0x{offset:x}>;\n", level + 1)
        dts += helpers.indent_string(f"#clock-cells = <1>;\n", level + 1)
        # Write register name as comment
        dts += helpers.indent_string(f"/* SCG0::[FIRCCSR] */\n", level + 1)
        dts += helpers.indent_string(f"reg = <0x{reg_addr:x} 0x{width:x}>;\n", level + 1)
        dts += helpers.indent_string(f"frequency = <144000000>;\n", level + 1)
        # Write 144MHz clock gate
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

        # Now write the FIRC node, which itself is a mux between the
        # firc_source and firc_div3 nodes
        (reg_addr, width, _) = helpers.get_addr_and_bitfield(peripheral_map,
                                                        "SCG0::FIRCCSR",
                                                        None)
        dts += "\n"
        dts += helpers.indent_string(f"{signal['id'].lower()}: ", level)
        dts += f"{signal['id'].lower().replace('_','-')}@{reg_addr:x} {{\n"
        dts += helpers.indent_string(f"compatible = \"nxp,mcxn9xx-firc\";\n", level + 1)
        dts += helpers.indent_string("/* SCG0::FIRCCSR */\n", level + 1)
        dts += helpers.indent_string(f"reg = <0x{reg_addr:x} 0x{width:x}>;\n", level + 1)
        dts += helpers.indent_string(f"input-sources = <&firc_source &firc_div3>\n", level + 1)
        dts += helpers.indent_string("};\n", level)
        return dts
    elif signal["id"] == "PLL0":
        # APLL
        return helpers.generate_node_with_compat(peripheral_map, signal, level,
                                                 proc_name, "nxp,mcxn9xx-pll",
                                                 6, "SCG0::APLLCSR", None)
    elif signal["id"] == "PLL1":
        # SPLL
        return helpers.generate_node_with_compat(peripheral_map, signal, level,
                                                 proc_name, "nxp,mcxn9xx-pll",
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
                                                 proc_name, "nxp,mcxn9xx-pll-pdec",
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
