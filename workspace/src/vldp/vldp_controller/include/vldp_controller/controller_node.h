/******************************************************************************
 * @file controller_node.h
 * @brief 控制器 ROS 节点
 *
 * Project : VLDP-Drone
 ******************************************************************************/

#pragma once

#include <ros/ros.h>

#include <vldp_msgs/ControlCommand.h>

#include "vldp_controller/controller.h"

#include "vldp_core/control_command.h"

namespace vldp
{

class ControllerNode
{
public:

    explicit ControllerNode(ros::NodeHandle& nh);

    ~ControllerNode() = default;

    bool Initialize();

private:

    /**
     * @brief 加载参数
     */
    bool LoadParameters();

    /**
     * @brief 创建 ROS 通信
     */
    bool CreateROSInterfaces();


	    bool CreateTimer();
    /**
     * @brief 控制定时器回调
     */
    void ControlTimerCallback(
        const ros::TimerEvent& event
    );

    /**
     * @brief 发布控制命令
     */
    void PublishCommand(
        const ControlCommand& command
    );

private:

    /// ROS节点句柄
    ros::NodeHandle nh_;

    /// 控制器核心
    Controller controller_;

    /// 控制定时器
    ros::Timer control_timer_;

    /// 控制命令发布器
    ros::Publisher command_pub_;

    /// 控制频率
    double control_frequency_;
};

} // namespace vldp
