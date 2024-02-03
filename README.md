![](https://github.com/dolphin2003/arabic-nlp-toolkit/actions/workflows/c-cpp.yml/badge.svg)
![](https://github.com/dolphin2003/arabic-nlp-toolkit/actions/workflows/wheels.yml/badge.svg)
[![](https://badge.fury.io/py/arabic-nlp-toolkit.svg)](https://badge.fury.io/py/arabic-nlp-toolkit)
[![](https://img.shields.io/badge/License-Boost_1.0-lightblue.svg)](https://www.boost.org/LICENSE_1_0.txt)
[![Downloads](https://static.pepy.tech/personalized-badge/arabic-nlp-toolkit?period=total&units=international_system&left_color=blue&right_color=orange&left_text=Downloads)](https://pepy.tech/project/arabic-nlp-toolkit)

# Arabic Natural Language Toolkit

Arabic Natural Language Toolkit is a set of Arabic natural language processing tools developed with a focus on simplicity and performance. It's a C++ library, with python bindings.

## Installation
For python:
```
pip install arabic-nlp-toolkit
```
## Building
Note: Currently only tested on Linux, prebuilt python wheels are available for Linux, Windows, Macos on [pypi](https://pypi.org/project/arabic-nlp-toolkit/)

## Usage Examples:

For C++ API and Python API code examples, please refer to the original repository. Illustrations include transliteration, tashkeel removal, etc. and cover both the C++ API and Python API.

**For a list of features, see [Features.md](Features.md)**

## Benchmarks

Performace benchmarks are provided for a file containing 500000 lines, 6787731 words, 112704541 characters. The tasks include removing diacritics and transliterating to Buckwalter.