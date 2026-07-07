/******************************************************************************
 * @file controller.h
 * @brief 无人机控制器核心类
 *
 * Controller 负责无人机控制逻辑，不直接处理 ROS Topic、
 * Publisher 或 Subscriber。所有 ROS 相关内容由
 * ControllerNode 负责。
 *
 * 当前版本（Sprint 1）功能：
 * 1. 控制器初始化
 * 2. 控制循环更新
 *
 * 后续版本将增加：
 * 1. 控制命令管理
 * 2. 安全限制
 * 3. 控制模式管理
 *
 * Project : VLDP-Drone
 ******************************************************************************/

#pragma once

#include <cstdint>

namespace vldp
{

/**
 * @brief 无人机控制器核心类
 */
class Controller
{
public:

    /**
     * @brief 构造函数
     */
    Controller();

    /**
     * @brief 析构函数
     */
    ~Controller() = default;

    /**
     * @brief 初始化控制器
     * @return 初始化成功返回 true
     */
    bool Initialize();

    /**
     * @brief 控制器更新
     */
    void Update();

private:

    /**
     * @brief 控制循环计数
     */
    uint64_t control_count_;
};

} // namespace vldp
