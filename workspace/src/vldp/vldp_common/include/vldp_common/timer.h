#pragma once

/**
 * @file timer.h
 * @brief 程序计时器
 */

#include <chrono>

namespace vldp
{

class Timer
{
public:

    Timer();

    /**
     * @brief 开始计时
     */
    void Reset();

    /**
     * @brief 获取耗时（秒）
     */
    double Elapsed() const;

    /**
     * @brief 返回耗时并重新开始计时
     */
    double Restart();

private:

    std::chrono::steady_clock::time_point start_time_;

};

}