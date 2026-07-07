/******************************************************************************
 * @file px4_bridge.h
 * @brief PX4桥接核心类
 *
 * 负责将VLDP内部控制指令转换为PX4需要的控制数据。
 *
 * 该类不依赖ROS，仅处理控制数据逻辑。
 *
 * Project : VLDP-Drone
 ******************************************************************************/
#pragma once

#include "vldp_core/control_command.h"

namespace vldp
{

/**
 * @brief PX4桥接核心类
 */
class PX4Bridge
{

public:

    /**
     * @brief 构造函数
     */
    PX4Bridge();
    /**
     * @brief 设置控制指令
     *
     * @param command VLDP控制指令
     */
    void SetCommand(
        const ControlCommand& command
    );

    /**
     * @brief 获取当前控制指令
     *
     * @return 当前控制指令
     */
    ControlCommand GetCommand() const;

private:

    /// 当前控制指令
    ControlCommand command_;

};


} // namespace vldp
