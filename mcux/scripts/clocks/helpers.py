"""
Common helper functions for SOC clock generation
"""
import gen_soc_clocks
import os
import sys

SHARED_DIR = os.path.join(os.path.dirname(os.path.abspath(__file__)), os.pardir)
sys.path.append(SHARED_DIR)

from lib import registers


def indent_string(string, indent):
    """
    Basic helper to generate a string indented by a given number of tabs
    @param string string to output
    @param indent number of tabs to indent string by
    """
    indent_str = ""
    for _ in range(indent):
        indent_str += "\t"
    return indent_str + string

def get_addr_and_bitfield(peripheral_map, reg_expr, bitfield):
    """
    Helper function to get the register address, bitfield width, and bitfield
    offset for register expression
    @param peripheral_map: map of peripheral names to peripheral objects
    @param reg_expr: expression describing register, formatted as PERIPHERAL::REGISTER
    @param bitfield: name of bitfield in register to access. If set to None,
    bitfield width will be 0x20, and offset will be 0x0
    @return tuple of (register address, bitfield width, bitfield offset)
    """
    if "::" not in reg_expr:
        # Try to find the register by name. This is slow, but the best
        # option we have
        periph = registers.find_register(peripheral_map.values(), reg_expr)
        reg = reg_expr
    else:
        # Read the bitfield and register expression (peripheral + reg)
        (periph_name, reg) = reg_expr.split("::")
        periph = peripheral_map[periph_name]

    reg_addr = periph.get_reg_addr(reg)
    if bitfield is not None:
        # Get register offset and bitfield
        bitfield_offset = periph.get_register(reg).get_bit_field_offset(bitfield)
        bitfield_width = periph.get_register(reg).get_bit_field_width(bitfield)
    else:
        bitfield_offset = 0x0
        bitfield_width = 0x20
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

def generate_children(peripheral_map, signal, level, proc_name):
    """
    Generates devicetree data for children of a given clock signal
    @param peripheral_map: peripheral map used to resolve reset values
    @param signal: signal to parse and output devicetree for
    @param level: indentation level of output devicetree
    @param proc_name: Processor name, used for special case signals handling
    Returns string describing devicetree for this node, or empty string
    if the signal is not handled
    """
    dts = ""
    child_dts = ""
    for child in signal['children']:
        child_dts += gen_soc_clocks.output_signal(peripheral_map, child, level + 1, proc_name)
    if len(child_dts) > 0 and "@" in child_dts:
        # Add address-cells and size-cells settings
        dts += indent_string(f"#address-cells = <1>;\n", level + 1)
        dts += indent_string(f"#size-cells = <1>;\n", level + 1)
    dts += child_dts
    return dts

def generate_node_with_compat(peripheral_map, signal, level, proc_name,
                              compat, cell_cnt, reg, bitfield):
    """
    Generates devicetree node (and children nodes) for a given signal,
    using the provided compatible, clock cell count, register, and width
    @param peripheral_map: peripheral map used to resolve reset values
    @param signal: signal to parse and output devicetree for
    @param level: indentation level of output devicetree
    @param proc_name: Processor name, used for special case signals handling
    @param compat: compatible to use for generation
    @param cell_cnt: number of clock cells to set
    @param reg: name of register to use for register address
    @param bitfield: name of bitfield in register to access. If set to None,
    bitfield width will be 0x20.
    @return devicetree node string describing the signal, formatted like so:

    {signal['id'].lower()}: {signal['id'].lower.replace('_','-')} {
        compatible = "{compat}";
        #clock-cells = <{cell_cnt}>;
        /* {reg}[{bitfield}] */
        reg = <{reg_address} {bitfield_width}>;
    };
    """
    (reg_offset, width, _) = get_addr_and_bitfield(peripheral_map,
                                                    reg, bitfield)
    dts = "\n"
    dts += indent_string(f"{signal['id'].lower()}: ", level)
    dts += f"{signal['id'].lower().replace('_','-')}@{reg_offset:x} {{\n"
    dts += indent_string(f"compatible = \"{compat}\";\n", level + 1)
    dts += indent_string(f"#clock-cells = <{cell_cnt}>;\n", level + 1)
    # Write register offset and width
    if bitfield is not None:
        dts += indent_string(f"/* {reg}[{bitfield}] */\n", level + 1)
    else:
        dts += indent_string(f"/* {reg} */\n", level + 1)
    dts += indent_string(f"reg = <0x{reg_offset:x} 0x{width:x}>;\n", level + 1)
    # Generate children of frgdiv
    dts += generate_children(peripheral_map, signal, level, proc_name)
    dts += indent_string("};\n", level)
    return dts
