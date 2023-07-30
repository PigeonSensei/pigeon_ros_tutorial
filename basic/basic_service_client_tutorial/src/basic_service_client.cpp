#include <ros/ros.h>
#include "tutorial_srvs/TutorialSrv.h"

int main(int argc, char **argv)
{
  ros::init(argc, argv, "basic_service_client_node");
  ros::NodeHandle n;

  ROS_INFO("basic_service_client_node Open");

  ros::ServiceClient service_client_tutorial_command;
  service_client_tutorial_command = n.serviceClient<tutorial_srvs::TutorialSrv>("tutorial_command");

  tutorial_srvs::TutorialSrv tutorial_command;

  tutorial_command.request.command = "tutorial 1";

  service_client_tutorial_command.call(tutorial_command);

  ROS_INFO("rosservice call /tutorial_command command : '%s'", tutorial_command.request.command.c_str());

  ROS_INFO("Service Call Response result : %s", tutorial_command.response.result.c_str());

  ROS_INFO("Service Call Response message : %s", tutorial_command.response.message.c_str());

  ROS_INFO("basic_service_client_node Close");

  return 0;

}
