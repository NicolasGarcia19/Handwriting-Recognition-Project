#!/bin/bash

ROOT=$(basename $(pwd))
if [ $ROOT != "pa5-sys" ]; then
    echo "Please run this script from the pa5-sys directory"
    exit 1
fi

if ./scripts/build.sh -DCMAKE_BUILD_TYPE=Release ; then
    echo "Build successful"
else
    echo "Fix build errors above"
    exit 1
fi

cd build

NAMES=("hrs-binary-search-eval" "hrs-linear-search-eval")
PATTERNS=("urandom" "sorted-asc" "sorted-desc")

# Running /tests
echo "Running tests..."
if make test; then
    echo "Tests passed"
    echo "Recording execution time..."

    echo "hrs-linear-search-eval 6000 100" > results.txt
    echo "======================" >> results.txt
    ./eval/hrs-linear-search-eval 6000 100 >> results.txt
    echo "hrs-binary-search-eval 6000 100 15" >> results.txt
    echo "======================" >> results.txt
    ./eval/hrs-binary-search-eval 6000 100 15 >> results.txt
    cat results.txt
else
    echo "Tests failed"
    echo "SKIPPED: evaluation"
fi
