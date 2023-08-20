#ifndef BASIC_CLASS_DYNAMIC_RECONFIGURE_H
#define BASIC_CLASS_DYNAMIC_RECONFIGURE_H

#include <ros/ros.h>
#include "dynamic_reconfigure/server.h"
#include "basic_class_dynamic_reconfigure_tutorial/TutorialConfig.h"

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

    void DynamicReconfigureCallback(basic_class_dynamic_reconfigure_tutorial::TutorialConfig &config, uint32_t level);

    void PrintParameta();

    void Spin();

private:

    int dynamic_parameta_int_;
    double dynamic_parameta_double_;
    std::string dynamic_parameta_string_;
    bool dynamic_parameta_bool_;

    dynamic_reconfigure::Server<basic_class_dynamic_reconfigure_tutorial::TutorialConfig> server_;
    dynamic_reconfigure::Server<basic_class_dynamic_reconfigure_tutorial::TutorialConfig>::CallbackType f_ = boost::bind(&BasicClassDynamicReconfigure::DynamicReconfigureCallback, this, _1, _2);

};

#endif // BASIC_CLASS_DYNAMIC_RECONFIGURE_H
