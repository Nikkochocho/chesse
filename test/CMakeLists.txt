#
# chesse
# Copyright (C) 2025  Lara H. Ferreira.
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
# 
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.
#/

cmake_minimum_required (VERSION 3.24)
project (chesse_tests)

include(FetchContent)
include(ExternalProject)
include(CTest)
include(GoogleTest)

option(ENABLE_GTEST_LCOV_COVERAGE_REPORT "Enable google test lcov coverage report" OFF)

#
# Setup CLang to C++17 (minimum for gtest)
#
set(CMAKE_CXX_STANDARD 17)

#
# Setup code coverage
#
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --coverage")
set(CMAKE_EXE_LINKER_FLAGS "--coverage")


#
# Add all chesse app include directories
#
include_directories("../src")
include_directories("test/src")

set(CHESSE_TESTS_SOURCES
   ${PROJECT_SOURCE_DIR}/src/main.cpp 
   ${PROJECT_SOURCE_DIR}/src/pawn_tests.cc
   ${PROJECT_SOURCE_DIR}/src/rook_tests.cc
   ${PROJECT_SOURCE_DIR}/src/knight_tests.cc
   ${PROJECT_SOURCE_DIR}/src/bishop_tests.cc
   ${PROJECT_SOURCE_DIR}/src/queen_tests.cc
   ${PROJECT_SOURCE_DIR}/src/king_tests.cc
   ${PROJECT_SOURCE_DIR}/src/gameplay_tests.cc
   ${PROJECT_SOURCE_DIR}/src/test_helper.cpp
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
add_executable(chesse_tests
               ${CHESSE_APP_SOURCES}
               ${CHESSE_TESTS_SOURCES})


#
# Google test coverage support with lcov.
#
if (ENABLE_GTEST_LCOV_COVERAGE_REPORT)
  #
  # Run unit tests for coverage purposes (and coverage dependencies)
  #
  set(UNIT_TESTS_BINARY "${CMAKE_BINARY_DIR}/test/chesse_tests")

  add_custom_command(
      POST_BUILD
      TARGET chesse_tests
      COMMENT "Run tests ${UNIT_TESTS_BINARY}"
      POST_BUILD 
      WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
      COMMAND echo "=================== RUNNING TESTS ===================="
      COMMAND ${UNIT_TESTS_BINARY}
  )

  #
  # Create coverage report.
  #
  add_custom_command(POST_BUILD TARGET chesse_tests
      COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_BINARY_DIR}/lcoverage
      COMMAND echo "=================== LCOV COVERAGE ===================="
      COMMAND echo "-- Passing lcov tool under code coverage"
      COMMAND lcov --capture --ignore-errors inconsistent,format,unused,empty,mismatch  --directory "'${CMAKE_BINARY_DIR}/../'" --output-file ${CMAKE_BINARY_DIR}/lcoverage/main_coverage.info
      COMMAND lcov --remove ${CMAKE_BINARY_DIR}/lcoverage/main_coverage.info "build*" "test/gtest*" "usr*" --ignore-errors inconsistent,format,unused,empty,mismatch -o ${CMAKE_BINARY_DIR}/lcoverage/main_coverage_filtered.info
      COMMAND echo "-- Generating HTML output files"
      COMMAND genhtml ${CMAKE_BINARY_DIR}/lcoverage/main_coverage_filtered.info --ignore-errors inconsistent,category,unused --output-directory ${CMAKE_BINARY_DIR}/lcoverage
  )

  #
  # Show coverage data with default browser depending on platform
  #
  if (WIN32)
    set(BROWSER_EXEC_CMD "start")
  elseif (APPLE)
    set(BROWSER_EXEC_CMD "open")
  elseif (UNIX)
    set(BROWSER_EXEC_CMD "xdg-open")
  else()
    message(WARNING "Unsupported operating system. Cannot determine browser command.")
    return()
  endif()

  add_custom_command(POST_BUILD TARGET chesse_tests
      COMMAND ${CMAKE_COMMAND} -E echo "Opening documentation..."
      COMMAND ${BROWSER_EXEC_CMD} "${CMAKE_BINARY_DIR}/lcoverage/index.html"
      COMMENT "Open project documentation in browser"
  )
endif(ENABLE_GTEST_LCOV_COVERAGE_REPORT)

######################################
# Configure the test to use GoogleTest
#
# If used often, could be made a macro.

add_dependencies(chesse_tests gtest)

#
# GTest include and generated link libraries paths
# (respect the link order because GTest is problematic with link order) 
#
include_directories(${SOURCE_DIR}/googletest/include)
include_directories(${SOURCE_DIR}/googlemock/include)
target_link_libraries(chesse_tests ${BINARY_DIR}/lib/libgtest.a)
target_link_libraries(chesse_tests ${BINARY_DIR}/lib/libgtest_main.a)

##################################
# Just make the test runnable with
#   $ make test

#enable_testing()

gtest_discover_tests(chesse_tests)

add_test(NAME    chesse_tests 
         COMMAND chesse_tests)
