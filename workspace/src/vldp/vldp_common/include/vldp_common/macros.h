#pragma once

/**
 * @file macros.h
 * @brief VLDP-Drone公共宏定义
 */

/// 禁止拷贝
#define VLDP_DISABLE_COPY(Class)         \
    Class(const Class&) = delete;        \
    Class& operator=(const Class&) = delete;

/// 禁止移动
#define VLDP_DISABLE_MOVE(Class)         \
    Class(Class&&) = delete;             \
    Class& operator=(Class&&) = delete;

/// 禁止拷贝和移动
#define VLDP_DISABLE_COPY_MOVE(Class)    \
    VLDP_DISABLE_COPY(Class)             \
    VLDP_DISABLE_MOVE(Class)

/// 忽略未使用变量
#define VLDP_UNUSED(x) (void)(x)

/// 版本号
#define VLDP_VERSION_MAJOR 0
#define VLDP_VERSION_MINOR 1
#define VLDP_VERSION_PATCH 0