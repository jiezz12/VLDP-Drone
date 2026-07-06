#pragma once
#include <memory>

namespace vldp {

template<typename T>
using Ptr = std::shared_ptr<T>;

template<typename T>
using ConstPtr = std::shared_ptr<const T>;

using TimeStamp = double;

enum class SystemState {
    INIT,
    READY,
    RUNNING,
    ERROR
};

enum class FlightMode {
    MANUAL,
    OFFBOARD,
    AUTO
};

}