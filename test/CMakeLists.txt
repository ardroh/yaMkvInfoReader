include(FetchContent)
FetchContent_Declare(gtest
        QUIET
        URL https://github.com/google/googletest/archive/release-1.10.0.tar.gz
        )
# configure build of googletest
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
set(BUILD_GMOCK OFF CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(gtest)

file(GLOB_RECURSE TEST_SOURCES LIST_DIRECTORIES false *.h *.cpp)
set(SOURCES ${TEST_SOURCES})

set(BINARY ${CMAKE_PROJECT_NAME})

add_executable(
        ${BINARY}_tests
        ${TEST_SOURCES})

target_link_libraries(${BINARY}_tests
        PRIVATE
        yaMkvInfoReader_lib
        gtest_main
        )

# automatic discovery of unit tests
include(GoogleTest)
gtest_discover_tests(${BINARY}_tests
        PROPERTIES
        LABELS "unit"
        DISCOVERY_TIMEOUT  # how long to wait (in seconds) before crashing
        240
        )