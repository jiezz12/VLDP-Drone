/******************************************************************************
 * @file controller.cpp
 * @brief 无人机控制器核心类实现
 *
 * Project : VLDP-Drone
 ******************************************************************************/

#include "vldp_controller/controller.h"


namespace vldp
{


Controller::Controller()
    : control_count_(0)
{
}


bool Controller::Initialize()
{
    control_count_ = 0;

    command_.vx = 0.0;
    command_.vy = 0.0;
    command_.vz = 0.0;
    command_.yaw_rate = 0.0;
    command_.valid = false;


    return true;
}


ControlCommand Controller::Update()
{
    control_count_++;


    /*
     * Sprint2测试阶段：
     *
     * 固定输出前进速度。
     *
     * 后续替换为：
     * 视觉算法
     * VLM决策
     * 轨迹规划
     */

    command_.vx = 0.3;
    command_.vy = 0.0;
    command_.vz = 0.0;
    command_.yaw_rate = 0.0;

    command_.valid = true;


    return command_;
}


} // namespace vldp
