

enum class MissionType
{
    NONE = 0,

    TAKEOFF,

    GOTO,

    LAND,

    HOVER
};

enum class MissionState
{
    IDLE = 0,

    RUNNING,

    FINISHED,

    FAILED
};

struct MissionGoal
{
    MissionType type = MissionType::NONE;

    Pose target_pose;

    double position_tolerance = 0.2;

    double yaw_tolerance = 0.2;
};
