# VLDP-Drone

> 基于视觉-语言可微物理无人机系统(Vision-Language Differentiable Physics Drone)

---

## 项目简介

VLDP-Drone（Vision-Language Differentiable Physics Drone）
是一个面向智能无人机自主飞行研究的开源项目。

项目探索视觉-语言模型、可微物理模型与无人机自主控制的结合，
通过构建模块化的软件框架，实现从环境感知、状态理解、
任务规划到飞行控制的完整闭环。

---

## 系统特点

- 模块化架构设计
- ROS 与算法解耦
- 统一数据结构（vldp_core）
- 面向 Gazebo 与 PX4 双平台
- 支持后续接入 VLA、Diffusion Policy 等模型
- 全中文文档与代码注释

---

## 软件架构

ROS工程结构

## 当前开发进度

### Sprint 1（已完成）

- ✅ vldp_common
- ✅ vldp_core
- ✅ vldp_platform
- ✅ vldp_controller

当前已完成基础软件框架搭建。

---

## 项目结构

```text
VLDP-Drone
│
├── docs/
│
├── workspace/
│   └── src/
│       └── vldp/
│           ├── vldp_common
│           ├── vldp_core
│           ├── vldp_platform
│           ├── vldp_controller
│           └── vldp_px4_bridge（开发中）
│
├── README.md
└── LICENSE
```

---

## 软件架构

详细架构请参考：

```
docs/architecture.md
```

---

## 开发路线

| Sprint | 内容 | 状态 |
|---------|------|------|
| Sprint1 | 基础框架 | ✅ |
| Sprint2 | PX4 Bridge + Gazebo闭环 | 🚧 |
| Sprint3 | Policy接口 | ⏳ |
| Sprint4 | VLA接入 | ⏳ |

---

## 开发环境

Ubuntu 20.04

ROS Noetic

Gazebo 11

PX4

MAVROS

OpenCV

Eigen3

---

## 编译

```bash
cd workspace

catkin_make
```

---

## 运行

各功能包均可独立启动，例如：

```bash
rosrun vldp_platform vldp_platform_node

rosrun vldp_controller vldp_controller_node
```

---

## 文档

```
docs/
```

包含：

- 系统架构
- Sprint开发记录
- 编码规范（持续完善）

---

## 开发原则

本项目遵循以下原则：

- 先完成闭环，再增加功能
- 不进行过度设计
- Node 负责 ROS，Core 负责算法
- Core 不依赖 ROS
- 每完成一个 Sprint 必须完成验证

---

## 开源协议

MIT License
