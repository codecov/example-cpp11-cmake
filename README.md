# Example Travis CI CMake g++ cpp11 lcov
[![Travis CI logo][travis-image]][travis-link]
[![Codecov logo][codecov-image]][codecov-link]

[![Build Status][travis-badge]][travis-link]
[![codecov][codecov-badge]][codecov-link]
[![MIT License][license-badge]](LICENSE.md)

Repository that serves as example how to build project with Travis CI, Cmake, lcov and CodeCov.


### Table of Contents

* **[Built With](#built-with)**
* **[Prerequisites](#prerequisites)**
* **[Authors](#authors)**
* **[License](#license)**

## Built With

The goal of this project is to build project with following tools:
 * C++ version: `C++11`
 * Build system: [`CMake`](https://cmake.org/)
 * C++ compiler: `g++`
 * Libraries: `STL` only
 * Code coverage: [`lcov`](http://ltp.sourceforge.net/coverage/lcov.php) (note: it should show the code coverage is below 100%)
 * [`CodeCov`](https://codecov.io/) (code coverage is measured by CodeCov).
 * Source: multiple files


## Prerequisites

To build the project you need to install `CMake`. [Here](https://cmake.org/install/) are the instructions. To create code coverage report you need to install `lcov`. [`Download lcov`](http://ltp.sourceforge.net/coverage/lcov.php) from here you can download latest `lcov` and here are [`instructions`](http://ltp.sourceforge.net/coverage/lcov/readme.php). This reports will be later uploaded to CodeCov servers.

## Authors

* **RokKos** - [RokKos](https://github.com/RokKos)
* **Rolf Eike Beer** - [DerDakon](https://github.com/DerDakon)

## License

This project is licensed under the MIT License - see the [LICENSE](https://github.com/RokKos/classes-c-/blob/master/LICENSE) file for details.


[travis-badge]:    https://travis-ci.org/codecov/example-cpp11-cmake.svg?branch=master
[travis-link]:     https://travis-ci.org/codecov/example-cpp11-cmake
[travis-image]:    https://github.com/codecov/example-cpp1-cmake/blob/master/img/TravisCI.png
[license-badge]:   https://img.shields.io/badge/license-MIT-007EC7.svg
[codecov-badge]:   https://codecov.io/gh/codecov/example-cpp11-cmake/branch/master/graph/badge.svg
[codecov-link]:    https://codecov.io/gh/codecov/example-cpp11-cmake
[codecov-image]:   https://github.com/codecov/example-cpp1-cmake/blob/master/img/Codecov.png
