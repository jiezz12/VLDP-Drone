cmake_minimum_required(VERSION 3.0.2)

project(vldp_localization)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(catkin REQUIRED COMPONENTS
    roscpp
    std_msgs
    geometry_msgs
    nav_msgs
    tf2
    tf2_ros
    tf2_geometry_msgs
    vldp_core
)

catkin_package(
    INCLUDE_DIRS include
    CATKIN_DEPENDS
        roscpp
        std_msgs
        geometry_msgs
        nav_msgs
        tf2
        tf2_ros
        tf2_geometry_msgs
        vldp_core
)

include_directories(
    include
    ${catkin_INCLUDE_DIRS}
)

add_library(${PROJECT_NAME}
    src/localization.cpp
)

target_link_libraries(${PROJECT_NAME}
    ${catkin_LIBRARIES}
)

add_executable(localization_node
    src/localization_node.cpp
    src/main.cpp
)

target_link_libraries(localization_node
    ${PROJECT_NAME}
    ${catkin_LIBRARIES}
)
