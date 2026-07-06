#pragma once

/**
 * @file time.h
 * @brief 时间工具类
 */

#include <cstdint>
#include <string>

namespace vldp
{

class Time
{
public:

    /**
     * @brief 当前Unix时间（秒）
     */
    static double Now();

    /**
     * @brief 当前Unix时间（毫秒）
     */
    static uint64_t NowMilliseconds();

    /**
     * @brief 当前Unix时间（微秒）
     */
    static uint64_t NowMicroseconds();

    /**
     * @brief 获取当前时间字符串
     *
     * 格式：
     * YYYY-MM-DD HH:MM:SS
     */
    static std::string NowString();

};

}