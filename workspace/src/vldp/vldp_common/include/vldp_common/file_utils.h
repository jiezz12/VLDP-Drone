#pragma once

/**
 * @file file_utils.h
 * @brief 文件工具类
 *
 * 提供统一的文件及目录操作接口。
 */

#include <string>
#include <vector>

namespace vldp
{

class FileUtils
{
public:

    /**
     * @brief 判断文件是否存在
     *
     * @param path 文件路径
     * @return true 文件存在
     */
    static bool Exists(const std::string& path);

    /**
     * @brief 判断目录是否存在
     */
    static bool DirectoryExists(const std::string& path);

    /**
     * @brief 创建目录（递归）
     */
    static bool CreateDirectory(const std::string& path);

    /**
     * @brief 删除文件
     */
    static bool Remove(const std::string& path);

    /**
     * @brief 获取文件扩展名
     */
    static std::string Extension(const std::string& path);

    /**
     * @brief 获取文件名
     */
    static std::string Filename(const std::string& path);

    /**
     * @brief 获取父目录
     */
    static std::string Parent(const std::string& path);

};

}