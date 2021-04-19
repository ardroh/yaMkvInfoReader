#!/bin/bash
cmake -B./release/ -S. -DCMAKE_BUILD_TYPE=Release
cd ./release
cmake --build . --target yaMkvInfoReader_run
