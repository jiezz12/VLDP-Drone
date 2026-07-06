#pragma once

/**
 * @file logger.h
 * @brief 日志系统
 *
 * 负责整个 VLDP-Drone 的日志输出。
 * 当前版本基于 ROS Console 实现，
 * 后续可无缝切换到 spdlog。
 */

#include <string>

namespace vldp
{

class Log
{
public:

    /**
     * @brief 初始化日志系统
     */
    static void Initialize();

    /**
     * @brief 输出调试信息
     */
    static void Debug(const std::string& message);

    /**
     * @brief 输出普通信息
     */
    static void Info(const std::string& message);

    /**
     * @brief 输出警告
     */
    static void Warn(const std::string& message);

    /**
     * @brief 输出错误
     */
    static void Error(const std::string& message);

};

}