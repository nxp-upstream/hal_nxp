"""
Common helper functions for SOC clock generation
"""
import gen_soc_clocks

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
    @param bitfield: name of bitfield to read from
    @return tuple of (register address, bitfield width, bitfield offset)
    """
    if "::" not in reg_expr:
        # Add the SCG to the register expression
        reg_expr = "SCG0::" + reg_expr
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
