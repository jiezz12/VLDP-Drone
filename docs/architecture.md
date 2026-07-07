# VLDP-Drone 系统总体架构

---

## 整体架构

```text
                 Camera
                 IMU
                VINS
                  │
                  ▼
          vldp_platform
                  │
                  ▼
            Observation
                  │
                  ▼
             vldp_policy
                  │
                  ▼
         ControlCommand
                  │
                  ▼
          vldp_controller
                  │
                  ▼
          vldp_px4_bridge
                  │
                  ▼
             PX4 / Gazebo
```

---

## 功能包说明

### vldp_common

公共工具库。

负责：

- 日志
- 配置读取
- 文件工具
- 时间工具
- 宏定义

---

### vldp_core

共享数据结构。

包括：

- Pose
- Velocity
- Observation
- ControlCommand

整个工程唯一的数据模型。

---

### vldp_platform

平台层。

负责：

- Camera
- IMU
- VINS
- 数据同步

生成 Observation。

---

### vldp_controller

控制层。

负责：

- 控制循环
- 控制逻辑
- 输出 ControlCommand

不直接操作 ROS Topic。

---

### vldp_px4_bridge

飞控桥接层。

负责：

- 接收 ControlCommand
- 发布 MAVROS 控制命令
- 接收 PX4 状态

---

### vldp_policy（后续）

策略层。

负责：

- VLM
- VLA
- Diffusion Policy
- 强化学习

输出统一的 ControlCommand。

---

## 数据流

```text
Platform

↓

Observation

↓

Policy

↓

ControlCommand

↓

Controller

↓

PX4 Bridge

↓

PX4
```

---

## 分层原则

Node：

负责 ROS。

Core：

负责算法。

Core：

不依赖 ROS。

所有共享数据均放在 vldp_core。
