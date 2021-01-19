#ifndef BASIC_CLASS_MSG_H
#define BASIC_CLASS_MSG_H

#include <ros/ros.h>
#include "basic_class_msg_tutorial/TutorialMsg.h"

#include <termios.h>
#include <unistd.h>

class Basic_class_msg
{
public:
    Basic_class_msg(ros::NodeHandle &n)
      : publisher_tutorial_msg_(n.advertise<basic_class_msg_tutorial::TutorialMsg>("tutorial_msg",1000))
       {
          // open run
          ROS_INFO("basic_class_msg_node Open");
       }
       ~Basic_class_msg()
       {
          // close run
          ROS_INFO("basic_class_msg_node Close");
       }

    int ReturnInputKey();

    bool UpdateTutorialMsg();

    bool Publisher();

    bool Update();

private:
    basic_class_msg_tutorial::TutorialMsg tutorial_msg_;
    ros::Publisher publisher_tutorial_msg_;


};

#endif // BASIC_CLASS_MSG_H
