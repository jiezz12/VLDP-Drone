#pragma once

/**
 * @file observation.h
 * @brief 无人机观测数据
 */

#include "vldp_core/pose.h"
#include "vldp_core/velocity.h"

namespace vldp
{

struct Observation
{
    Pose pose;

    Velocity velocity;
};

}
