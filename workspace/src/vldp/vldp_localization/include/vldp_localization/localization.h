#ifndef VLDP_LOCALIZATION_LOCALIZATION_H_
#define VLDP_LOCALIZATION_LOCALIZATION_H_

#include <mutex>

#include "ros/ros.h"

#include "vldp_core/pose.h"
#include "vldp_core/velocity.h"

namespace vldp
{

/**
 * @brief 定位数据来源
 *
 * 后续可根据不同定位设备或算法扩展。
 */
enum class LocalizationSource
{
    NONE = 0,

    GAZEBO = 10,

    GPS = 20,

    VINS = 30,

    RTK = 40
};

 std::string LocalizationSourceToString(
    LocalizationSource source);

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

    bool Initialize();

    /**
     * @brief 更新定位状态
     *
     * @param pose      当前位姿
     * @param velocity  当前速度
     * @param source    定位来源
     */
	void Update(
	    const vldp::Pose& pose,
	    const vldp::Velocity& velocity,
	    LocalizationSource source
	    );
	    
    void Reset();

    /**
     * @brief 获取当前位姿
     */
    vldp::Pose GetPose() const;

    /**
     * @brief 获取当前速度
     */
    vldp::Velocity GetVelocity() const;

    /**
     * @brief 获取定位来源
     */
    LocalizationSource GetLocalizationSource() const;

    /**
     * @brief 当前定位是否有效
     */
    bool IsLocalizationValid() const;
   
    ros::Time GetLastUpdateTime() const;
    
   
private:

    /// 当前位姿
    vldp::Pose pose_;

    /// 当前速度
    vldp::Velocity velocity_;

    /// 定位来源
    LocalizationSource source_;

    /// 定位是否有效
    bool localization_valid_;

    /// 数据互斥锁
    mutable std::mutex mutex_;
    
    ros::Time last_update_time_;
    
    
};

}   // namespace vldp

#endif  // VLDP_LOCALIZATION_LOCALIZATION_H_
