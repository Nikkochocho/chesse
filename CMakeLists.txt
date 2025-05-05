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

file(GLOB_RECURSE CHESSE_APP_SOURCES ./src/*.cpp)
file(GLOB CHESSE_APP_HEADERS ./src/*.h)

file(GLOB_RECURSE REMOVE_CMAKE_FILES CMakeFiles/*)
file(GLOB_RECURSE REMOVE_BUILD_FILES build/*)

add_executable(chess ${CHESSE_APP_SOURCES} ${CHESSE_APP_HEADERS})

#==================================================
# Unit Tests
#==================================================

add_subdirectory(test)

enable_testing ()
add_test (NAME chesse_tests_step COMMAND chesse_tests)

