#pragma once

/**
 * @file platform_node.h
 * @brief VLDP Platform节点
 */

#include <ros/ros.h>
#include <image_transport/image_transport.h>
#include <sensor_msgs/Image.h>
#include <cv_bridge/cv_bridge.h>

#include <opencv2/opencv.hpp>

namespace vldp
{

class PlatformNode
{
public:

    explicit PlatformNode(ros::NodeHandle& nh);

    ~PlatformNode() = default;

    /**
     * @brief 初始化节点
     * @return true 成功
     * @return false 失败
     */
    bool Initialize();

private:

  /*-------------------------------
     * ROS
     *------------------------------*/
    ros::NodeHandle nh_;

    image_transport::ImageTransport it_;

    image_transport::Subscriber image_sub_;

    ros::Timer status_timer_;

    /*-------------------------------
     * Camera
     *------------------------------*/
    cv::Mat latest_image_;

    uint64_t image_count_{0};

	/* 最近一次收到图像的时间 */
	ros::Time last_image_time_;

	/* 在线状态 */
	bool camera_online_{false};

	/* 每秒统计 */
	uint32_t image_counter_{0};

	double camera_fps_{0.0};

        uint32_t status_tick_{0};

	/* 超时时间 */
	double camera_timeout_{2.0};

    /*-------------------------------
     * Callback
     *------------------------------*/
    void ImageCallback(
        const sensor_msgs::ImageConstPtr& msg);

    void StatusTimerCallback(
        const ros::TimerEvent& event);

    /*-------------------------------
     * Status
     *------------------------------*/
    bool IsCameraOnline() const;

    void PrintStatus();
};

} // namespace vldp
