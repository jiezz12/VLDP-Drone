#include <ros/ros.h>

#include "vldp_common/config.h"
#include "vldp_common/file_utils.h"
#include "vldp_common/logger.h"
#include "vldp_common/time.h"
#include "vldp_common/timer.h"

int main(int argc, char** argv)
{
    setlocale(LC_ALL, "");
    ros::init(argc, argv, "test_common");
   
    ros::NodeHandle nh;

    vldp::Log::Initialize();
    
    vldp::Log::Info("========== 开始测试 vldp_common ==========");
    
    // Timer测试
    vldp::Timer timer;

    ros::Duration(0.1).sleep();
    
    vldp::Log::Info(
        "耗时：" +
        std::to_string(timer.Elapsed()));
    
    // Time测试
    vldp::Log::Info(
        "当前时间：" +
        vldp::Time::NowString());
    
    // File测试
    if (vldp::FileUtils::Exists("/tmp"))
    {
        vldp::Log::Info("/tmp 存在");
    }
    
    // Config测试
    vldp::Config::Load("config/default.yaml");
    
    vldp::Log::Info("========== 测试结束 ==========");
    
    return 0;
}
