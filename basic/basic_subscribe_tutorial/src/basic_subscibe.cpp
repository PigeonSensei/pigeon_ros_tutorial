#include <ros/ros.h>
#include <geometry_msgs/Twist.h>

void CmdVelCallback(const geometry_msgs::Twist &cmd_vel)
{
  ROS_INFO("subscribd cmd_vel : linear.x = %.3f , angular.z = %.3f", cmd_vel.linear.x, cmd_vel.angular.z);
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "basic_subscibe_node");
  ros::NodeHandle n;

  ROS_INFO("basic_subscibe_node Open");

  ros::Subscriber subscriber_cmd_vel;
  subscriber_cmd_vel = n.subscribe("cmd_vel", 1000, CmdVelCallback);

  ros::Rate loop_rate(60);

  while (ros::ok())
  {
    ros::spinOnce();
    loop_rate.sleep();
  }

  ROS_INFO("basic_subscibe_node Close");

  return 0;
}
