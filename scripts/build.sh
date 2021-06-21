buildConfig=$1

if [ "$buildConfig" != "release" ] && [ "$buildConfig" != "debug" ]
 then
    echo "Unknown build configuration: $buildConfig"
    exit 1
fi

cmake -B./$buildConfig/ -S. -DCMAKE_BUILD_TYPE=$buildConfig
cd ./$buildConfig
cmake --build . --target yaMkvInfoReader_run