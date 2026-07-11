/******************************************************************************
 * @file control_command.h
 * @brief 无人机控制指令数据结构
 *
 * 定义控制器输出的目标控制指令。
 * 当前版本采用速度控制模式，包括三轴线速度和偏航角速度。
 *
 * 后续如果切换到姿态控制或推力控制，可在此基础上扩展。
 *
 * Project : VLDP-Drone
 ******************************************************************************/

#pragma once

namespace vldp
{

/**
 * @brief 无人机控制指令
 */
struct ControlCommand
{
    /// 前向速度（m/s）
    double vx{0.0};

    /// 左向速度（m/s）
    double vy{0.0};

    /// 向上速度（m/s）
    double vz{0.0};

    /// 偏航角速度（rad/s）
        double x_rate{0.0};
        double y_rate{0.0};
    
    double yaw_rate{0.0};

    /// 是否有效
    bool valid{false};
};

} // namespace vldp
