cmake_minimum_required(VERSION 3.0.2)

project(vldp_common)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_compile_options(
    -Wall
    -Wextra
    -O2
)

find_package(catkin REQUIRED COMPONENTS
    roscpp
)

catkin_package(
    INCLUDE_DIRS include
    LIBRARIES vldp_common
)

include_directories(
    include
    ${catkin_INCLUDE_DIRS}
)

add_library(vldp_common

    src/config.cpp
    src/file_utils.cpp
    src/logger.cpp
    src/time.cpp
    src/timer.cpp
)

target_link_libraries(
    vldp_common
    ${catkin_LIBRARIES}
)

add_executable(test_common
    test/test_common.cpp
)

target_link_libraries(
    test_common
    vldp_common
    ${catkin_LIBRARIES}
)