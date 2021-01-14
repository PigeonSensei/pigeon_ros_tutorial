#ifndef BASIC_CLASS_PUBLISH_H
#define BASIC_CLASS_PUBLISH_H

#include <ros/ros.h>
#include <geometry_msgs/Twist.h>

#include <termios.h>
#include <unistd.h>
class Basic_class_pubilsh
{
public:
    Basic_class_pubilsh(ros::NodeHandle &n)
      : publisher_cmd_vel_(n.advertise<geometry_msgs::Twist>("cmd_vel",1000))
       {
          // open run
          ROS_INFO("Basic_class_pubilsh_node Open");
       }
       ~Basic_class_pubilsh()
       {
          // close run
          ROS_INFO("Basic_class_pubilsh_node Close");
       }

    int ReturnInputKey();

    bool UpdateCmdVel();

    bool Publisher();

    bool Update();

private:
    geometry_msgs::Twist cmd_vel_;
    ros::Publisher publisher_cmd_vel_;

};

#endif // BASIC_CLASS_PUBLISH_H
