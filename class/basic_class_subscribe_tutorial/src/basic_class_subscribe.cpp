#include <ros/ros.h>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "basic_class_subscribe");
  ros::NodeHandle nh;

  ROS_INFO("Hello world!");
}
