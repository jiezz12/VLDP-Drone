# Sprint 1 开发记录

---

## Sprint目标

完成 VLDP-Drone 基础软件框架搭建。

建立统一的数据结构、模块划分及开发规范。

---

## 完成内容

### vldp_common

完成：

- Logger
- Config
- Timer
- FileUtils
- Time
- Macros

---

### vldp_core

完成：

- Pose
- Velocity
- Observation
- ControlCommand

建立统一数据模型。

---

### vldp_platform

完成：

- Camera Topic订阅
- Gazebo双目相机验证
- Camera FPS统计

---

### vldp_controller

完成：

- Controller
- ControllerNode
- 控制循环
- 参数读取

---

## Gazebo验证

完成：

- Gazebo启动

- 相机Topic订阅成功

- 图像接收正常

- FPS统计正常

---

## 当前工程状态

所有功能包：

- 编译通过

- 独立运行正常

---

## Sprint总结

Sprint1 完成了整个项目的软件框架搭建。

当前系统已经具备：

Platform

↓

Observation

↓

Controller

的数据流。

下一阶段将完成 PX4 Bridge，使无人机真正实现闭环控制。

---

## 下一阶段（Sprint2）

目标：

建立 Gazebo 控制闭环。

包括：

- vldp_px4_bridge

- MAVROS

- Velocity Control

- Gazebo飞行验证
