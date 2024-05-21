"""
Common handler function, which handles clock nodes specific to an SOC.
This handler function is a common entry point for the generic soc clock code,
which calls on SOC specific handler functions
"""

from soc import lpc55s6x, mcxn9x
import logging

def handle_soc_signals(peripheral_map, signal, level, proc_name):
    """
    Handles "special case" signals, which need generation different than
    what can be handled in the standard signal output function
    @param peripheral_map: peripheral map used to resolve reset values
    @param signal: signal to parse and output devicetree for
    @param level: indentation level of output devicetree
    @param proc_name: Processor name
    Returns string describing devicetree for this node, or empty string
    if the signal is not handled
    """
    if "LPC55S6" in proc_name:
        return lpc55s6x.handle_soc_signals(peripheral_map, signal, level, proc_name)
    elif "MCXN9" in proc_name:
        return mcxn9x.handle_soc_signals(peripheral_map, signal, level, proc_name)
    else:
        logging.warning("Support for %s not implemented", proc_name)
        return ""
