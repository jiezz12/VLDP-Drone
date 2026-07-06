#pragma once

/**
 * @file config.h
 * @brief 配置文件管理
 */

#include <string>

namespace vldp
{

class Config
{
public:

    /**
     * @brief 加载配置文件
     *
     * @param file 配置文件路径
     *
     * @return 是否加载成功
     */
    static bool Load(const std::string& file);

    /**
     * @brief 判断配置是否已加载
     */
    static bool IsLoaded();

private:

    static bool loaded_;

};

}