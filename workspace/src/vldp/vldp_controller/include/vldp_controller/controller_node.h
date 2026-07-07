/******************************************************************************
 * @file controller_node.h
 * @brief 控制器 ROS 节点
 *
 * ControllerNode 负责 ROS 相关功能，包括：
 * 1. 参数加载
 * 2. 创建控制循环定时器
 * 3. 调用 Controller 更新
 *
 * 所有控制逻辑均由 Controller 类完成。
 *
 * Project : VLDP-Drone
 ******************************************************************************/

#pragma once

#include <ros/ros.h>

#include "vldp_controller/controller.h"

namespace vldp
{

/**
 * @brief 控制器 ROS 节点
 */
class ControllerNode
{
public:

    /**
     * @brief 构造函数
     * @param nh ROS节点句柄
     */
    explicit ControllerNode(ros::NodeHandle& nh);

    /**
     * @brief 析构函数
     */
    ~ControllerNode() = default;

    /**
     * @brief 初始化节点
     * @return 初始化成功返回 true
     */
    bool Initialize();

private:

    /**
     * @brief 加载参数
     * @return 成功返回 true
     */
    bool LoadParameters();

    /**
     * @brief 创建控制循环定时器
     * @return 成功返回 true
     */
    bool CreateTimer();

    /**
     * @brief 控制循环回调函数
     */
    void ControlTimerCallback(const ros::TimerEvent& event);

private:

    /**
     * @brief ROS节点句柄
     */
    ros::NodeHandle nh_;

    /**
     * @brief 控制器对象
     */
    Controller controller_;

    /**
     * @brief 控制循环定时器
     */
    ros::Timer control_timer_;

    /**
     * @brief 控制频率（Hz）
     */
    double control_frequency_;
};

} // namespace vldp
