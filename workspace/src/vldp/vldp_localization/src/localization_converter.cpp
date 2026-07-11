#include "vldp_localization/localization_converter.h"

namespace vldp
{

void LocalizationConverter::GazeboPoseToPose(
    const geometry_msgs::Pose& input,
    Pose* output)
{
	output->timestamp =
    ros::Time::now().toSec();
	
    output->x = input.position.x;
    output->y = input.position.y;
    output->z = input.position.z;

    output->qw = input.orientation.w;
    output->qx = input.orientation.x;
    output->qy = input.orientation.y;
    output->qz = input.orientation.z;
}

void LocalizationConverter::GazeboTwistToVelocity(
    const geometry_msgs::Twist& input,
    Velocity* output)
{
    output->x = input.linear.x;
    output->y = input.linear.y;
    output->z = input.linear.z;

    output->x_rate = input.angular.x;
    output->y_rate = input.angular.y;
    output->yaw_rate = input.angular.z;
}

void LocalizationConverter::VinsOdometryToPose(
    const nav_msgs::Odometry& input,
    Pose* output)
{
    output->timestamp =
    input.header.stamp.toSec();

output->x =
    input.pose.pose.position.x;

output->y =
    input.pose.pose.position.y;

output->z =
    input.pose.pose.position.z;

output->qw =
    input.pose.pose.orientation.w;

output->qx =
    input.pose.pose.orientation.x;

output->qy =
    input.pose.pose.orientation.y;

output->qz =
    input.pose.pose.orientation.z;
}

void LocalizationConverter::VinsOdometryToVelocity(
    const nav_msgs::Odometry& input,
    Velocity* output)
    {
    output->x =
    input.twist.twist.linear.x;

output->y =
    input.twist.twist.linear.y;

output->z =
    input.twist.twist.linear.z;

output->x_rate =
    input.twist.twist.angular.x;

output->y_rate =
    input.twist.twist.angular.y;

output->yaw_rate =
    input.twist.twist.angular.z;
    
    }

void LocalizationConverter::PoseToVisionPose(
    const Pose& input,
    const std::string& frame_id,
    geometry_msgs::PoseStamped* output)
{
	output->header.stamp =
	    ros::Time(input.timestamp);
    output->header.frame_id = frame_id;

    output->pose.position.x = input.x;
    output->pose.position.y = input.y;
    output->pose.position.z = input.z;

    //output->pose.orientation = input.orientation;
    
    output->pose.orientation.w = input.qw;
    output->pose.orientation.x = input.qx;
    output->pose.orientation.y = input.qy;
    output->pose.orientation.z = input.qz;
}

}   // namespace vldp
