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
//    if(basic_class.ReturnInputKey() == 27) break;
  }
}
