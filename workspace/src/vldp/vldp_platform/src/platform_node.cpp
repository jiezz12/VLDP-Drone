#include "vldp_platform/platform_node.h"

#include "vldp_common/logger.h"

namespace vldp
{

PlatformNode::PlatformNode(ros::NodeHandle& nh)
    : nh_(nh)
{

}

bool PlatformNode::Initialize()
{
    Log::Info("Platform 初始化成功");

    return true;
}

} // namespace vldp
