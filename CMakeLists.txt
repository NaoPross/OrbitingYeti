cmake_minimum_required(VERSION 3.7)

#######################################################################
# B-Circuit
project(OrbitingYeti)

## Version
set(OrbitingYeti_VERSION_MAJOR 0)
set(OrbitingYeti_VERSION_MINOR 1)

## Libraries

# qt5

# Tell CMake to run moc when necessary:
set(CMAKE_AUTOMOC ON)
# As moc files are generated in the binary dir, tell CMake
# to always look for includes there:
set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt5Core REQUIRED)
find_package(Qt5Widgets REQUIRED)

add_definitions(${Qt5Core_DEFINITIONS})
add_definitions(${Qt5Widgets_DEFINITIONS})

include_directories(${Qt5core_INCLUDES})
include_directories(${Qt5Widgets_INCLUDES})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${Qt5Core_EXECUTABLE_COMPILE_FLAGS}")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${Qt5Widgets_EXECUTABLE_COMPILE_FLAGS}")

## Compiler 
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Wall -Werror")

## Source code
include_directories(${CMAKE_SOURCE_DIR}/inc)
file(GLOB_RECURSE SOURCES ${CMAKE_SOURCE_DIR} "src/*.cpp")

## Executable
add_executable(OrbitingYeti ${SOURCES})
target_link_libraries(OrbitingYeti Qt5::Core Qt5::Widgets)

## Toolchain
# enable useful output for linters
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
