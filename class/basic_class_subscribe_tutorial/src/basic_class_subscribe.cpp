#include "basic_class_subscribe.h"

void Basic_class_subscribe::CmdVelCallback(const geometry_msgs::Twist &cmd_vel)
{
  ROS_INFO("subscribd cmd_vel : linear.x = %.3f , angular.z = %.3f", cmd_vel.linear.x, cmd_vel.angular.z);
}

bool Basic_class_subscribe::Update()
{
  return true;

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
  ros::init(argc, argv, "basic_class_subscribe");
  ros::NodeHandle n;

  ros::Rate loop_rate(60);

  Basic_class_subscribe basic_class_subscribe(n);
  while (ros::ok())
  {
    basic_class_subscribe.Update();
    loop_rate.sleep();
    ros::spinOnce();
    if(ReturnInputKey() == 27) break; // Press 'Esc' to exit
  }

}
