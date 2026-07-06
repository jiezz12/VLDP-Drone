#include "vldp_common/config.h"

#include "vldp_common/logger.h"

namespace vldp
{

bool Config::loaded_ = false;

bool Config::Load(const std::string& file)
{
    Log::Info("加载配置文件：" + file);

    loaded_ = true;
    
    return true;
}

bool Config::IsLoaded()
{
    return loaded_;
}

}