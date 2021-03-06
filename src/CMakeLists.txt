cmake_minimum_required(VERSION 3.16)

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
find_package(Boost 1.71.0 COMPONENTS log)
set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)

set(BINARY ${CMAKE_PROJECT_NAME})

file(GLOB_RECURSE SOURCES LIST_DIRECTORIES true *.h *.cpp logging/*.h logging/*.cpp options/* mkvs/*.h mkvs/*.cpp)
set(SOURCES ${SOURCES})

add_executable(${BINARY}_run ${SOURCES})
add_library(${BINARY}_lib STATIC ${SOURCES})

target_include_directories(${BINARY}_run PUBLIC ${Boost_INCLUDE_DIRS} PkgConfig::LIBAV)

target_link_libraries(${BINARY}_run
        PkgConfig::LIBAV
        ${Boost_LIBRARIES}
        )
