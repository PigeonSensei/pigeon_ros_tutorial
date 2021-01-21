#include <ros/ros.h>
#include "basic_msg_tutorial/TutorialMsg.h"

#include <termios.h>
#include <unistd.h>

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
  ros::init(argc, argv, "basic_msg_node");

  ROS_INFO("basic_msg_node Open");
  ros::NodeHandle n;

  basic_msg_tutorial::TutorialMsg tutorial_msg;
  ros::Publisher publisher_tutorial_msg = n.advertise<basic_msg_tutorial::TutorialMsg>("tutorial_msg", 1000);

  ros::Rate loop_rate(60);

  while (ros::ok())
  {

    tutorial_msg.A = true;
    tutorial_msg.B = -1;
    tutorial_msg.C = 1;
    tutorial_msg.D = -2;
    tutorial_msg.E = 2;
    tutorial_msg.F = -3;
    tutorial_msg.G = 3;
    tutorial_msg.H = -4;
    tutorial_msg.I = 4;
    tutorial_msg.J = -5.5;
    tutorial_msg.K = -6.6;
    tutorial_msg.L = "Tutorial";
    tutorial_msg.M = ros::Time::now();
    tutorial_msg.N = ros::Duration(5, 1);

    publisher_tutorial_msg.publish(tutorial_msg);

    ros::spinOnce();
    loop_rate.sleep();
    if(ReturnInputKey() == 27) break; // Press 'Esc' to exit
  }

  ROS_INFO("basic_msg_node Close");

  return 0;
}
