/******************************************************************************
 * @file controller_node.cpp
 * @brief 控制器ROS节点实现
 *
 * Project : VLDP-Drone
 ******************************************************************************/

#include "vldp_controller/controller_node.h"

namespace vldp
{

ControllerNode::ControllerNode(ros::NodeHandle& nh)
    : nh_(nh)
{
}

bool ControllerNode::Initialize()
{
    if (!LoadParameters())
    {
        return false;
    }

    if (!CreateROSInterfaces())
    {
        return false;
    }

    if (!CreateTimer())
    {
        return false;
    }

    if (!controller_.Initialize())
    {
        return false;
    }

    ROS_INFO("========== VLDP Controller ==========");
    ROS_INFO("Control Frequency : %.1f Hz", control_frequency_);
    ROS_INFO("Control Command Topic : /vldp/control_command");
    ROS_INFO("Controller 初始化完成");

    return true;
}

bool ControllerNode::LoadParameters()
{
    nh_.param(
        "control_frequency",
        control_frequency_,
        20.0
    );

    return true;
}

bool ControllerNode::CreateROSInterfaces()
{
    command_pub_ =
        nh_.advertise<vldp_msgs::ControlCommand>(
            "/vldp/control_command",
            10
        );

    return true;
}

bool ControllerNode::CreateTimer()
{
    control_timer_ =
        nh_.createTimer(
            ros::Duration(1.0 / control_frequency_),
            &ControllerNode::ControlTimerCallback,
            this
        );

    return true;
}

void ControllerNode::ControlTimerCallback(
    const ros::TimerEvent&)
{
    ControlCommand command =
        controller_.Update();

    PublishCommand(command);
}

void ControllerNode::PublishCommand(
    const ControlCommand& command)
{
    vldp_msgs::ControlCommand msg;

    msg.vx = command.vx;
    msg.vy = command.vy;
    msg.vz = command.vz;
    msg.yaw_rate = command.yaw_rate;

    msg.valid = command.valid;

    command_pub_.publish(msg);
}

} // namespace vldp
