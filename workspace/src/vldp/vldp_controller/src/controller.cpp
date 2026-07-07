/******************************************************************************
 * @file controller.cpp
 * @brief 无人机控制器核心类实现
 *
 * Project : VLDP-Drone
 ******************************************************************************/

#include "vldp_controller/controller.h"

#include "vldp_common/logger.h"

namespace vldp
{

Controller::Controller()
    : control_count_(0)
{
}

bool Controller::Initialize()
{
    Log::Info("Controller 初始化成功。");

    return true;
}

void Controller::Update()
{
    ++control_count_;

    // 每100次输出一次运行状态
    if (control_count_ % 100 == 0)
    {
        Log::Info(
            "Controller 正在运行，控制循环计数："
            + std::to_string(control_count_));
    }
}

} // namespace vldp
