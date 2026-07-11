#ifndef VLDP_LOCALIZATION_LOCALIZATION_CONVERTER_H_
#define VLDP_LOCALIZATION_LOCALIZATION_CONVERTER_H_

#include <gazebo_msgs/ModelStates.h>
#include <geometry_msgs/PoseStamped.h>
#include <nav_msgs/Odometry.h>

#include "vldp_core/pose.h"
#include "vldp_core/velocity.h"

namespace vldp
{

class LocalizationConverter
{
public:

    static void GazeboPoseToPose(
    const geometry_msgs::Pose& input,
    Pose* output);

    static void GazeboTwistToVelocity(
        const geometry_msgs::Twist& input,
        Velocity* output);
        
    static void VinsOdometryToPose(
    	const nav_msgs::Odometry& input,
    	Pose* output);

    static void VinsOdometryToVelocity(
    	const nav_msgs::Odometry& input,
    	Velocity* output);
    
    static void PoseToVisionPose(
	    const Pose& input,
	    const std::string& frame_id,
	    geometry_msgs::PoseStamped* output);
        
};

}   // namespace vldp

#endif
