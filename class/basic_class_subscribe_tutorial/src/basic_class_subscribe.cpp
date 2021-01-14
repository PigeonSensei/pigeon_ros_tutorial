#include "basic_class_subscribe.h"

void Basic_class_subscribe::CmdVelCallback(const geometry_msgs::Twist &cmd_vel)
{
  ROS_INFO("subscribd cmd_vel : linear.x = %.3f , angular.z = %.3f", cmd_vel.linear.x, cmd_vel.angular.z);
}

bool Basic_class_subscribe::Update()
{
  return true;

}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "basic_class_subscribe");
  ros::NodeHandle n;

  ros::Rate loop_rate(60);

  Basic_class_subscribe basic_class_subscribe(n);
  while (ros::ok())
  {
    basic_class_subscribe.Update();
    loop_rate.sleep();
    ros::spinOnce();
//    if(basic_class.ReturnInputKey() == 27) break;
  }

}
