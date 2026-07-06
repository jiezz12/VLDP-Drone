cmake_minimum_required(VERSION 3.0.2)
project(vldp_core)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(catkin REQUIRED COMPONENTS
    roscpp
    std_msgs
    vldp_common
)

catkin_package(
    INCLUDE_DIRS include
    CATKIN_DEPENDS roscpp std_msgs vldp_common
)

include_directories(
    include
    ${catkin_INCLUDE_DIRS}
)

add_executable(demo_core
    src/demo_core.cpp
)


