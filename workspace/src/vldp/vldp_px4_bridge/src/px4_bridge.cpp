/******************************************************************************
 * @file px4_bridge.cpp
 * @brief PX4桥接核心类实现
 *
 * Project : VLDP-Drone
 ******************************************************************************/

#include "vldp_px4_bridge/px4_bridge.h"


namespace vldp
{


PX4Bridge::PX4Bridge()
{
}


void PX4Bridge::SetCommand(
    const ControlCommand& command
)
{
    command_ = command;
}


ControlCommand PX4Bridge::GetCommand() const
{
    return command_;
}


} // namespace vldp
