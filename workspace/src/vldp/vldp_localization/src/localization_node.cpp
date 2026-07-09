/******************************************************************************
 * @file localization_node.cpp
 * @brief Localization ROS节点实现
 *
 * Project : Vision-Language Differentiable Physics Drone (VLDP)
 ******************************************************************************/

#include "vldp_localization/localization_node.h"

namespace vldp_localization
{

LocalizationNode::LocalizationNode()
    : private_nh_("~"),
      vehicle_index_(-1)
{
}

bool LocalizationNode::Initialize()
{
    vldp::Log::Info("Initializing localization node...");

    localization_ = std::make_unique<Localization>();

    if (!localization_->Initialize())
    {
        vldp::Log::Error("Failed to initialize localization.");
        return false;
    }

    if (!LoadParameters())
    {
        return false;
    }

    if (!CreateROSInterfaces())
    {
        return false;
    }

    if (!CreateTimer())
    {
        return false;
    }

    vldp::Log::Info("Localization node initialized.");

    return true;
}

bool LocalizationNode::LoadParameters()
{
    private_nh_.param(
        "gazebo_model_states_topic",
        gazebo_topic_,
        std::string("/gazebo/model_states"));

    private_nh_.param(
        "update_rate",
        update_rate_,
        30.0);

    return true;
}

bool LocalizationNode::CreateROSInterfaces()
{
    gazebo_sub_ = nh_.subscribe(
        gazebo_topic_,
        10,
        &LocalizationNode::ModelStatesCallback,
        this);

    return true;
}

bool LocalizationNode::CreateTimer()
{
    // Sprint3 Phase1 暂时无需定时器

    return true;
}

void LocalizationNode::OdometryCallback(
    const nav_msgs::OdometryConstPtr& msg)
{
    (void)msg;

    // 下一阶段：
    //
    // nav_msgs::Odometry
    //       ↓
    // Pose
    // Velocity
    //       ↓
    // Localization
}

void LocalizationNode::ModelStatesCallback(
    const gazebo_msgs::ModelStatesConstPtr& msg)
{
    if (vehicle_index_ < 0)
    {
        for (size_t i = 0; i < msg->name.size(); ++i)
        {
            if (msg->name[i] == "iris")
            {
                vehicle_index_ = static_cast<int>(i);

                vldp::Log::Info("Found vehicle model: iris");

                break;
            }
        }

        if (vehicle_index_ < 0)
        {
            return;
        }
    }

    vldp::Pose pose;

    pose.position.x = msg->pose[vehicle_index_].position.x;
    pose.position.y = msg->pose[vehicle_index_].position.y;
    pose.position.z = msg->pose[vehicle_index_].position.z;

    pose.orientation.w = msg->pose[vehicle_index_].orientation.w;
    pose.orientation.x = msg->pose[vehicle_index_].orientation.x;
    pose.orientation.y = msg->pose[vehicle_index_].orientation.y;
    pose.orientation.z = msg->pose[vehicle_index_].orientation.z;

    vldp::Velocity velocity;

    velocity.linear.x = msg->twist[vehicle_index_].linear.x;
    velocity.linear.y = msg->twist[vehicle_index_].linear.y;
    velocity.linear.z = msg->twist[vehicle_index_].linear.z;

    velocity.angular.x = msg->twist[vehicle_index_].angular.x;
    velocity.angular.y = msg->twist[vehicle_index_].angular.y;
    velocity.angular.z = msg->twist[vehicle_index_].angular.z;

    localization_->Update(
        pose,
        velocity,
        LocalizationSource::GAZEBO);
}

} // namespace vldp_localization
