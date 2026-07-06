#pragma once

/**
 * @file velocity.h
 * @brief 速度数据结构
 */

namespace vldp
{

/**
 * @brief 三维速度
 */
struct Velocity
{
    /// 线速度（m/s）
    double vx{0.0};
    double vy{0.0};
    double vz{0.0};

    /// 角速度（rad/s）
    double wx{0.0};
    double wy{0.0};
    double wz{0.0};
};

}
