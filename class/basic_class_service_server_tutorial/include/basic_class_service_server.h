#ifndef BASIC_CLASS_SERVICE_H
#define BASIC_CLASS_SERVICE_H

#include <ros/ros.h>
#include "basic_class_service_server_tutorial/Tutorial.h"

#include <termios.h>
#include <unistd.h>

class Basic_class_service_server
{
public:
    Basic_class_service_server(ros::NodeHandle &n)
      : service_server_(n.advertiseService("tutorial_command", &Basic_class_service_server::TutorialCommandServiceCallback, this))
       {
          // open run
          ROS_INFO("basic_class_service_server_node Open");
       }
       ~Basic_class_service_server()
       {
          // close run
          ROS_INFO("basic_class_service_server_node Close");
       }

    bool TutorialCommandServiceCallback(basic_class_service_server_tutorial::Tutorial::Request &req,
                      basic_class_service_server_tutorial::Tutorial::Response &res);
    bool Update();

private:
    ros::ServiceServer service_server_;

};

#endif // BASIC_CLASS_SERVICE_H
