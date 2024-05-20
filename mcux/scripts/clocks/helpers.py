"""
Common helper functions for SOC clock generation
"""

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
