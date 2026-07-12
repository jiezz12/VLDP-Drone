cmake_minimum_required(VERSION 3.0.2)
project(vldp_mission)

## C++17
add_compile_options(-std=c++17)

find_package(catkin REQUIRED COMPONENTS
    roscpp
    std_msgs
    geometry_msgs
    vldp_common
    vldp_core
    vldp_localization
)

catkin_package(
    INCLUDE_DIRS include
    LIBRARIES vldp_mission
    CATKIN_DEPENDS
        roscpp
        std_msgs
        geometry_msgs
    vldp_common
    vldp_core
    vldp_localization
)

include_directories(
    include
    ${catkin_INCLUDE_DIRS}
)

############################################################
# Library
############################################################

add_library(vldp_mission

    src/mission.cpp
)

target_link_libraries(vldp_mission

    ${catkin_LIBRARIES}
)

############################################################
# Node
############################################################

add_executable(vldp_mission_node

    src/mission_node.cpp
)

target_link_libraries(vldp_mission_node

    vldp_mission
    ${catkin_LIBRARIES}
)

############################################################
# Install
############################################################

install(TARGETS
    vldp_mission
    vldp_mission_node

    ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}

    LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}

    RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)

install(DIRECTORY include/

    DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
)
