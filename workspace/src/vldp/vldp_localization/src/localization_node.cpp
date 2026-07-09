/******************************************************************************
 * @file localization_node.cpp
 * @brief Localization ROS节点实现
 *
 * Project : Vision-Language Differentiable Physics Drone (VLDP)
 ******************************************************************************/

#include "vldp_localization/localization_node.h"

#include "vldp_common/logger.h"

#include <gazebo_msgs/ModelStates.h>

namespace vldp
{

LocalizationNode::LocalizationNode()
    : private_nh_("~"),
      vehicle_index_(-1)
{
}

bool LocalizationNode::Initialize()
{
    vldp::Log::Info(
        "Initializing localization node.");

    localization_ =
        std::make_unique<Localization>();

    if (!localization_->Initialize())
    {
        vldp::Log::Error(
            "Failed to initialize localization.");

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

    vldp::Log::Info(
        "Localization node initialized.");

    return true;
}

bool LocalizationNode::LoadParameters()
{
    private_nh_.param(
        "gazebo_model_states_topic",
        gazebo_topic_,
        std::string("/gazebo/model_states"));

    return true;
}

bool LocalizationNode::CreateROSInterfaces()
{
    gazebo_sub_ =
        nh_.subscribe(
            gazebo_topic_,
            10,
            &LocalizationNode::ModelStatesCallback,
            this);

    return true;
}

void LocalizationNode::ModelStatesCallback(
    const gazebo_msgs::ModelStatesConstPtr& msg)
{
    if (vehicle_index_ < 0)
    {
        for (size_t i = 0;
             i < msg->name.size();
             ++i)
        {
            if (msg->name[i] == "iris")
            {
                vehicle_index_ =
                    static_cast<int>(i);

                vldp::Log::Info(
                    "Found vehicle model: iris");

                break;
            }
        }

        if (vehicle_index_ < 0)
        {
            return;
        }
    }

    const auto& gazebo_pose =
        msg->pose[vehicle_index_];

    const auto& gazebo_twist =
        msg->twist[vehicle_index_];

    vldp::Pose pose;

   // 从 gazebo_pose 到 vldp::Pose
	pose.x = gazebo_pose.position.x;
	pose.y = gazebo_pose.position.y;
	pose.z = gazebo_pose.position.z;
	pose.qw = gazebo_pose.orientation.w;
	pose.qx = gazebo_pose.orientation.x;
	pose.qy = gazebo_pose.orientation.y;
	pose.qz = gazebo_pose.orientation.z;

    vldp::Velocity velocity;

    velocity.x = gazebo_twist.linear.x;
	velocity.y = gazebo_twist.linear.y;
	velocity.z = gazebo_twist.linear.z;

    velocity.x_rate =
        gazebo_twist.angular.x;

    velocity.y_rate =
        gazebo_twist.angular.y;

    velocity.yaw_rate =
        gazebo_twist.angular.z;

    localization_->Update(
        pose,
        velocity,
        vldp::LocalizationSource::GAZEBO);
}

} // namespace vldp
