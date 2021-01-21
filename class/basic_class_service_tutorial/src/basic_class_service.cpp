#include "basic_class_service.h"

bool Basic_class_service::TutorialCommandServiceCallback(basic_class_service_tutorial::Tutorial::Request &req, basic_class_service_tutorial::Tutorial::Response &res)
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

bool Basic_class_service::Update()
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
  ros::init(argc, argv, "basic_class_service_node");
  ros::NodeHandle n;



  ros::Rate loop_rate(60);
  ROS_INFO("IN");

  Basic_class_service basic_class_service(n);

  while (ros::ok())
  {

    basic_class_service.Update();
    loop_rate.sleep();
    ros::spinOnce();
    if(ReturnInputKey() == 27) break;
  }
}
