# vldp_msgs

## 简介

vldp_msgs 是 VLDP-Drone 项目的 ROS 消息定义功能包。

该功能包负责定义 ROS 节点之间通信使用的数据格式。

---

## 设计原则

vldp_msgs 只负责：

- ROS Message 定义

不包含：

- 算法
- 控制逻辑
- 数据处理

---

## 当前消息

### ControlCommand

无人机速度控制指令。

字段：

|字段|说明|
|-|-|
|vx|X方向速度|
|vy|Y方向速度|
|vz|Z方向速度|
|yaw_rate|偏航角速度|
|valid|数据有效标志|

---

## 数据关系

