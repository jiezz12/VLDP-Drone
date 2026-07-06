#include "vldp_common/time.h"

#include <chrono>
#include <ctime>
#include <iomanip>
#include <sstream>

namespace vldp
{

double Time::Now()
{
    auto now = std::chrono::system_clock::now();

    return std::chrono::duration<double>(
        now.time_since_epoch()).count();
}

uint64_t Time::NowMilliseconds()
{
    auto now = std::chrono::system_clock::now();

    return std::chrono::duration_cast<
        std::chrono::milliseconds>(
        now.time_since_epoch()).count();
}

uint64_t Time::NowMicroseconds()
{
    auto now = std::chrono::system_clock::now();

    return std::chrono::duration_cast<
        std::chrono::microseconds>(
        now.time_since_epoch()).count();
}

std::string Time::NowString()
{
    auto now = std::chrono::system_clock::now();

    auto t = std::chrono::system_clock::to_time_t(now);
    
    std::stringstream ss;
    
    ss << std::put_time(std::localtime(&t),
                        "%Y-%m-%d %H:%M:%S");
    
    return ss.str();
}

}