#ifndef BASIC_CLASS_PUBLISH_SUBSCRIBE_H
#define BASIC_CLASS_PUBLISH_SUBSCRIBE_H

#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <nav_msgs/Odometry.h>
#include <tf/transform_broadcaster.h>
#include <tf/tf.h>

#include <termios.h>
#include <unistd.h>

struct CmdVel
{
  double linear_x = 0;
  double linear_y = 0;
  double linear_z = 0;
  double angular_x = 0;
  double angular_y = 0;
  double angular_z = 0;
};

class Basic_class_pubilsh_subscribe
{
public:
    Basic_class_pubilsh_subscribe(ros::NodeHandle &n)
      : subscriber_cmd_vel_(n.subscribe("cmd_vel", 100, &Basic_class_pubilsh_subscribe::CmdVelCallback, this)),
        publisher_odom_(n.advertise<nav_msgs::Odometry>("odom",1000))

       {
          // open run
          ROS_INFO("basic_class_publish_subscribe_node Open");
       }
       ~Basic_class_pubilsh_subscribe()
       {
          // close run
          ROS_INFO("basic_class_publish_subscribe_node Close");
       }

    int ReturnInputKey();

    void CmdVelCallback(const geometry_msgs::Twist &cmd_vel);

    bool UpdateOdom();

    bool SetOdomTF();

    bool Publisher();

    bool Update();

private:
    nav_msgs::Odometry odom_;
    tf::TransformBroadcaster odom_broadcaster;
    ros::Subscriber subscriber_cmd_vel_;
    ros::Publisher publisher_odom_;
    CmdVel Scmd_vel_;

    ros::Time time_now;
    unsigned int seq_count = 0;

};

#endif // BASIC_CLASS_PUBLISH_SUBSCRIBE_H
