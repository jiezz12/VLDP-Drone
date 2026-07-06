#pragma once

/**
 * @file platform_node.h
 * @brief VLDP Platform节点
 */

#include <ros/ros.h>

namespace vldp
{

class PlatformNode
{
public:

    explicit PlatformNode(ros::NodeHandle& nh);

    ~PlatformNode() = default;

    /**
     * @brief 初始化节点
     * @return true 成功
     * @return false 失败
     */
    bool Initialize();

private:

    ros::NodeHandle nh_;
};

} // namespace vldp
