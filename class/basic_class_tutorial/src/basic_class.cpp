#include "basic_class.h"

bool Basic_class::Update()
{
  ROS_INFO("Hello world!");
  return true;
}

int ReturnInputKey()
{

}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "basic_class_node");
  ros::NodeHandle n;

  ros::Rate loop_rate(60);

  Basic_class basic_class(n);

  while (ros::ok())
  {
    basic_class.Update();
    loop_rate.sleep();
    ros::spinOnce();
//    if(basic_class.ReturnInputKey() == 27) break;
  }

  return 0;

}
