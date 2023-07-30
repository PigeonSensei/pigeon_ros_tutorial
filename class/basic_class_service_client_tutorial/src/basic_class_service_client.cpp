#include "basic_class_service_client_tutorial/basic_class_client.h"

bool BasicClassClient::TutorialCommandServiceCall()
{
  tutorial_command_.request.command = "tutorial 1";

  service_client_tutorial_command_.call(tutorial_command_);

  ROS_INFO("rosservice call /tutorial_command command: '%s'", tutorial_command_.request.command.c_str());

  ROS_INFO("Service Call Response result : %s", tutorial_command_.response.result.c_str());

  ROS_INFO("Service Call Response message : %s", tutorial_command_.response.message.c_str());

  return true;
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "basic_class_service_client_node");
  ros::NodeHandle n;

  BasicClassClient basic_class_client(n);

  basic_class_client.TutorialCommandServiceCall();

  return 0;
}
