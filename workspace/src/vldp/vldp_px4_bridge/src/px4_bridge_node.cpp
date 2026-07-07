/******************************************************************************
 * @file px4_bridge_node.cpp
 * @brief PX4桥接ROS节点实现
 *
 * Project : VLDP-Drone
 ******************************************************************************/

#include "vldp_px4_bridge/px4_bridge_node.h"

#include <locale.h>


namespace vldp
{

PX4BridgeNode::PX4BridgeNode(ros::NodeHandle& nh)
    : nh_(nh)
{
}


void PX4BridgeNode::Initialize()
{
    // ROS订阅

    command_sub_ = nh_.subscribe(
        "/vldp/control_command",
        10,
        &PX4BridgeNode::CommandCallback,
        this
    );

    state_sub_ = nh_.subscribe(
        "/mavros/state",
        10,
        &PX4BridgeNode::StateCallback,
        this
    );


    // ROS发布

    velocity_pub_ = nh_.advertise<geometry_msgs::TwistStamped>(
        "/mavros/setpoint_velocity/cmd_vel",
        10
    );


    // 控制频率
    timer_ = nh_.createTimer(
        ros::Duration(0.05),
        &PX4BridgeNode::PublishCommand,
        this
    );


    ROS_INFO("PX4 Bridge 初始化完成");
}


void PX4BridgeNode::CommandCallback(
    const vldp_msgs::ControlCommand::ConstPtr& msg
)
{
    ControlCommand command;

    command.vx = msg->vx;
    command.vy = msg->vy;
    command.vz = msg->vz;
    command.yaw_rate = msg->yaw_rate;
    command.valid = msg->valid;


    bridge_.SetCommand(command);


    if (command.valid)
    {
        ROS_INFO(
            "收到控制指令 vx=%.2f vy=%.2f vz=%.2f",
            command.vx,
            command.vy,
            command.vz
        );
    }
}


void PX4BridgeNode::StateCallback(
    const mavros_msgs::State::ConstPtr& msg
)
{
    px4_state_ = *msg;


    ROS_INFO_THROTTLE(
        5.0,
        "PX4连接状态: %s  模式: %s",
        px4_state_.connected ? "true" : "false",
        px4_state_.mode.c_str()
    );
}


void PX4BridgeNode::PublishCommand(
    const ros::TimerEvent& event
)
{
    ControlCommand command = bridge_.GetCommand();


    geometry_msgs::TwistStamped msg;


    msg.header.stamp = ros::Time::now();


    if (command.valid)
    {
        msg.twist.linear.x = command.vx;
        msg.twist.linear.y = command.vy;
        msg.twist.linear.z = command.vz;

        msg.twist.angular.z = command.yaw_rate;
    }
    else
    {
        // 没有有效命令时保持零速度

        msg.twist.linear.x = 0.0;
        msg.twist.linear.y = 0.0;
        msg.twist.linear.z = 0.0;

        msg.twist.angular.z = 0.0;
    }


    velocity_pub_.publish(msg);
}


} // namespace vldp
