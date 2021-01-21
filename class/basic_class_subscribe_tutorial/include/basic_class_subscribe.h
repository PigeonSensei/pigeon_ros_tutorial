#ifndef BASIC_CLASS_SUBSCRIBE_H
#define BASIC_CLASS_SUBSCRIBE_H
#include <ros/ros.h>
#include <geometry_msgs/Twist.h>

#include <termios.h>
#include <unistd.h>

class Basic_class_subscribe
{
public:
    Basic_class_subscribe(ros::NodeHandle &n)
      : subscriber_cmd_vel_(n.subscribe("cmd_vel", 100, &Basic_class_subscribe::CmdVelCallback, this))
       {
          // open run
          ROS_INFO("Basic_class_subscribe_node Open");
       }
       ~Basic_class_subscribe()
       {
          // close run
          ROS_INFO("Basic_class_subscribe_node Close");
       }

    void CmdVelCallback(const geometry_msgs::Twist &cmd_vel);

    bool Update();

private:
    ros::Subscriber subscriber_cmd_vel_;

};

#endif // BASIC_CLASS_SUBSCRIBE_H
