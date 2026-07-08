/******************************************************************************
 * @file controller.h
 * @brief 无人机控制器核心类
 *
 * Controller 负责无人机控制逻辑。
 *
 * Controller 不直接处理 ROS Topic、
 * Publisher 或 Subscriber。
 *
 * 输出统一控制指令：
 * vldp::ControlCommand
 *
 * Project : VLDP-Drone
 ******************************************************************************/

#pragma once

#include <cstdint>

#include "vldp_core/control_command.h"


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
     *
     * @return 初始化成功返回 true
     */
    bool Initialize();


    /**
     * @brief 控制器更新
     *
     * 根据当前状态生成控制指令。
     *
     * 当前版本：
     * 输出测试速度指令。
     *
     * @return 控制指令
     */
    ControlCommand Update();


private:

    /**
     * @brief 控制循环计数
     */
    uint64_t control_count_;


    /**
     * @brief 当前控制指令
     */
    ControlCommand command_;

};


} // namespace vldp
