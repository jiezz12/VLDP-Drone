#pragma once

namespace vldp
{

enum class Status
{
    SUCCESS = 0,

    FAILED,

    TIMEOUT,

    INVALID_PARAMETER,

    NOT_INITIALIZED,

    RUNNING
};

}