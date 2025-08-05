#!/bin/bash

# Check current path 
ROOT=$(basename $(pwd))
if [ $ROOT != "pa5-sys" ]; then
    echo "Please run this script from the pa5-sys directory: ./scripts/memcheck.sh"
    exit 1
fi

# refresh the build
./scripts/build.sh

EXECUTABLE_DIR="build/test"
TEST_FILES=( 
  "hrs-binary-search-directed-test"
  "hrs-linear-search-directed-test"
  "image-directed-test"
  "image-random-test"
  "sort-image-directed-test"
  "sort-image-random-test"
  "sort-int-directed-test"
  "sort-int-random-test"
  "vector-image-directed-test"
  "vector-image-random-test"
  "vector-int-directed-test"
  "vector-int-random-test"
)

for test in "${TEST_FILES[@]}"; do
  echo "Running valgrind on $test BEGIN"
  echo "===================================================="
  ./scripts/valgrind.sh "$EXECUTABLE_DIR/$test"
  echo "===================================================="
done
