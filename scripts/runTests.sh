#!/bin/bash
cmake -B./debug/ -S. -DCMAKE_BUILD_TYPE=Debug
cd ./debug
cmake --build . --target yaMkvInfoReader_tests
./test/yaMkvInfoReader_tests
