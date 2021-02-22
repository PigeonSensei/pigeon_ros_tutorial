#include "basic_class_client.h"

bool Basic_class_client::TutorialCommandServiceCall()
{
  tutorial_command_.request.command = "tutorial 1";

  service_client_tutorial_command_.call(tutorial_command_);

  ROS_INFO("rosservice call /tutorial_command command: 'tutorial 1'");

  return true;
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "basic_class_client_node");
  ros::NodeHandle n;

  Basic_class_client basic_class_client(n);

  basic_class_client.TutorialCommandServiceCall();

  return 0;
}
