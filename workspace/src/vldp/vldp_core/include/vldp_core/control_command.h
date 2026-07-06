#pragma once

/**
 * @file control_command.h
 * @brief 控制指令
 */

namespace vldp
{

struct ControlCommand
{
    /// 期望速度（ENU）
    double vx{0.0};
    double vy{0.0};
    double vz{0.0};

    /// 期望偏航角速度（rad/s）
    double yaw_rate{0.0};
};

}
