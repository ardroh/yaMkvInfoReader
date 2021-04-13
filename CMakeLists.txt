cmake_minimum_required(VERSION 3.19)
project(yaMkvInfoReader)

set(CMAKE_CXX_STANDARD 17)

find_package(PkgConfig REQUIRED)
pkg_check_modules(LIBAV REQUIRED IMPORTED_TARGET
        libavdevice
        libavfilter
        libavformat
        libavcodec
        libswresample
        libswscale
        libavutil
        )
set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)

add_executable(${PROJECT_NAME} main.cpp options/IOptionsParser.h options/AppOptions.h options/CmdArgsOptionsParser.cpp options/CmdArgsOptionsParser.h)

target_include_directories(${PROJECT_NAME} PUBLIC ${Boost_INCLUDE_DIRS})

target_link_libraries(${PROJECT_NAME}
        PkgConfig::LIBAV
        ${Boost_LIBRARIES}
        )
