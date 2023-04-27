#ifndef BASIC_CLASS_SUBSCRIBE_H
#define BASIC_CLASS_SUBSCRIBE_H
#include <ros/ros.h>
#include <geometry_msgs/Twist.h>

class BasicClassSubscribe
{
public:
    BasicClassSubscribe(ros::NodeHandle &n)
      : subscriber_cmd_vel_(n.subscribe("cmd_vel", 100, &BasicClassSubscribe::CmdVelCallback, this))
       {
          // open run
          ROS_INFO("Basic_class_subscribe_node Open");
       }
       ~BasicClassSubscribe()
       {
          // close run
          ROS_INFO("Basic_class_subscribe_node Close");
       }

    void CmdVelCallback(const geometry_msgs::Twist::ConstPtr& cmd_vel);

    void Spin();

private:
    ros::Subscriber subscriber_cmd_vel_;

};

#endif // BASIC_CLASS_SUBSCRIBE_H
