#!/bin/bash

valgrind --trace-children=yes --leak-check=full --error-exitcode=1 --undef-value-errors=no $1
