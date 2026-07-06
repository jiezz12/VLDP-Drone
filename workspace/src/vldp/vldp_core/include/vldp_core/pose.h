#pragma once

/**
 * @file pose.h
 * @brief 位姿数据结构
 */

namespace vldp
{

/**
 * @brief 三维位姿
 *
 * 坐标系：
 * ENU（East-North-Up）
 *
 * 姿态表示：
 * 四元数（Hamilton）
 */
struct Pose
{
    /// 时间戳（秒）
    double timestamp{0.0};

    /// 位置（米）
    double x{0.0};
    double y{0.0};
    double z{0.0};

    /// 四元数
    double qw{1.0};
    double qx{0.0};
    double qy{0.0};
    double qz{0.0};
};

} // namespace vldp
