#include <vldp_mission/mission_node.h>

#include <sstream>

namespace vldp
{

MissionNode::MissionNode()
    : private_nh_("~"),
      update_rate_(30.0)
{
}

bool MissionNode::Initialize()
{
    Log::Info("Initializing Mission Node.");

    if (!LoadParameters())
    {
        Log::Error("Failed to load parameters.");

        return false;
    }

    if (!mission_.Initialize())
    {
        Log::Error("Failed to initialize mission.");

        return false;
    }

    if (!CreateTimer())
    {
        Log::Error("Failed to create timer.");

        return false;
    }

    Log::Info("Mission Node initialized.");

    return true;
}

bool MissionNode::LoadParameters()
{
    private_nh_.param(
        "update_rate",
        update_rate_,
        30.0);

    std::stringstream ss;

    ss << "Mission update rate: "
       << update_rate_
       << " Hz";

    Log::Info(ss.str());

    return true;
}

bool MissionNode::CreateTimer()
{
    timer_ = nh_.createTimer(
        ros::Duration(1.0 / update_rate_),
        &MissionNode::TimerCallback,
        this);

    return true;
}

void MissionNode::TimerCallback(
    const ros::TimerEvent&)
{
    // Sprint4-Part1
    // 暂时没有任务执行逻辑

}

}  // namespace vldp
