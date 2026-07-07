cmake_minimum_required(VERSION 3.0.2)

project(vldp_px4_bridge)


find_package(catkin REQUIRED COMPONENTS
  roscpp
  geometry_msgs
  mavros_msgs
  vldp_msgs
  vldp_core
)


catkin_package(
  INCLUDE_DIRS include
  CATKIN_DEPENDS
    roscpp
    geometry_msgs
    mavros_msgs
    vldp_msgs
    vldp_core
)


include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)


add_library(
  px4_bridge
  src/px4_bridge.cpp
)


target_link_libraries(
  px4_bridge
  ${catkin_LIBRARIES}
)


add_executable(
  vldp_px4_bridge_node
  src/main.cpp
  src/px4_bridge_node.cpp
)


target_link_libraries(
  vldp_px4_bridge_node
  px4_bridge
  ${catkin_LIBRARIES}
)
