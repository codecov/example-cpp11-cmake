# [Codecov][1] CI CMake g++ cpp11 lcov Example
[![Travis CI logo][travis-image]][travis-link]
[![Codecov logo][codecov-image]][codecov-link]

[![Build Status][travis-badge]][travis-link]
[![codecov][codecov-badge]][codecov-link]
[![MIT License][license-badge]](LICENSE.md)

The goal of this project is to build project with following tools:
 * C++ version: `C++11`
 * Build system: [`CMake`](https://cmake.org/)
 * C++ compiler: `g++`
 * Libraries: `STL` only
 * Code coverage report: [`lcov`](http://ltp.sourceforge.net/coverage/lcov.php) (note: it should show the code coverage is below 100%)
 * [`CodeCov`](https://codecov.io/) (code coverage is measured by CodeCov).
 * Source: multiple files

## Special Thanks
Goes to [Richel Bilderbeek](https://github.com/richelbilderbeek) for inspiration and all work on [Travis CI tutorials](https://github.com/richelbilderbeek/travis_cpp_tutorial).
Here is a [link](https://github.com/richelbilderbeek/travis_cmake_gcc_cpp11) to a project with the same structure (without `lcov`),
and here is a [list](https://github.com/richelbilderbeek/travis_cpp_tutorial/blob/master/statuses.md) of all his Travis configuration examples.

## Prerequisites
To build the project you need to install `CMake`. ([Install instructions](https://cmake.org/install/))
To display a code coverage report in the console, install `lcov`. ([`Download lcov`](http://ltp.sourceforge.net/coverage/lcov.php), [`Instructions`](http://ltp.sourceforge.net/coverage/lcov/readme.php))

## Guide
1. Compile with code coverage instrumentation enabled [(GCC)](https://gcc.gnu.org/onlinedocs/gcc/Instrumentation-Options.html).
2. Execute the tests to generate the coverage data.
3. (Optionally) generate and customize reports with `lcov`.
4. Upload to CodeCov using the bash uploader.

### Travis Setup Using lcov
Add to your `.travis.yml` file:
```yml
addons:
  apt:
    packages: lcov

after_success:
# Create lcov report
- lcov --capture --directory . --output-file coverage.info
- lcov --remove coverage.info '/usr/*' --output-file coverage.info # filter system-files
- lcov --list coverage.info # debug info
# Uploading report to CodeCov
- bash <(curl -s https://codecov.io/bash) -f coverage.info || echo "Codecov did not collect coverage reports"
```

### Travis Setup without lcov
By default the bash uploader processes the coverage data using gcov when no file is supplied.
```yml
after_success:
- bash <(curl -s https://codecov.io/bash) || echo "Codecov did not collect coverage reports"
```

## Caveats
### Private Repos
Add to your `.travis.yml` file:
```yml
after_success:
  - bash <(curl -s https://codecov.io/bash) -t uuid-repo-token
```

## Example details
This repo can serve as the starting point for a new project. The following is worth noticing:
1. Use of a build script instead of putting the commands into `.travis.yml`
  - Allows local testing
  - Allows usage of `set -e` to error out with meaningfull messages on any command failure
2. Separate testing source tree
  - Allows to easily enable/disable testing
  - Allows usage in parent projects (you don't want to build the tests if you are consumed)
  - You may want to exclude coverage of test files which is easier when they are in a separate folder.
    Remember to use **full paths** for patterns (like `'*/tests/*'`)
3. Use of travis cache to cache manually build 3rd-party dependencies (like boost)
  - Speeds up build
  - More can be added (e.g. `ccache`)
  - Those need to be excluded from coverage info too

## Authors
* **RokKos** - [RokKos](https://github.com/RokKos)
* **Rolf Eike Beer** - [DerDakon](https://github.com/DerDakon)
* **Alexander Grund** - [Flamefire](https://github.com/Flamefire)

## License
This project is licensed under the MIT License - see the [LICENSE](https://github.com/RokKos/classes-c-/blob/master/LICENSE) file for details.

1. More documentation at https://docs.codecov.io
2. Configure codecov through the `codecov.yml` https://docs.codecov.io/docs/codecov-yaml

We are happy to help if you have any questions. Please email our Support at [support@codecov.io](mailto:support@codecov.io)

[1]: https://codecov.io/
[travis-badge]:    https://travis-ci.org/codecov/example-cpp11-cmake.svg?branch=master
[travis-link]:     https://travis-ci.org/codecov/example-cpp11-cmake
[travis-image]:    https://github.com/codecov/example-cpp1-cmake/blob/master/img/TravisCI.png
[license-badge]:   https://img.shields.io/badge/license-MIT-007EC7.svg
[codecov-badge]:   https://codecov.io/gh/codecov/example-cpp11-cmake/branch/master/graph/badge.svg
[codecov-link]:    https://codecov.io/gh/codecov/example-cpp11-cmake
[codecov-image]:   https://github.com/codecov/example-cpp1-cmake/blob/master/img/Codecov.png
