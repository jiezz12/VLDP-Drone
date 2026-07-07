/******************************************************************************
 * @file main.cpp
 * @brief PX4桥接节点入口
 *
 * Project : VLDP-Drone
 ******************************************************************************/

#include <ros/ros.h>

#include <locale.h>

#include "vldp_px4_bridge/px4_bridge_node.h"


int main(int argc, char** argv)
{
    // 设置中文环境
    setlocale(LC_ALL, "");

    ros::init(
        argc,
        argv,
        "vldp_px4_bridge_node"
    );


    ros::NodeHandle nh;


    vldp::PX4BridgeNode node(nh);

    node.Initialize();


    ros::spin();


    return 0;
}
