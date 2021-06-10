#ifndef BASIC_CLASS_H
#define BASIC_CLASS_H

#include <ros/ros.h>

class BasicClass
{
public:
    BasicClass(ros::NodeHandle &n)
       {
          // open run
          ROS_INFO("basic_class_node Open");
       }
       ~BasicClass()
       {
          // close run
          ROS_INFO("basic_class_node Close");
       }

    void Spin();

private:

};

#endif // BASIC_CLASS_H
