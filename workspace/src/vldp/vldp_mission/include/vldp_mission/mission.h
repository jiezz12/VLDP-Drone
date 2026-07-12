#pragma once

/**
 * @file mission.h
 * @brief Mission模块
 *
 * Mission负责维护无人机当前任务目标，
 * 并向Controller提供目标位姿。
 */

#include <mutex>

#include <vldp_core/pose.h>

namespace vldp
{

class Mission
{
public:

    Mission();

    ~Mission() = default;

    /**
     * @brief 初始化Mission
     */
    bool Initialize();

    /**
     * @brief 更新当前无人机位姿
     */
    void SetCurrentPose(const Pose& pose);

    /**
     * @brief 获取当前无人机位姿
     */
    Pose GetCurrentPose() const;

    /**
     * @brief 设置目标位姿
     */
    void SetGoal(const Pose& goal);

    /**
     * @brief 获取目标位姿
     */
    Pose GetGoal() const;

    /**
     * @brief 是否存在目标
     */
    bool HasGoal() const;

    /**
     * @brief 清除目标
     */
    void ClearGoal();

    /**
     * @brief 起飞任务
     * @param height 相对当前高度增加(m)
     */
    bool Takeoff(double height);

    /**
     * @brief 降落任务
     */
    bool Land();

    /**
     * @brief 悬停任务
     */
    bool Hover();

    /**
     * @brief 飞往指定位置
     */
    bool Goto(const Pose& goal);

private:

    mutable std::mutex mutex_;

    /// 当前位姿（Localization更新）
    Pose current_pose_;

    /// Mission目标
    Pose goal_;

    /// 是否已有目标
    bool has_goal_;
};

} // namespace vldp
