#include <ros/ros.h>
#include "tutorial_srvs/TutorialSrv.h"

int main(int argc, char **argv)
{
  ros::init(argc, argv, "basic_service_client_node");
  ros::NodeHandle n;

  ROS_INFO("basic_service_client_node Open");

  ros::ServiceClient service_client_tutorial_command = n.serviceClient<tutorial_srvs::TutorialSrv>("tutorial_command");
  basic_service_server_tutorial::Tutorial tutorial_command;

  tutorial_command.request.command = "tutorial 1";

  service_client_tutorial_command.call((tutorial_command));

  ROS_INFO("rosservice call /tutorial_command command: 'tutorial 1'");

  ROS_INFO("basic_service_client_node Close");

  return 0;

}
