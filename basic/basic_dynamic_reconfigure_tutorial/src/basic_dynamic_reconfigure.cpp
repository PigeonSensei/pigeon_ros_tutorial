#include <ros/ros.h>
#include "dynamic_reconfigure/server.h"
#include "basic_dynamic_reconfigure_tutorial/TutorialConfig.h"

void callback(basic_dynamic_reconfigure_tutorial::TutorialConfig &config, uint32_t level)
{
  ROS_INFO("Dynamic Param Int : %d", config.param_int);
  ROS_INFO("Dynamic Param Double : %f", config.param_double);
  ROS_INFO("Dynamic Param String : %s", config.param_string.c_str());
  if(config.param_bool == true) ROS_INFO("Dynamic Param Bool : true");
  else if (config.param_bool != true) ROS_INFO("Dynamic Param Bool : false");
  std::cout << std::endl;
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "basic_dynamic_reconfigure_node");
  ros::NodeHandle n;

  ros::Rate loop_rate(60);

  ROS_INFO("basic_dynamic_reconfigure_node Open");

  dynamic_reconfigure::Server<basic_dynamic_reconfigure_tutorial::TutorialConfig> server;
  dynamic_reconfigure::Server<basic_dynamic_reconfigure_tutorial::TutorialConfig>::CallbackType f;

  f = boost::bind(&callback, _1, _2);
  server.setCallback(f);

  while (ros::ok())
  {
    ros::spinOnce();
    loop_rate.sleep();
  }

  ROS_INFO("basic_dynamic_reconfigure_node Close");


}
