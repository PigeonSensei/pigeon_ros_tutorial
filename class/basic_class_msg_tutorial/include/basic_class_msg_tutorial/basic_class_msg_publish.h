#ifndef BASIC_CLASS_MSG_PUBLISH_H
#define BASIC_CLASS_MSG_PUBLISH_H

#include <ros/ros.h>
#include "tutorial_msgs/TutorialMsg.h"

class BasicClassMsgPublish
{
public:
    BasicClassMsgPublish(ros::NodeHandle &n)
      : publisher_tutorial_msg_(n.advertise<tutorial_msgs::TutorialMsg>("tutorial_msg",1000))
       {
          // open run
          ROS_INFO("basic_class_msg_publish_node Open");
       }
       ~BasicClassMsgPublish()
       {
          // close run
          ROS_INFO("basic_class_msg_publish_node Close");
       }

    void UpdateTutorialMsg();

    void Publisher();

    void Spin();

private:
    tutorial_msgs::TutorialMsg tutorial_msg_;
    ros::Publisher publisher_tutorial_msg_;


};

#endif // BASIC_CLASS_MSG_PUBLISH_H
