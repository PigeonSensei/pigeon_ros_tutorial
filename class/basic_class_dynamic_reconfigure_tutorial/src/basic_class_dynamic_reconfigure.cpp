#include "basic_class_dynamic_reconfigure_tutorial/basic_class_dynamic_reconfigure.h"

void BasicClassDynamicReconfigure::callback(basic_class_dynamic_reconfigure_tutorial::TutorialConfig &config, uint32_t level)
{
  dynamic_parameta_int_ = config.param_int;
  dynamic_parameta_double_ = config.param_double;
  dynamic_parameta_string_ = config.param_string;
  dynamic_parameta_bool_ = config.param_bool;
}

void BasicClassDynamicReconfigure::PrintParameta()
{
  ROS_INFO("Dynamic Param Int : %d", dynamic_parameta_int_);
  ROS_INFO("Dynamic Param Double : %f", dynamic_parameta_double_);
  ROS_INFO("Dynamic Param String : %s", dynamic_parameta_string_.c_str());
  if(dynamic_parameta_bool_ == true) ROS_INFO("Dynamic Param Bool : true");
  else if (dynamic_parameta_bool_ != true) ROS_INFO("Dynamic Param Bool : false");
  std::cout << std::endl;
}

void BasicClassDynamicReconfigure::Spin()
{
  PrintParameta();
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "basic_class_dynamic_reconfigure_node");
  ros::NodeHandle n;

  ros::Rate loop_rate(60);

  BasicClassDynamicReconfigure basic_class_dynamic_reconfigure(n);

  while (ros::ok())
  {
    basic_class_dynamic_reconfigure.Spin();
    ros::spinOnce();
    loop_rate.sleep();
  }

}
