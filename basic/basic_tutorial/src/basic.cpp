#include <ros/ros.h>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "basic_node");
  ros::NodeHandle n;

  ROS_INFO("Hello world!");

  return 0;
}
