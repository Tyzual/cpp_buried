#!/bin/bash

cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug &&
cmake --build build &&
./build/arrow
