/******************************************************************************
 * @file observation.h
 * @brief 无人机观测数据
 *
 * Observation 表示当前控制器能够获取到的无人机状态，
 * 作为策略层（Policy）的输入。
 *
 * 当前版本包含：
 * 1. 位姿
 * 2. 速度
 *
 * 后续根据需要逐步增加。
 *
 * Project : VLDP-Drone
 ******************************************************************************/

#pragma once

#include "vldp_core/pose.h"
#include "vldp_core/velocity.h"

namespace vldp
{

/**
 * @brief 无人机观测数据
 */
struct Observation
{
    /// 当前位姿
    Pose pose;

    /// 当前速度
    Velocity velocity;

    /// 数据是否有效
    bool valid{false};
};

} // namespace vldp
