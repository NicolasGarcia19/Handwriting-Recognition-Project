#!/bin/bash

ROOT=$(basename $(pwd))
if [ $ROOT != "pa5-sys" ]; then
    echo "Please run this script from the pa5-sys directory: ./scripts/test.sh"
    exit 1
fi

if ./scripts/build.sh ; then
    echo "Build successful"
else
    echo "Fix build errors above"
    exit 1
fi

cd build

# Running /tests
echo "Running tests..."
if make test; then
    echo "Tests successful"
else
    echo "Tests failed"
fi
