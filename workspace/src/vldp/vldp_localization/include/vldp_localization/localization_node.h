#pragma once

#include <gazebo_msgs/ModelStates.h>
#include <nav_msgs/Odometry.h>
#include <ros/ros.h>
#include <geometry_msgs/PoseStamped.h>

#include "vldp_core/pose.h"
#include "vldp_core/velocity.h"
#include "vldp_localization/localization.h"
#include "vldp_localization/localization_converter.h"

namespace vldp
{

class LocalizationNode
{

public:

    LocalizationNode();

    ~LocalizationNode() = default;

    bool Initialize();
    
private:
	

    bool LoadParameters();

    bool CreateROSInterfaces();



    /**
     * @brief Gazebo Ground Truth回调
     */
    void ModelStatesCallback(
        const gazebo_msgs::ModelStatesConstPtr& msg);

    /**
     * @brief VINS回调（Sprint3后续实现）
     */
    void VinsCallback(
        const nav_msgs::OdometryConstPtr& msg);
	
	 bool CreateTimer();

	void PublishTimerCallback(
	    const ros::TimerEvent&);
	    
 
private:

    ros::NodeHandle nh_;

    ros::NodeHandle private_nh_;

    ros::Subscriber gazebo_sub_;

    ros::Subscriber vins_sub_;

    ros::Publisher vision_pose_pub_;
    
    ros::Timer publish_timer_;

    std::unique_ptr<Localization> localization_;

    std::string gazebo_topic_;

    std::string vins_topic_;

    std::string vision_pose_topic_;

    double update_rate_;
    
    int vehicle_index_;
    
    LocalizationSource last_source_;
    
    std::string localization_frame_;
      
    };
    
}
