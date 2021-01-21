#include "basic_class_publish.h"

bool Basic_class_pubilsh::UpdateCmdVel()
{
  cmd_vel_.linear.x = 10;
  cmd_vel_.angular.z = 10;

  return true;
}

bool Basic_class_pubilsh::Publisher()
{
  publisher_cmd_vel_.publish(cmd_vel_);
  return true;
}

bool Basic_class_pubilsh::Update()
{
  UpdateCmdVel();
  Publisher();
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
  ros::init(argc, argv, "basic_class_publish_node");
  ros::NodeHandle n;

  ros::Rate loop_rate(60);

  Basic_class_pubilsh basic_class_publish(n);
  while (ros::ok())
  {
    basic_class_publish.Update();
    loop_rate.sleep();
    ros::spinOnce();
    if(ReturnInputKey() == 27) break; // Press 'Esc' to exit
  }

  return 0;

}
