#ifndef VLDP_LOCALIZATION_LOCALIZATION_H_
#define VLDP_LOCALIZATION_LOCALIZATION_H_

#include <mutex>

#include "vldp_core/pose.h"
#include "vldp_core/velocity.h"

namespace vldp_localization
{

/**
 * @brief 定位数据来源
 *
 * 后续可根据不同定位设备或算法扩展。
 */
enum class LocalizationSource
{
    NONE = 0,

    GAZEBO,

    VINS_FUSION,

    OPEN_VINS,

    ORB_SLAM3,

    GPS,

    RTK,

    MOCAP
};

/**
 * @brief 统一定位状态管理类
 *
 * 本类不负责运行任何定位算法，仅负责：
 * 1. 保存统一位姿状态
 * 2. 保存统一速度状态
 * 3. 记录当前定位来源
 * 4. 管理定位有效性
 *
 * 本类不依赖 ROS，不依赖 PX4，不依赖具体定位算法，
 * 是整个 VLDP 的统一状态管理模块。
 */
class Localization
{
public:

    Localization();

    ~Localization() = default;

    /**
     * @brief 初始化定位模块
     * @return 是否初始化成功
     */
    bool Initialize();

    /**
     * @brief 更新位姿
     * @param pose 最新位姿
     */
    void UpdatePose(const vldp_core::Pose& pose);

    /**
     * @brief 更新速度
     * @param velocity 最新速度
     */
    void UpdateVelocity(const vldp_core::Velocity& velocity);

    /**
     * @brief 设置定位来源
     * @param source 定位来源
     */
    void SetLocalizationSource(LocalizationSource source);

    /**
     * @brief 设置定位有效性
     * @param valid 是否有效
     */
    void SetLocalizationValid(bool valid);

    /**
     * @brief 获取当前位姿
     */
    vldp_core::Pose GetPose() const;

    /**
     * @brief 获取当前速度
     */
    vldp_core::Velocity GetVelocity() const;

    /**
     * @brief 获取定位来源
     */
    LocalizationSource GetLocalizationSource() const;

    /**
     * @brief 当前定位是否有效
     */
    bool IsLocalizationValid() const;

private:

    /// 当前位姿
    vldp_core::Pose pose_;

    /// 当前速度
    vldp_core::Velocity velocity_;

    /// 定位来源
    LocalizationSource source_;

    /// 定位是否有效
    bool localization_valid_;

    /// 数据互斥锁
    mutable std::mutex mutex_;
};

}   // namespace vldp_localization

#endif  // VLDP_LOCALIZATION_LOCALIZATION_H_
