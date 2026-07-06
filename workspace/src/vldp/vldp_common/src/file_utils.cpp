#include "vldp_common/file_utils.h"

#include <filesystem>

namespace fs = std::filesystem;

namespace vldp
{

bool FileUtils::Exists(const std::string& path)
{
    return fs::exists(path);
}

bool FileUtils::DirectoryExists(const std::string& path)
{
    return fs::exists(path) && fs::is_directory(path);
}

bool FileUtils::CreateDirectory(const std::string& path)
{
    return fs::create_directories(path);
}

bool FileUtils::Remove(const std::string& path)
{
    return fs::remove(path);
}

std::string FileUtils::Extension(const std::string& path)
{
    return fs::path(path).extension().string();
}

std::string FileUtils::Filename(const std::string& path)
{
    return fs::path(path).filename().string();
}

std::string FileUtils::Parent(const std::string& path)
{
    return fs::path(path).parent_path().string();
}

}