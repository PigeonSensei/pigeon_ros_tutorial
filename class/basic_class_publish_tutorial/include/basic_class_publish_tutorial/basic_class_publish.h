#ifndef BASIC_CLASS_PUBLISH_H
#define BASIC_CLASS_PUBLISH_H

#include <ros/ros.h>
#include <geometry_msgs/Twist.h>

class BasicClassPubilsh
{
public:
    BasicClassPubilsh(ros::NodeHandle &n)
      : publisher_cmd_vel_(n.advertise<geometry_msgs::Twist>("cmd_vel",1000))
       {
          // open run
          ROS_INFO("Basic_class_pubilsh_node Open");
       }
       ~BasicClassPubilsh()
       {
          // close run
          ROS_INFO("Basic_class_pubilsh_node Close");
       }

    void UpdateCmdVel();

    void Publisher();

    void Spin();

private:
    geometry_msgs::Twist cmd_vel_;
    ros::Publisher publisher_cmd_vel_;

};

#endif // BASIC_CLASS_PUBLISH_H
