/******************************************************************************
 * @file localization.cpp
 * @brief 统一定位状态管理类实现
 *
 * Project : Vision-Language Differentiable Physics Drone (VLDP)
 ******************************************************************************/

#include "vldp_localization/localization.h"

namespace vldp
{

Localization::Localization()
    : source_(LocalizationSource::NONE),
      localization_valid_(false)
{
}

bool Localization::Initialize()
{
    std::lock_guard<std::mutex> lock(mutex_);

    pose_ = vldp::Pose();
    velocity_ = vldp::Velocity();

    source_ = LocalizationSource::NONE;
    localization_valid_ = false;

    return true;
}

void Localization::Update(
    const vldp::Pose& pose,
    const vldp::Velocity& velocity,
    LocalizationSource source)
{
    std::lock_guard<std::mutex> lock(mutex_);

    pose_ = pose;
    velocity_ = velocity;
    source_ = source;
    localization_valid_ = true;
}

void Localization::Reset()
{
    std::lock_guard<std::mutex> lock(mutex_);

    localization_valid_ = false;
}

vldp::Pose Localization::GetPose() const
{
    std::lock_guard<std::mutex> lock(mutex_);

    return pose_;
}

vldp::Velocity Localization::GetVelocity() const
{
    std::lock_guard<std::mutex> lock(mutex_);

    return velocity_;
}

LocalizationSource Localization::GetLocalizationSource() const
{
    std::lock_guard<std::mutex> lock(mutex_);

    return source_;
}

bool Localization::IsLocalizationValid() const
{
    std::lock_guard<std::mutex> lock(mutex_);

    return localization_valid_;
}

} // namespace vldp_localization
