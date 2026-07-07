# vldp_controller

## 功能介绍

vldp_controller 负责无人机控制层。

当前版本（Sprint1）实现：

- Controller 类
- ControllerNode
- 20Hz 控制循环
- 参数加载
- 日志输出

## 功能结构

Controller
│
├── Initialize()
└── Update()

ControllerNode
│
├── LoadParameters()
├── CreateTimer()
└── ControlTimerCallback()

## 依赖

- ROS Noetic
- roscpp
- vldp_common

## 编译

catkin_make

## 运行

rosrun vldp_controller vldp_controller_node

## 下一步开发计划

Sprint2：

- 接入 vldp_px4
- 发布控制命令


