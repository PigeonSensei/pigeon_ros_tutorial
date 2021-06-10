#include <ros/ros.h>
#include "basic_service_server_tutorial/Tutorial.h"

bool TutorialCommandServiceCallback(basic_service_server_tutorial::Tutorial::Request &req,
                                    basic_service_server_tutorial::Tutorial::Response &res)
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

int main(int argc, char **argv)
{
  ros::init(argc, argv, "basic_service_server_node");
  ros::NodeHandle n;

  ROS_INFO("basic_service_server_node Open");

  ros::ServiceServer service_server;
  service_server = n.advertiseService("tutorial_command", TutorialCommandServiceCallback);

  ros::Rate loop_rate(60);

  while (ros::ok())
  {
    ros::spinOnce();
    loop_rate.sleep();
  }

  ROS_INFO("basic_service_server_node Close");

  return 0;


}
