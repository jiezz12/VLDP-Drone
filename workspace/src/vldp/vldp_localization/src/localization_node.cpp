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

if (!CreateTimer())
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

bool LocalizationNode::CreateTimer()
{
    publish_timer_ =
        nh_.createTimer(
            ros::Duration(1.0 / update_rate_),
            &LocalizationNode::PublishTimerCallback,
            this);

    return true;
}

void LocalizationNode::PublishTimerCallback(
    const ros::TimerEvent&)
{
	constexpr double kLocalizationTimeout = 1.0;
	
	if ((ros::Time::now() -
     localization_->GetLastUpdateTime()).toSec() >
	    kLocalizationTimeout)
	{
	    localization_->Reset();

	    return;
	}

    LocalizationSource current_source =
    localization_->GetLocalizationSource();

	if (current_source != last_source_)
	{
	    std::stringstream ss;

	    ss << "Localization source switched to "
	       << LocalizationSourceToString(current_source);

	    vldp::Log::Info(ss.str());

	    last_source_ = current_source;
	}

    if (!localization_->IsLocalizationValid())
    {
        return;
    }

    geometry_msgs::PoseStamped msg;

    vldp::LocalizationConverter::PoseToVisionPose(
        localization_->GetPose(),
        localization_frame_,
        &msg);

    vision_pose_pub_.publish(msg);
}

bool LocalizationNode::LoadParameters()
{
    private_nh_.param(
        "gazebo_model_states_topic",
        gazebo_topic_,
        std::string("/gazebo/model_states"));

    private_nh_.param(
    "vision_pose_topic",
    vision_pose_topic_,
    std::string("/mavros/vision_pose/pose"));
    
    private_nh_.param(
    "update_rate",
    update_rate_,
    30.0);
    
    private_nh_.param(
    "vins_topic",
    vins_topic_,
    std::string("/vins_fusion/imu_propagate"));
    
    private_nh_.param(
    "localization_frame",
    localization_frame_,
    std::string("world"));
    
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
            
    vision_pose_pub_ =
    nh_.advertise<geometry_msgs::PoseStamped>(
        vision_pose_topic_,
        10);
        
    vins_sub_ =
    nh_.subscribe(
        vins_topic_,
        10,
        &LocalizationNode::VinsCallback,
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
    vldp::Velocity velocity;

 vldp::LocalizationConverter::GazeboPoseToPose(
    msg->pose[vehicle_index_],
    &pose);

	vldp::LocalizationConverter::GazeboTwistToVelocity(
	    gazebo_twist,
	    &velocity);

pose.timestamp = ros::Time::now().toSec();

    localization_->Update(
        pose,
        velocity,
        vldp::LocalizationSource::GAZEBO);
}

void LocalizationNode::VinsCallback(
    const nav_msgs::OdometryConstPtr& msg)
{
	vldp::Pose pose;

	vldp::Velocity velocity;

	LocalizationConverter::VinsOdometryToPose(
	    *msg,
	    &pose);

	LocalizationConverter::VinsOdometryToVelocity(
	    *msg,
	    &velocity);

	localization_->Update(
	    pose,
	    velocity,
	    LocalizationSource::VINS);
}

} // namespace vldp
