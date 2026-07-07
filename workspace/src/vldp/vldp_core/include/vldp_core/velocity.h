/******************************************************************************
 * @file velocity.h
 * @brief 无人机速度数据结构
 *
 * 定义无人机线速度和角速度。
 *
 * Project : VLDP-Drone
 ******************************************************************************/

#pragma once

namespace vldp
{

struct Velocity
{
    /// 线速度（m/s）
    double x{0.0};
    double y{0.0};
    double z{0.0};

    /// 偏航角速度（rad/s）
    double yaw_rate{0.0};
};

} // namespace vldp
