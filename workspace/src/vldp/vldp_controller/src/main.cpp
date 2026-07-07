/******************************************************************************
 * @file main.cpp
 * @brief vldp_controller 主程序
 *
 * Project : VLDP-Drone
 ******************************************************************************/

#include <clocale>

#include <ros/ros.h>

#include "vldp_common/logger.h"
#include "vldp_controller/controller_node.h"

int main(int argc, char** argv)
{
    // 设置系统区域，支持中文输出
    setlocale(LC_ALL, "");

    // 初始化 ROS
    ros::init(argc, argv, "vldp_controller");

    // 创建节点句柄
    ros::NodeHandle nh("~");

    // 初始化日志系统
    vldp::Log::Initialize();

    // 创建控制器节点
    vldp::ControllerNode controller_node(nh);

    if (!controller_node.Initialize())
    {
        vldp::Log::Error("ControllerNode 初始化失败。");
        return -1;
    }

    ros::spin();

    return 0;
}
