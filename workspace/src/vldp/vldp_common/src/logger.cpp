#include "vldp_common/logger.h"

#include <ros/console.h>

namespace vldp
{

void Log::Initialize()
{
    ROS_INFO("========== VLDP Logger Initialized ==========");
}

void Log::Debug(const std::string& message)
{
    ROS_DEBUG("%s", message.c_str());
}

void Log::Info(const std::string& message)
{
    ROS_INFO("%s", message.c_str());
}

void Log::Warn(const std::string& message)
{
    ROS_WARN("%s", message.c_str());
}

void Log::Error(const std::string& message)
{
    ROS_ERROR("%s", message.c_str());
}

}