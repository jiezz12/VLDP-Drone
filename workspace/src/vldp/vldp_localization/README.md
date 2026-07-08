# vldp_localization

## 功能简介

`vldp_localization` 是 **Vision-Language Differentiable Physics Drone（VLDP）** 的统一状态估计模块。

本模块负责接收来自各种定位算法或定位设备的状态信息，进行统一管理，并向飞控系统（PX4）和 VLDP 平台提供一致的无人机位姿信息。

> **注意：**
>
> `vldp_localization` **不负责运行任何定位算法**（例如 VINS-Fusion、OpenVINS、ORB-SLAM3 等），仅负责统一接入、管理和发布定位结果。

---

# 功能定位

本模块位于 VLDP 系统中的状态估计层，负责连接定位算法、飞控系统以及平台层。

```
            Localization Source
      (VINS / GPS / Gazebo / RTK ...)
                    │
                    ▼
          vldp_localization
              │          │
              │          │
              ▼          ▼
     PX4 Vision Pose   Platform
```

其主要职责包括：

* 接收外部定位结果；
* 管理统一的无人机位姿状态；
* 发布 PX4 Vision Pose；
* 为 Platform 提供统一状态信息；
* 监测定位状态是否正常。

---

# 设计原则

为了保证整个 VLDP 架构长期稳定，本模块遵循以下设计原则。

## 1. 单一职责（Single Responsibility）

本模块只负责统一状态估计管理。

不负责：

* 图像处理；
* 控制算法；
* 路径规划；
* VLM 推理。

---

## 2. 不实现定位算法

定位算法属于外部模块，例如：

* VINS-Fusion
* OpenVINS
* ORB-SLAM3
* Motion Capture
* GPS / RTK

本模块仅负责接收其输出结果。

---

## 3. 统一状态来源（Single Source of Truth）

整个 VLDP 系统始终维护一份统一状态。

所有控制、规划和决策均基于该状态进行。

避免多个模块维护不同的位置估计。

---

## 4. PX4 优先（PX4 First）

定位结果将同步发送给 PX4。

利用 PX4 EKF2/EKF3 完成状态融合，提高飞行稳定性和安全性。

---

## 软件架构

当前模块内部结构如下：

```
LocalizationNode
        │
        ▼
 Localization
        │
        ▼
 Unified State
```

其中：

**LocalizationNode**

负责：

* ROS Topic
* Publisher
* Subscriber
* Timer

**Localization**

负责：

* 状态管理
* 数据更新
* 数据有效性检查
* 对外提供统一状态

---

# 当前规划支持的定位来源

目前计划支持以下定位来源：

| 来源                  | 状态   |
| ------------------- | ---- |
| Gazebo Ground Truth | ✔    |
| VINS-Fusion         | ✔    |
| OpenVINS            | 计划支持 |
| ORB-SLAM3           | 计划支持 |
| Motion Capture      | 计划支持 |
| GPS                 | 计划支持 |
| RTK                 | 计划支持 |

---

# 输入

后续将支持订阅以下 Topic：

| Topic         | 类型                | 说明        |
| ------------- | ----------------- | --------- |
| Ground Truth  | nav_msgs/Odometry | Gazebo 真值 |
| VINS Odometry | nav_msgs/Odometry | VINS 输出   |
| GPS           | 待定                | GPS 数据    |

---

# 输出

本模块将统一输出：

| Topic               | 类型                        | 说明           |
| ------------------- | ------------------------- | ------------ |
| PX4 Vision Pose     | geometry_msgs/PoseStamped | 提供给 PX4 EKF  |
| Unified Observation | 后续定义                      | 提供给 Platform |

---

# 当前开发进度

## Sprint3

### Phase1

* [ ] 创建功能包
* [ ] 完成 CMakeLists
* [ ] 完成 package.xml
* [ ] 完成 Localization 类
* [ ] 完成 LocalizationNode

### Phase2

* [ ] 接入 Gazebo Ground Truth
* [ ] 发布 PX4 Vision Pose
* [ ] Gazebo 验证

### Phase3

* [ ] 接入 VINS-Fusion
* [ ] 输出统一状态
* [ ] 状态有效性检测

---

# 后续规划

未来本模块将继续扩展以下能力：

* 多定位源切换；
* 定位状态监测；
* 时间同步；
* 坐标系转换（TF）；
* 状态缓存；
* 统一 Observation 输出。

---

# 与其它模块关系

```
Camera
   │
   ▼
vldp_platform

Localization Source
   │
   ▼
vldp_localization
   │
   ├────────► PX4
   │
   └────────► Platform
                   │
                   ▼
            vldp_controller
                   │
                   ▼
            vldp_px4_bridge
                   │
                   ▼
                  PX4
```

---

# 开发规范

本模块遵循 VLDP 工程统一开发规范：

* C++17
* ROS Noetic
* Controller 不依赖 ROS
* Node 负责 ROS 通信
* Localization 不依赖具体定位算法
* 统一状态管理
* 中文代码注释
* 每完成一个 Sprint 更新文档与版本记录

