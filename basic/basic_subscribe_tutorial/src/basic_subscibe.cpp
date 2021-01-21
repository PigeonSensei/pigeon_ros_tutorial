#include <ros/ros.h>
#include <geometry_msgs/Twist.h>

#include <termios.h>
#include <unistd.h>

void CmdVelCallback(const geometry_msgs::Twist &cmd_vel)
{
  ROS_INFO("subscribd cmd_vel : linear.x = %.3f , angular.z = %.3f", cmd_vel.linear.x, cmd_vel.angular.z);
}

int ReturnInputKey()
{
  struct termios org_term;

  char input_key = 0;

  tcgetattr(STDIN_FILENO, &org_term);

  struct termios new_term = org_term;

  new_term.c_lflag &= ~(ECHO | ICANON);

  new_term.c_cc[VMIN] = 0;
  new_term.c_cc[VTIME] = 0;

  tcsetattr(STDIN_FILENO, TCSANOW, &new_term);

  read(STDIN_FILENO, &input_key, 1);

  tcsetattr(STDIN_FILENO, TCSANOW, &org_term);

  return input_key;
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "basic_subscibe_node");
  ros::NodeHandle n;

  ROS_INFO("basic_subscibe_node Open");

  ros::Subscriber subscriber_cmd_vel_;
  subscriber_cmd_vel_ = n.subscribe("cmd_vel", 1000, CmdVelCallback);

  ros::Rate loop_rate(60);

  while (ros::ok())
  {
    ros::spinOnce();
    loop_rate.sleep();
    if(ReturnInputKey() == 27) break; // Press 'Esc' to exit
  }

  ROS_INFO("basic_subscibe_node Close");

  return 0;
}
