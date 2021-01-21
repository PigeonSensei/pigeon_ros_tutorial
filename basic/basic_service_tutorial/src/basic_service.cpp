#include <ros/ros.h>
#include "basic_service_tutorial/Tutorial.h"

#include <termios.h>
#include <unistd.h>

bool TutorialCommandServiceCallback(basic_service_tutorial::Tutorial::Request &req,
                                    basic_service_tutorial::Tutorial::Response &res)
{
  if(req.command == "tutorial 1")
  {
      ROS_INFO("Receive Service call tutorial command : tutorial 1");
      res.message = "Receive success";
      res.result = "true";
  }
  else if(req.command == "tutorial 2")
  {
      ROS_INFO("Receive Service call tutorial command : tutorial 2");
      res.message = "Receive success";
      res.result = "true";
  }

  else
  {
    ROS_INFO("Receive Service call tutorial command : non");
    res.message = "Receive fall";
    res.result = "false";
  }

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
  ros::init(argc, argv, "basic_service_node");
  ros::NodeHandle n;

  ROS_INFO("basic_service_node Open");

  ros::ServiceServer service_server;
  service_server = n.advertiseService("tutorial_command", TutorialCommandServiceCallback);

  ros::Rate loop_rate(60);

  while (ros::ok())
  {
    ros::spinOnce();
    loop_rate.sleep();
    if(ReturnInputKey() == 27) break; // Press 'Esc' to exit
  }

  ROS_INFO("basic_service_node Close");

  return 0;


}
