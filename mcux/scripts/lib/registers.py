"""
Utilites for managing registers
definitions within MCUXpresso Datapacks
"""

import pathlib
import xml.etree.ElementTree as ET
import logging
import re

class Peripheral:
    """
    Internal class used to represent a peripheral
    """
    def __init__(self, peripheral_xml, register_xml = None):
        """
        Initializes peripheral object using peripheral XML structure
        @param peripheral_xml: peripheral XML object - parsed from registers.xml
        @param register: path to XML file with register description for this peripheral
        """
        self._name = peripheral_xml.attrib['name']
        self._fullname = peripheral_xml.attrib['full_name']
        # Peripheral address space in bytes
        self._size = int(peripheral_xml.attrib['size'])
        self._base_addr = int(peripheral_xml.find('base_address').attrib['addr'], 0)
        # Do not load registers now, just record the filename. This
        # Lazy loading speeds up the script, since we only need registers from
        # some peripherals
        if register_xml is not None:
            self._registers = {}
            self._register_file = register_xml
        else:
            self._registers = None
            self._register_file = None

    def _load_registers(self):
        """
        Loads registers from register XML file
        """
        if (self._register_file is not None) and (self._registers == {}):
            # Parse registers
            try:
                if not pathlib.Path(self._register_file).exists():
                    raise RuntimeError(f"Register file {self._register_file} does not exist")
                register_xml = ET.parse(self._register_file)
                for register_def in register_xml.findall('register'):
                    reg = Register(register_def)
                    self._registers[reg.get_name()] = reg
                # Parse register template definitions to locate remaining
                # Register definitions
                reg_templates = {}
                for template in register_xml.findall('reg_template'):
                    reg_templates[template.get('rid')] = template
                for reg_instance in register_xml.findall('reg_instance'):
                    reg = TemplatedRegister(reg_templates[reg_instance.get('rid')], reg_instance)
                    self._registers[reg.get_name()] = reg

            except ET.ParseError:
                raise RuntimeError(f"Register file {self._register_file} is not valid XML")
        elif self._register_file is None:
            raise RuntimeError("Cannot load registers, no xml file path provided")

    def __repr__(self):
        """
        Generate string representation of the object
        """
        if self._registers:
            return ("Peripheral(%s, 0x%X, %d Regs)" %
                    (self._name, self._base_addr, len(self._registers)))
        return ("Peripheral(%s, 0x%X)" %
                (self._name, self._base_addr))

    def get_name(self):
        """
        Gets peripheral name
        """
        return self._name

    def get_size(self):
        """
        Gets size of peripheral address region in bytes
        """
        return self._size

    def get_base(self):
        """
        Gets base address of peripheral
        """
        return self._base_addr

    def get_register(self, reg_name):
        """
        Get register object within peripheral by name
        @param reg_name: name of register to get
        """
        self._load_registers()
        return self._registers[reg_name]

    def get_reg_addr(self, reg_name):
        """
        Gets full address of register in peripheral
        @param reg_name: name of register to calculate address for
        """
        self._load_registers()
        return self._base_addr + self._registers[reg_name].get_offset()


class Register:
    """
    Internal class used to represent a register in a peripheral
    """
    def __init__(self, register_xml):
        """
        Constructs a register object from provided register xml data
        """
        self._name = register_xml.attrib['name']
        for alias in register_xml.findall('alias'):
            if alias.attrib['type'] == 'id':
                self._name = alias.attrib['value']
        self._offset = int(register_xml.attrib['offset'], 0)
        self._build_bitfield_map(register_xml)
        self._build_bitfield_offsets(register_xml)

    def _build_bitfield_map(self, register_xml):
        """
        Helper function called during init
        Builds mapping of register field values to descriptions
        """
        self._bit_field_map = {}
        for bit_field in register_xml.findall('bit_field'):
            bit_field_map = {}
            for bit_field_value in bit_field.findall('bit_field_value'):
                # Some reserved bitfields are encoded as 0b??. Replace
                # ? with 0 so int decoding works
                bit_field_str = bit_field_value.attrib['value'].replace('?', '0')
                if not bit_field_str.isdigit():
                    # Skip this bitfield
                    continue
                field_val = int(bit_field_str, 0)
                bit_field_map[field_val] = bit_field_value.attrib

            # Save reset value
            bit_field_map['RESET'] = int(bit_field.get('reset_value'), 0)
            # Save bit field mapping
            self._bit_field_map[bit_field.attrib['name']] = bit_field_map

    def _build_bitfield_offsets(self, register_xml):
        """
        Helper function called during init
        Builds mapping of bitfield names to offsets and widths
        """
        # Get offsets and widths of all register bitfields
        self._bitfield_offsets = {}
        for bitfield in register_xml.findall('bit_field'):
            offset_dict = ({'offset': int(bitfield.get('offset'), 0),
                            'width': int(bitfield.get('width'), 0)})
            self._bitfield_offsets[bitfield.get('name')] = offset_dict

    def __repr__(self):
        """
        Generate string representation of the object
        """
        return "Register(%s, 0x%X)" % (self._name, self._offset)


    def get_name(self):
        """
        Get the name of the register
        """
        return self._name

    def get_offset(self):
        """
        Get the offset of this register from the base
        """
        return self._offset

    def get_bit_field_offset(self, bit_field):
        """
        Get the offset of a bitfield within the register
        """
        return self._bitfield_offsets[bit_field]['offset']

    def get_bit_field_width(self, bit_field):
        """
        Get the width of a bitfield within the register
        """
        return self._bitfield_offsets[bit_field]['width']

    def get_bit_field_value_description(self, bit_field, value):
        """
        Get human-readable description of the value a bit field in the register
        represents
        @param bit_field: name of register bit field
        @param value: value assigned to bit field
        @return description of effect that value has on register
        """
        return self._bit_field_map[bit_field][value]['description']

    def get_bit_fields(self):
        """
        Get list of all bit fields present in register
        """
        return self._bit_field_map.keys()

    def get_reset_value(self, bit_field):
        """
        Get reset value of register bitfield
        @param bit_field: name of register bit field
        @return reset value of bitfield
        """
        return self._bit_field_map[bit_field]['RESET']


class TemplatedRegister(Register):
    """
    Subclass of standard register, that implements support for templated
    register definitions in a manner compatible with the standard register
    class instance.
    """
    def __init__(self, template_xml, instance_xml):
        """
        Constructs a register instance based off the register template XML
        and register instance XML
        """
        self._values = instance_xml.get('vals').split(' ')
        self._name = self._sub_template(template_xml.attrib['name'])
        self._offset = int(self._sub_template(template_xml.attrib['offset']), 0)
        self._build_bitfield_map(template_xml)
        self._build_bitfield_offsets(template_xml)

    def _sub_template(self, string):
        """
        Uses string substitution to replace references to template parameter
        in string with value in a value array. For instance,
        SW_PAD_CTL_PAD_GPIO_EMC_{1} would become SW_PAD_CTL_PAD_GPIO_EMC_15
        if values[1] == 15
        """
        for i in range(len(self._values)):
            string = re.sub(r'\{' + re.escape(str(i)) + r'\}',
                self._values[i], string)
        return string

def load_peripheral_map(reg_dir):
    """
    Generates a mapping of peripheral names to peripheral objects
    @param reg_dir: directory where register defintion files are stored
    @return dict mapping peripheral names to base addresses
    """
    cfg_dir = pathlib.Path(reg_dir)
    register_path = cfg_dir / 'registers.xml'
    if not register_path.exists():
        raise RuntimeError("Required processor configuration files not present")
    # Load the register xml defintion
    reg_xml = ET.parse(str(register_path))
    periph_map = {}
    for peripheral in reg_xml.findall('peripherals/peripheral'):
        periph_path = reg_dir / peripheral.attrib.get('link')
        if periph_path.exists():
            try:
                # Build register map for this peripheral
                periph_map[peripheral.attrib['name']] = Peripheral(peripheral,
                    str(periph_path))
            except ET.ParseError:
                logging.error("Malformed XML tree in %s, skipping...", periph_path)
                periph_map[peripheral.attrib['name']] = Peripheral(peripheral)

    return periph_map

def find_register(periph_array, reg_name):
    """
    Finds a register within all peripheral sets. Note that this function is
    inherently slow, as it will load register maps for all
    peripherals provided in the search list
    @param periph_array array of peripheral objects to search
    @param reg_name: name of register to find
    @return peripheral object containing the register, or None if not found
    """
    for periph in periph_array:
        periph._load_registers()
        if reg_name in periph._registers:
            return periph
    return None
