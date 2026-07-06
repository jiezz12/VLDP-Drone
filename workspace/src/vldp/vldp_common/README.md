# vldp_common

## 一、功能介绍

`vldp_common` 是 **VLDP-Drone** 框架的基础公共库（Common Library），属于整个系统的最底层模块。

该功能包提供整个项目通用的基础设施，包括：

- 基础类型定义（Types）
- 日志系统（Logger）
- 配置管理（Config）
- 时间统计（Timer）
- 单例模板（Singleton）
- 状态码定义（Status）
- 异常处理（Exception）
- 版本管理（Version）

本功能包**不包含任何无人机算法**，也**不依赖具体硬件设备**，仅负责提供整个工程的公共基础能力。

---

## 二、设计原则

本模块遵循以下设计原则：

- 与具体业务解耦
- 不依赖 PX4
- 不依赖 MAVROS
- 不依赖 VINS-Fusion
- 不依赖相机
- 尽量减少 ROS 依赖（后续逐步实现纯 C++）

所有上层模块均可直接依赖 `vldp_common`。

---

## 三、目录结构

```text
vldp_common
│
├── include/
│   └── vldp_common/
│       ├── config.h          # 配置管理
│       ├── exception.h       # 异常定义
│       ├── logger.h          # 日志系统
│       ├── singleton.h       # 单例模板
│       ├── status.h          # 状态码定义
│       ├── timer.h           # 计时器
│       ├── types.h           # 基础类型
│       └── version.h         # 版本信息
│
├── src/
│   ├── config.cpp
│   ├── logger.cpp
│   └── timer.cpp
│
├── config/
│
├── test/
│
├── CMakeLists.txt
├── package.xml
└── README.md
```

---

## 四、模块说明

### 1. Types

定义整个工程统一的数据类型。

例如：

- 智能指针别名
- 时间戳
- 飞行模式
- 系统状态

所有 Package 均使用统一的数据类型。

---

### 2. Logger

日志输出模块。

负责统一整个工程日志格式。

后续计划支持：

- ROS Console
- 文件日志
- 彩色终端输出
- 日志等级过滤

---

### 3. Config

配置管理模块。

后续采用 `yaml-cpp` 读取 YAML 配置文件。

计划支持：

- int
- double
- bool
- string
- vector

统一配置接口。

---

### 4. Timer

程序计时器。

主要用于：

- 算法耗时统计
- 控制周期统计
- Profiling
- Benchmark

---

### 5. Singleton

单例模板。

用于：

- Config
- Logger

等全局对象。

---

### 6. Status

统一状态码。

所有公共接口推荐返回：

```cpp
Status
```

而不是：

```cpp
bool
```

方便后续错误定位。

---

### 7. Exception

统一异常类型。

便于整个工程异常管理。

---

### 8. Version

统一维护：

- 主版本号
- 次版本号
- Patch版本号

便于 Release 管理。

---

## 五、依赖关系

当前依赖：

- ROS Noetic
- roscpp
- C++17

后续计划增加：

- yaml-cpp
- Eigen3

---

## 六、被哪些模块使用

整个 VLDP-Drone 都依赖本模块。

```text
vldp_common
        │
        ├────────────┐
        │            │
        ▼            ▼
vldp_msgs      vldp_core
        │            │
        └──────┬─────┘
               ▼
      所有其它 Package
```

因此：

**vldp_common 是整个框架唯一的基础公共库。**

---

## 七、编译方式

编译：

```bash
catkin build vldp_common
```

运行：

```bash
rosrun vldp_common test_common
```

测试内容：

- Logger
- Timer
- Time
- FileUtils
- Config

---

## 八、后续计划

Sprint2：

- yaml-cpp
- Profiler
- 文件日志

Sprint3：

- Benchmark
- 参数服务器
- 配置热更新

---

## 九、开发规范

本模块遵循以下规范：

- C++17
- Google C++ Style
- UTF-8 编码
- 中文注释
- Doxygen 风格接口注释
- 一个类对应一个头文件
- 一个类对应一个源文件

---

## 十、版本信息

当前版本：

```
v0.1.0-alpha
```

所属项目：

```
VLDP-Drone
```

开发团队：

```
VLDP-Drone Project
```

版权所有：

```
Copyright © 2026 VLDP-Drone
```