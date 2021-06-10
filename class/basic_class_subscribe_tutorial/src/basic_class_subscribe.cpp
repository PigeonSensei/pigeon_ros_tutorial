#include "basic_class_subscribe_tutorial/basic_class_subscribe.h"

void BasicClassSubscribe::CmdVelCallback(const geometry_msgs::Twist &cmd_vel)
{
  ROS_INFO("subscribd cmd_vel : linear.x = %.3f , angular.z = %.3f", cmd_vel.linear.x, cmd_vel.angular.z);
}

void BasicClassSubscribe::Spin()
{

}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "basic_class_subscribe");
  ros::NodeHandle n;

  ros::Rate loop_rate(60);

  BasicClassSubscribe basic_class_subscribe(n);
  while (ros::ok())
  {
    basic_class_subscribe.Spin();
    ros::spinOnce();
    loop_rate.sleep();
  }

}
