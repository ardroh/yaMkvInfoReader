#!/bin/bash
cmake -B./debug/ -S. -DCMAKE_BUILD_TYPE=Debug
cd ./debug
cmake --build . --target yaMkvInfoReader_run
