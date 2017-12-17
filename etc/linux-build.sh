#!/bin/bash

mkdir -p build/debug
cmake -DCMAKE_BUILD_TYPE=Debug -H. -Bbuild/debug
cmake --build build/debug -- clean all
