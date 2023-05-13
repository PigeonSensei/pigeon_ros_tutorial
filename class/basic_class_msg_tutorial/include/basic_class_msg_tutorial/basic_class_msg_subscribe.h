#ifndef BASIC_CLASS_MSG_SUBSCRIBE_H
#define BASIC_CLASS_MSG_SUBSCRIBE_H

#include <ros/ros.h>
#include "tutorial_msgs/TutorialMsg.h"

class BasicClassMsgSubscribe
{
public:
    BasicClassMsgSubscribe(ros::NodeHandle &n)
      : subscriber_tutorial_msg_(n.subscribe("tutorial_msg", 100, &BasicClassMsgSubscribe::TutorialMsgCallback, this))
       {
          // open run
          ROS_INFO("Basic_class_msg_subscribe_node Open");
       }
       ~BasicClassMsgSubscribe()
       {
          // close run
          ROS_INFO("Basic_class_msg_subscribe_node Close");
       }

    void TutorialMsgCallback(const tutorial_msgs::TutorialMsg::ConstPtr& tutorial_msg);

    void Spin();

private:
    ros::Subscriber subscriber_tutorial_msg_;

};

#endif // BASIC_CLASS_MSG_SUBSCRIBE_H
