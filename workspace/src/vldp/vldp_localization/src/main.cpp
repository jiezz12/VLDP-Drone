#include "vldp_localization/localization_node.h"


int main(
    int argc,
    char** argv)
{
    ros::init(
        argc,
        argv,
        "vldp_localization");

    vldp::LocalizationNode node;

    
    if (!node.Initialize())
    {
        return -1;
    }

    ros::spin();

    return 0;
}
