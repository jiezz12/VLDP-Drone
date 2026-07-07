/******************************************************************************
 * @file controller_node.cpp
 * @brief 控制器 ROS 节点实现
 *
 * Project : VLDP-Drone
 ******************************************************************************/

#include "vldp_controller/controller_node.h"

#include "vldp_common/logger.h"

namespace vldp
{

ControllerNode::ControllerNode(ros::NodeHandle& nh)
    : nh_(nh),
      control_frequency_(20.0)
{
}

bool ControllerNode::Initialize()
{
    Log::Info("========== VLDP Controller ==========");

    if (!LoadParameters())
    {
        Log::Error("加载参数失败。");
        return false;
    }

    if (!controller_.Initialize())
    {
        Log::Error("Controller 初始化失败。");
        return false;
    }

    if (!CreateTimer())
    {
        Log::Error("创建控制循环定时器失败。");
        return false;
    }

    Log::Info("ControllerNode 初始化完成。");

    return true;
}

bool ControllerNode::LoadParameters()
{
    // 如果参数服务器不存在，则使用默认值
    nh_.param("controller_frequency",
              control_frequency_,
              20.0);

    Log::Info("控制频率：" +
              std::to_string(control_frequency_) +
              " Hz");

    return true;
}

bool ControllerNode::CreateTimer()
{
    control_timer_ = nh_.createTimer(
        ros::Duration(1.0 / control_frequency_),
        &ControllerNode::ControlTimerCallback,
        this);

    return true;
}

void ControllerNode::ControlTimerCallback(
    const ros::TimerEvent&)
{
    controller_.Update();
}

} // namespace vldp
