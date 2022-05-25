#!/bin/bash

set -euo pipefail

mkdir -p build && cd build

# Configure
cmake -DCODE_COVERAGE=ON -DCMAKE_BUILD_TYPE=Debug ..
# Build (for Make on Unix equivalent to `make -j $(nproc)`)
cmake --build . --config Debug -- -j $(nproc)

# Test
export LLVM_PROFILE_FILE=$HOME/profiles/%p.profdata
ctest -j $(nproc) --output-on-failure

cd ..
