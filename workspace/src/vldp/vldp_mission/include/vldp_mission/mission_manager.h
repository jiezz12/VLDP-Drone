class MissionManager
{
public:

    bool Initialize();

    void SetMissionGoal(
        const MissionGoal& goal);

    MissionGoal GetMissionGoal() const;

    bool HasMissionGoal() const;

    void ClearMissionGoal();

private:

    MissionGoal mission_goal_;

    bool has_goal_;
};
