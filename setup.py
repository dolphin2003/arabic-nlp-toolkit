
import os
import setuptools
import platform
import pybind11
from pybind11.setup_helpers import Pybind11Extension, build_ext

# Figure out environment for cross-compile
anltk_source = os.getenv("ANLTK_SOURCE",
                         os.path.abspath(os.path.dirname(__file__)))            
system = os.environ.get('ANLTK_PLATFORM', platform.system())

with open("README.md", "r", encoding='utf-8') as fh:
    long_description = fh.read()


def _get_project_version():
    version_path = os.path.join(anltk_source, "python", "anltk_module",
                                "anltk", "version.py")
    version = {}
    with open(version_path, encoding="utf-8") as fp:
        exec(fp.read(), version)
    return version["__version__"]


include_dirs = [
    pybind11.get_include(),
    os.path.join(anltk_source, 'anltk', 'include'),
    os.path.join(anltk_source, 'subprojects', 'utfcpp', 'source')