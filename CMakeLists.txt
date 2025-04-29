cmake_minimum_required (VERSION 3.24)

project (chess)

include(CMakePackageConfigHelpers)
include(CMakeDependentOption)
include(GNUInstallDirs)

if(APPLE)
    #
    # Setup CLang to C++17 (minimum for working with some raylib defines when using APPLE)
    #
    set(CMAKE_CXX_STANDARD 17)
endif()

include_directories("./src/")

file(GLOB_RECURSE TEST_APP_SOURCES ./src/*.cpp)
file(GLOB TEST_APP_HEADERS ./src/*.h)

file(GLOB_RECURSE REMOVE_CMAKE_FILES CMakeFiles/*)
file(GLOB_RECURSE REMOVE_BUILD_FILES build/*)

add_executable(chess ${TEST_APP_SOURCES} ${TEST_APP_HEADERS})
