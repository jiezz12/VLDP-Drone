#include <vldp_mission/mission.h>

#include <sstream>

#include <vldp_common/logger.h>

namespace vldp
{

Mission::Mission()
    : has_goal_(false)
{
}

bool Mission::Initialize()
{
    has_goal_ = false;

    std::stringstream ss;
    ss << "Mission initialized.";

    Log::Info(ss.str());

    return true;
}

void Mission::SetCurrentPose(const Pose& pose)
{
    std::lock_guard<std::mutex> lock(mutex_);

    current_pose_ = pose;
}

Pose Mission::GetCurrentPose() const
{
    std::lock_guard<std::mutex> lock(mutex_);

    return current_pose_;
}

void Mission::SetGoal(const Pose& goal)
{
    std::lock_guard<std::mutex> lock(mutex_);

    goal_ = goal;

    has_goal_ = true;

    std::stringstream ss;
    ss << "Mission goal updated.";

    Log::Info(ss.str());
}

Pose Mission::GetGoal() const
{
    std::lock_guard<std::mutex> lock(mutex_);

    return goal_;
}

bool Mission::HasGoal() const
{
    std::lock_guard<std::mutex> lock(mutex_);

    return has_goal_;
}

void Mission::ClearGoal()
{
    std::lock_guard<std::mutex> lock(mutex_);

    has_goal_ = false;

    std::stringstream ss;
    ss << "Mission goal cleared.";

    Log::Info(ss.str());
}

bool Mission::Takeoff(double height)
{
    std::lock_guard<std::mutex> lock(mutex_);

    goal_ = current_pose_;

    goal_.z += height;

    has_goal_ = true;

    std::stringstream ss;
    ss << "Takeoff mission created. Target altitude = "
       << goal_.z << " m.";

    Log::Info(ss.str());

    return true;
}

bool Mission::Land()
{
    std::lock_guard<std::mutex> lock(mutex_);

    goal_ = current_pose_;

    goal_.z = 0.0;

    has_goal_ = true;

    Log::Info("Land mission created.");

    return true;
}

bool Mission::Hover()
{
    std::lock_guard<std::mutex> lock(mutex_);

    goal_ = current_pose_;

    has_goal_ = true;

    std::stringstream ss;
    ss << "Hover mission created.";

    Log::Info(ss.str());

    return true;
}

bool Mission::Goto(const Pose& goal)
{
    SetGoal(goal);

    std::stringstream ss;
    ss << "Goto mission created.";

    Log::Info(ss.str());

    return true;
}

}  // namespace vldp
