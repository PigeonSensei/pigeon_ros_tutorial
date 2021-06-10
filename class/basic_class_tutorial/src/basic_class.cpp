#include "basic_class_tutorial/basic_class.h"

void BasicClass::Spin()
{
  ROS_INFO("Hello world!");
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "basic_class_node");
  ros::NodeHandle n;

  ros::Rate loop_rate(60);

  BasicClass basic_class(n);

  while (ros::ok())
  {
    basic_class.Spin();
    ros::spinOnce();
    loop_rate.sleep();
  }

  return 0;

}
