#include "vldp_platform/platform_node.h"

#include "vldp_common/logger.h"

#include <sstream>

namespace vldp
{

PlatformNode::PlatformNode(ros::NodeHandle& nh)
    : nh_(nh)
    
    , it_(nh_)
{

}

bool PlatformNode::Initialize()
{
      image_sub_ = it_.subscribe(
        "/iris/stereo_camera/left/image_raw",
        1,
        &PlatformNode::ImageCallback,
        this);

    status_timer_ = nh_.createTimer(
        ros::Duration(1.0),
        &PlatformNode::StatusTimerCallback,
        this);

    Log::Info("Platform 初始化完成");
    Log::Info("Camera Subscriber 建立");

    return true;
}

void PlatformNode::ImageCallback(
    const sensor_msgs::ImageConstPtr& msg)
{
    try
    {
    /*
        latest_image_ = cv_bridge::toCvCopy(

            msg,

            sensor_msgs::image_encodings::BGR8

        )->image;
*/
	latest_image_ = cv_bridge::toCvShare(msg, msg->encoding)->image.clone();
	
	last_image_time_=ros::Time::now();
	
        image_count_++;

	image_counter_++;

    }
    catch(const cv_bridge::Exception& e)
    {
        Log::Error(e.what());
    }
}

bool PlatformNode::IsCameraOnline() const
{
    if(last_image_time_.isZero())
    {
        return false;
    }

    return
        (ros::Time::now()-last_image_time_).toSec()
        <
        camera_timeout_;
}

void PlatformNode::PrintStatus()
{
    std::stringstream ss;

    ss << "\n========== VLDP Platform ==========\n";

/*
    ss << "Camera : ";

    if(IsCameraOnline())
    {
        ss << "OK";
    }
    else
    {
        ss << "Waiting";
    }

    ss << "\n";
*/
    ss << "Camera : " << (IsCameraOnline() ? "OK" : "Waiting");

    Log::Info(ss.str());
}

void PlatformNode::StatusTimerCallback(
    const ros::TimerEvent&)
{
    bool online = IsCameraOnline();

    if(online != camera_online_)
    {
        camera_online_ = online;

        if(camera_online_)
        {
            Log::Info("Camera Connected");
        }
        else
        {
            Log::Warn("Camera Lost");
        }
        
    }

    camera_fps_ = static_cast<double>(image_counter_);

    image_counter_ = 0;

    status_tick_++;
	if (camera_online_ && status_tick_ % 5 == 0)
	{
	    std::ostringstream ss;
	    ss << "Camera FPS: " << camera_fps_;
	    Log::Info(ss.str());
	}
}

} // namespace vldp
