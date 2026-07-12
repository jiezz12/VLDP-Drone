# vldp_mission

## 简介

vldp_mission 是 VLDP-Drone 的任务管理模块。

Mission 层位于 Localization 与 Controller 之间。

负责维护当前任务目标（Goal）。

Mission 不直接控制 PX4。

Mission 不依赖 MAVROS。

Controller 根据 Mission 提供的目标完成控制。

---

## 当前功能

- 保存目标点
- 查询目标点
- 清除目标点

---

## 后续计划

Sprint4：

- Takeoff
- Land
- Hover
- GoTo

Sprint5：

- Planner

Sprint6：

- Vision Language Navigation

Sprint7：

- Multi Mission
