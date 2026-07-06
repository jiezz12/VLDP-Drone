#include "vldp_common/timer.h"

namespace vldp
{

Timer::Timer()
{
    Reset();
}

void Timer::Reset()
{
    start_time_ = std::chrono::steady_clock::now();
}

double Timer::Elapsed() const
{
    auto now = std::chrono::steady_clock::now();

    return std::chrono::duration<double>(now - start_time_).count();
}

double Timer::Restart()
{
    double elapsed = Elapsed();

    Reset();
    
    return elapsed;
}

}