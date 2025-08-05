#!/bin/bash

ROOT=$(basename $(pwd))
if [ $ROOT != "pa5-sys" ]; then
    echo "Please run this script from the pa5-sys directory: ./scripts/build.sh"
    exit 1
fi

mkdir -p build
cd build
cmake ..
make
echo "Build Successful"
