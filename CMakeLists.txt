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

project (chess)

include(CMakePackageConfigHelpers)
include(CMakeDependentOption)
include(GNUInstallDirs)
include(CTest)

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

add_subdirectory("./test")

# enable_testing ()
# add_test (NAME test COMMAND chesse_tests)

