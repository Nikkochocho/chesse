cmake_minimum_required (VERSION 3.24)
project (cheese_tests)

include(FetchContent)
include(ExternalProject)

#
# Setup CLang to C++17 (minimum for gtest)
#
set(CMAKE_CXX_STANDARD 17)

#
# Add all chesse app include directories
#
include_directories("../src")
include_directories("test//src")

set(CHESSE_TESTS_SOURCES
   ${PROJECT_SOURCE_DIR}/src/main.cpp 
   ${PROJECT_SOURCE_DIR}/src/pawn_tests.cc
   )

# Add all chesse source files
file(GLOB_RECURSE CHESSE_APP_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/../src/*.cpp)
list(REMOVE_ITEM CHESSE_APP_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/../src/chess.cpp)


##################################
# Download and install GoogleTest

ExternalProject_Add(gtest
  URL https://github.com/google/googletest/archive/refs/tags/v1.16.0.zip
  # Comment above line, and uncomment line below to use subversion.
  # SVN_REPOSITORY http://googletest.googlecode.com/svn/trunk/ 
  # Uncomment line below to freeze a revision (here the one for 1.7.0)
  # SVN_REVISION -r700

  PREFIX ${CMAKE_CURRENT_BINARY_DIR}/gtest
  INSTALL_COMMAND ""
)
ExternalProject_Get_Property(gtest SOURCE_DIR BINARY_DIR)

################
# Define a test
add_executable(cheese_tests
               ${CHESSE_APP_SOURCES}
               ${CHESSE_TESTS_SOURCES})

######################################
# Configure the test to use GoogleTest
#
# If used often, could be made a macro.

add_dependencies(cheese_tests gtest)

#
# GTest include and generated link libraries paths
# (respect the link order because GTest is problematic with link order) 
#
include_directories(${SOURCE_DIR}/googletest/include)
include_directories(${SOURCE_DIR}/googlemock/include)
target_link_libraries(cheese_tests ${BINARY_DIR}/lib/libgtest.a)
target_link_libraries(cheese_tests ${BINARY_DIR}/lib/libgtest_main.a)

##################################
# Just make the test runnable with
#   $ make test

enable_testing()
add_test(NAME    cheese_tests 
         COMMAND cheese_tests)
