cmake_minimum_required(VERSION 3.0.2)

project(vldp_platform)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_compile_options(
    -Wall
    -Wextra
    -O2
)

find_package(catkin REQUIRED COMPONENTS
    roscpp
    vldp_common
    vldp_core
)

catkin_package(
    INCLUDE_DIRS include
    CATKIN_DEPENDS
        roscpp
        vldp_common
        vldp_core
)

include_directories(
    include
    ${catkin_INCLUDE_DIRS}
)

add_library(vldp_platform
    src/platform_node.cpp
)

target_link_libraries(
    vldp_platform
    ${catkin_LIBRARIES}
)

add_executable(vldp_platform_node
    src/main.cpp
)

target_link_libraries(
    vldp_platform_node
    vldp_platform
    ${catkin_LIBRARIES}
)
