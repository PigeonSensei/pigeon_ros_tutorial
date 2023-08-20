#include <ros/ros.h>
#include "dynamic_reconfigure/server.h"
#include "tutorial_cfgs/TutorialCfgConfig.h"

void DynamicReconfigureCallback(tutorial_cfgs::TutorialCfgConfig &config, uint32_t level)
{
  ROS_INFO("Dynamic Param Int : %d", config.param_int);
  ROS_INFO("Dynamic Param Double : %f", config.param_double);
  ROS_INFO("Dynamic Param String : %s", config.param_string.c_str());
  if(config.param_bool == true) ROS_INFO("Dynamic Param Bool : true");
  else if (config.param_bool != true) ROS_INFO("Dynamic Param Bool : false");
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "basic_dynamic_reconfigure_node");
  ros::NodeHandle n;

  ros::Rate loop_rate(60);

  ROS_INFO("basic_dynamic_reconfigure_node Open");

  dynamic_reconfigure::Server<tutorial_cfgs::TutorialCfgConfig> server;
  dynamic_reconfigure::Server<tutorial_cfgs::TutorialCfgConfig>::CallbackType f;

  f = boost::bind(&DynamicReconfigureCallback, _1, _2);
  server.setCallback(f);

  while (ros::ok())
  {
    ros::spinOnce();
    loop_rate.sleep();
  }

  ROS_INFO("basic_dynamic_reconfigure_node Close");

  return 0;

}
