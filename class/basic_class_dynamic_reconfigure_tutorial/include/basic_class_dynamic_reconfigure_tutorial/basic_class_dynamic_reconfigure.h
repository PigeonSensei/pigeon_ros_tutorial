#ifndef BASIC_CLASS_DYNAMIC_RECONFIGURE_H
#define BASIC_CLASS_DYNAMIC_RECONFIGURE_H

#include <ros/ros.h>
#include "dynamic_reconfigure/server.h"
#include "tutorial_cfgs/TutorialCfgConfig.h"

class BasicClassDynamicReconfigure
{
public:
    BasicClassDynamicReconfigure(ros::NodeHandle &n)
       {
          // open run
          ROS_INFO("basic_class_dynamic_reconfigure_node Open");
          server_.setCallback(f_);
       }
       ~BasicClassDynamicReconfigure()
       {
          // close run
          ROS_INFO("basic_class_dynamic_reconfigure_node Close");
       }

    void DynamicReconfigureCallback(tutorial_cfgs::TutorialCfgConfig &config, uint32_t level);

    void PrintParameta();

    void Spin();

private:

    int dynamic_parameta_int_;
    double dynamic_parameta_double_;
    std::string dynamic_parameta_string_;
    bool dynamic_parameta_bool_;

    dynamic_reconfigure::Server<tutorial_cfgs::TutorialCfgConfig> server_;
    dynamic_reconfigure::Server<tutorial_cfgs::TutorialCfgConfig>::CallbackType f_ = boost::bind(&BasicClassDynamicReconfigure::DynamicReconfigureCallback, this, _1, _2);

};

#endif // BASIC_CLASS_DYNAMIC_RECONFIGURE_H
