#ifndef VLDP_LOCALIZATION_LOCALIZATION_NODE_H_
#define VLDP_LOCALIZATION_LOCALIZATION_NODE_H_

#include <memory>

#include <ros/ros.h>
#include <nav_msgs/Odometry.h>

#include "vldp_localization/localization.h"

namespace vldp_localization
{

/**
 * @brief Localization ROS节点
 *
 * 负责：
 * 1. 参数加载
 * 2. Topic创建
 * 3. Topic订阅
 * 4. Topic发布
 *
 * 不负责定位算法。
 */
class LocalizationNode
{
public:

    LocalizationNode();

    ~LocalizationNode() = default;

    /**
     * @brief 初始化节点
     * @return 是否初始化成功
     */
    bool Initialize();

private:

    /**
     * @brief 加载ROS参数
     */
    bool LoadParameters();

    /**
     * @brief 创建Publisher和Subscriber
     */
    bool CreateROSInterfaces();

    /**
     * @brief 创建定时器（预留）
     */
    bool CreateTimer();

    /**
     * @brief 接收定位数据
     *
     * 第一阶段先接Gazebo Ground Truth，
     * 后续切换VINS无需修改Localization类。
     */
    void OdometryCallback(
        const nav_msgs::OdometryConstPtr& msg);

private:

    /// ROS节点句柄
    ros::NodeHandle nh_;

    /// 私有节点句柄
    ros::NodeHandle private_nh_;

    /// 定位数据订阅器
    ros::Subscriber odometry_sub_;

    /// PX4 Vision Pose（第二阶段启用）
    ros::Publisher vision_pose_pub_;

    /// Localization核心模块
    std::unique_ptr<Localization> localization_;

    /// Topic名称
    std::string odometry_topic_;

    /// Vision Pose发布Topic
    std::string vision_pose_topic_;
};

}  // namespace vldp_localization

#endif  // VLDP_LOCALIZATION_LOCALIZATION_NODE_H_
