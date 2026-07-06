#include <clocale>

#include <ros/ros.h>

#include "vldp_common/logger.h"
#include "vldp_platform/platform_node.h"

int main(int argc, char** argv)
{
    setlocale(LC_ALL, "");

    ros::init(argc, argv, "vldp_platform");

    ros::NodeHandle nh;

    vldp::Log::Initialize();

    vldp::Log::Info("========== 启动 VLDP Platform ==========");

    vldp::PlatformNode node(nh);

    if (!node.Initialize())
    {
        vldp::Log::Error("Platform 初始化失败");
        return -1;
    }

    ros::spin();

    return 0;
}
