cmake_minimum_required(VERSION 3.0.2)

project(vldp_controller)

## 使用 C++17
add_compile_options(-std=c++17)

find_package(catkin REQUIRED COMPONENTS
    roscpp
    std_msgs
    vldp_common
    vldp_core
    vldp_msgs
)

catkin_package(
    INCLUDE_DIRS include
)

include_directories(
    include
    ${catkin_INCLUDE_DIRS}
)

add_executable(vldp_controller_node

    src/main.cpp

    src/controller.cpp

    src/controller_node.cpp
)

target_link_libraries(vldp_controller_node

    ${catkin_LIBRARIES}
)
