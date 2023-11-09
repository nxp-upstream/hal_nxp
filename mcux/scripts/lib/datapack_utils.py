"""
Common utilities for managing NXP MCUX SDK data packages
"""

import pathlib
import tempfile
import re
import zipfile

def extract_pack(pack_file):
    """
    Extracts the data pack.
    @param pack_file file containing data pack
    @retval TemporaryDirectory object, with pack contents
    """
    # Extract the Data pack to a temporary directory
    temp_dir = tempfile.TemporaryDirectory()
    zipfile.ZipFile(pack_file).extractall(temp_dir.name)
    return temp_dir

def get_pack_version(pack_dir):
    """
    Gets datapack version
    @param pack_dir: root directory data pack is in
    """
    # Check version of the config tools archive
    npi_data = pathlib.Path(pack_dir) / 'npidata.mf'
    data_version = 0.0
    with open(npi_data, 'r', encoding='UTF8') as stream:
        line = stream.readline()
        while line != '':
            match = re.search(r'data_version=([\d\.]+)', line)
            if match:
                data_version = float(match.group(1))
                break
            line = stream.readline()
    return data_version


def get_processor_name(pack_dir):
    """
    Gets processor name for datapack
    @param pack_dir: root directory data pack is in
    """
    # Check version of the config tools archive
    npi_data = pathlib.Path(pack_dir) / 'npidata.mf'
    proc = "UNKNOWN_PROCESSOR"
    with open(npi_data, 'r', encoding='UTF8') as stream:
        line = stream.readline()
        while line != '':
            match = re.search(r'processors=(\w+)', line)
            if match:
                proc = str(match.group(1))
                break
            line = stream.readline()
    return proc
