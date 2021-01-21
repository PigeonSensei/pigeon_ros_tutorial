#ifndef BASIC_CLASS_H
#define BASIC_CLASS_H

#include <ros/ros.h>

#include <termios.h>
#include <unistd.h>

class Basic_class
{
public:
    Basic_class(ros::NodeHandle &n)
       {
          // open run
          ROS_INFO("basic_class_node Open");
       }
       ~Basic_class()
       {
          // close run
          ROS_INFO("basic_class_node Close");
       }

    bool Update();

private:

};

#endif // BASIC_CLASS_H
