#pragma once

#include <ros/ros.h>

#include <vldp_common/logger.h>

#include <vldp_mission/mission.h>

namespace vldp
{

class MissionNode
{
public:

    MissionNode();

    ~MissionNode() = default;

    bool Initialize();

private:

    bool LoadParameters();

    bool CreateTimer();

    void TimerCallback(
        const ros::TimerEvent& event);

private:

    ros::NodeHandle nh_;

    ros::NodeHandle private_nh_;

    ros::Timer timer_;

    double update_rate_;

    Mission mission_;
};

}  // namespace vldp
