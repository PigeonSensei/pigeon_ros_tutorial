#include "basic_class_service_server_tutorial/basic_class_service_server.h"

bool BasicClassServiceServer::TutorialCommandServiceCallback(basic_class_service_server_tutorial::Tutorial::Request &req, basic_class_service_server_tutorial::Tutorial::Response &res)
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

void BasicClassServiceServer::Spin()
{

}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "basic_class_service_server_node");
  ros::NodeHandle n;

  ros::Rate loop_rate(60);

  BasicClassServiceServer basic_class_service_server(n);

  while (ros::ok())
  {

    basic_class_service_server.Spin();
    ros::spinOnce();
    loop_rate.sleep();
  }
}
