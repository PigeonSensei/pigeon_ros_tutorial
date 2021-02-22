#ifndef BASIC_CLASS_CLIENT_H
#define BASIC_CLASS_CLIENT_H

#include <ros/ros.h>

#include <termios.h>
#include <unistd.h>

#include "basic_class_service_server_tutorial/Tutorial.h"

class Basic_class_client
{
public:
    Basic_class_client(ros::NodeHandle &n)
      : service_client_tutorial_command_(n.serviceClient<basic_class_service_server_tutorial::Tutorial>("tutorial_command"))
       {
          // open run
          ROS_INFO("basic_class_client_node Open");
       }
       ~Basic_class_client()
       {
          // close run
          ROS_INFO("basic_class_client_node Close");
       }

    bool Update();

    bool TutorialCommandServiceCall();

private:
    ros::ServiceClient service_client_tutorial_command_;

    basic_class_service_server_tutorial::Tutorial tutorial_command_;



};


#endif // BASIC_CLASS_CLIENT_H
