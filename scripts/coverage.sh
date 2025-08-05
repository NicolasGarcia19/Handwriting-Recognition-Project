#!/bin/bash

# Check current path 
ROOT=$(basename $(pwd))
if [ $ROOT != "pa5-sys" ]; then
    echo "Please run this script from the pa5-sys directory: ./scripts/coverage.sh"
    exit 1
fi

# Set up build-coverage directory
echo "Cleaning up previous build-coverage directory..."
rm -rf build-coverage
echo "Creating build-coverage directory..."
mkdir -p build-coverage
cd build-coverage

# Compile with coverage flags
CXXFLAGS="-fprofile-arcs -ftest-coverage" cmake -DCMAKE_BUILD_TYPE=Debug -DCMAKE_CXX_COMPILER=g++ ..
make

# Run tests and gcov
ctest
gcov src/CMakeFiles/pa5-sys-lib.dir/HRSBinarySearch.cc.gcda \
    src/CMakeFiles/pa5-sys-lib.dir/HRSLinearSearch.cc.gcda \
    src/CMakeFiles/pa5-sys-lib.dir/Image.cc.gcda \
    src/CMakeFiles/pa5-sys-lib.dir/VectorImage.cc.gcda \
    src/CMakeFiles/pa5-sys-lib.dir/VectorInt.cc.gcda \
    src/CMakeFiles/pa5-sys-lib.dir/sort-image.cc.gcda \
    src/CMakeFiles/pa5-sys-lib.dir/sort-int.cc.gcda
