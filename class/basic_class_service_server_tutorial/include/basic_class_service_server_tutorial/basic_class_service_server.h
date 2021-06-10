#ifndef BASIC_CLASS_SERVICE_H
#define BASIC_CLASS_SERVICE_H

#include <ros/ros.h>
#include "basic_class_service_server_tutorial/Tutorial.h"

class BasicClassServiceServer
{
public:
    BasicClassServiceServer(ros::NodeHandle &n)
      : service_server_tutorial_command_(n.advertiseService("tutorial_command", &BasicClassServiceServer::TutorialCommandServiceCallback, this))
       {
          // open run
          ROS_INFO("basic_class_service_server_node Open");
       }
       ~BasicClassServiceServer()
       {
          // close run
          ROS_INFO("basic_class_service_server_node Close");
       }

    bool TutorialCommandServiceCallback(basic_class_service_server_tutorial::Tutorial::Request &req,
                      basic_class_service_server_tutorial::Tutorial::Response &res);
    void Spin();

private:
    ros::ServiceServer service_server_tutorial_command_;

};

#endif // BASIC_CLASS_SERVICE_H
