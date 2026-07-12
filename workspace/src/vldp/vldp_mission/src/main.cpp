#include <ros/ros.h>

#include <vldp_mission/mission_node.h>

int main(
    int argc,
    char** argv)
{
    ros::init(
        argc,
        argv,
        "vldp_mission");

    vldp::MissionNode node;

    if (!node.Initialize())
    {
        return -1;
    }

    ros::spin();

    return 0;
}
