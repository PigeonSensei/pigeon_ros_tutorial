#ifndef BASIC_CLASS_SERVICE_H
#define BASIC_CLASS_SERVICE_H

#include <ros/ros.h>
#include "basic_class_service_tutorial/Tutorial.h"

#include <termios.h>
#include <unistd.h>

class Basic_class_service
{
public:
    Basic_class_service(ros::NodeHandle &n)
      : service_server_(n.advertiseService("tutorial_command", &Basic_class_service::TutorialCommandServiceCallback, this))
       {
          // open run
          ROS_INFO("basic_class_service_node Open");
       }
       ~Basic_class_service()
       {
          // close run
          ROS_INFO("basic_class_service_nocd Close");
       }

    bool TutorialCommandServiceCallback(basic_class_service_tutorial::Tutorial::Request &req,
                      basic_class_service_tutorial::Tutorial::Response &res);
    bool Update();

private:
    ros::ServiceServer service_server_;

};

#endif // BASIC_CLASS_SERVICE_H
