#!/bin/bash

mkdir -p build/release
cmake -DCMAKE_BUILD_TYPE=Release -H. -Bbuild/release
cmake --build build/release -- clean all
