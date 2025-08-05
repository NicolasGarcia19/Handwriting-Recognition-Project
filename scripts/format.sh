#!/bin/bash

ROOT=$(basename $(pwd))
if [ $ROOT != "pa5-sys" ]; then
    echo "Please run this script from the pa5-sys directory"
    exit 1
fi

clang-format --verbose -i src/*.cc include/*.h eval/*.cc test/*.cc
