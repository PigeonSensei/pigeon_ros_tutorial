#ifndef BASIC_CLASS_MSG_H
#define BASIC_CLASS_MSG_H

#include <ros/ros.h>
#include "basic_class_msg_tutorial/TutorialMsg.h"

class BasicClassMsg
{
public:
    BasicClassMsg(ros::NodeHandle &n)
      : publisher_tutorial_msg_(n.advertise<basic_class_msg_tutorial::TutorialMsg>("tutorial_msg",1000))
       {
          // open run
          ROS_INFO("basic_class_msg_node Open");
       }
       ~BasicClassMsg()
       {
          // close run
          ROS_INFO("basic_class_msg_node Close");
       }

    void UpdateTutorialMsg();

    void Publisher();

    void Spin();

private:
    basic_class_msg_tutorial::TutorialMsg tutorial_msg_;
    ros::Publisher publisher_tutorial_msg_;


};

#endif // BASIC_CLASS_MSG_H
