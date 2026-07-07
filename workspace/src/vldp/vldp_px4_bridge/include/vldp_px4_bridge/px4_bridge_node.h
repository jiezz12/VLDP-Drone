/******************************************************************************
 * @file px4_bridge_node.h
 * @brief PX4桥接ROS节点
 *
 * 负责ROS消息与PX4控制接口之间的数据转换。
 *
 * Project : VLDP-Drone
 ******************************************************************************/

#pragma once

#include <ros/ros.h>

#include <geometry_msgs/TwistStamped.h>
#include <mavros_msgs/State.h>

#include <vldp_msgs/ControlCommand.h>

#include "vldp_px4_bridge/px4_bridge.h"


namespace vldp
{

/**
 * @brief PX4桥接ROS节点
 */
class PX4BridgeNode
{

public:

    /**
     * @brief 构造函数
     *
     * @param nh ROS节点句柄
     */
    explicit PX4BridgeNode(ros::NodeHandle& nh);


    /**
     * @brief 初始化节点
     */
    void Initialize();


private:

    /**
     * @brief 控制指令回调
     */
    void CommandCallback(
        const vldp_msgs::ControlCommand::ConstPtr& msg
    );


    /**
     * @brief PX4状态回调
     */
    void StateCallback(
        const mavros_msgs::State::ConstPtr& msg
    );


    /**
     * @brief 发布速度控制指令
     */
	void PublishCommand(
	    const ros::TimerEvent& event
	);


private:

    ros::NodeHandle nh_;


    /// 控制指令订阅
    ros::Subscriber command_sub_;


    /// PX4状态订阅
    ros::Subscriber state_sub_;


    /// 速度控制发布
    ros::Publisher velocity_pub_;


    /// PX4桥接核心类
    PX4Bridge bridge_;


    /// PX4状态
    mavros_msgs::State px4_state_;


    /// 发布频率
    ros::Timer timer_;

};

} // namespace vldp
