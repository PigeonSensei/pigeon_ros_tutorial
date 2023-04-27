#ifndef BASIC_CLASS_PUBLISH_SUBSCRIBE_H
#define BASIC_CLASS_PUBLISH_SUBSCRIBE_H

#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <nav_msgs/Odometry.h>
#include <tf/transform_broadcaster.h>
#include <tf/tf.h>


class BasicClassPubilshSubscribe
{
public:
    BasicClassPubilshSubscribe(ros::NodeHandle &n)
      : subscriber_cmd_vel_(n.subscribe("cmd_vel", 100, &BasicClassPubilshSubscribe::CmdVelCallback, this)),
        publisher_odom_(n.advertise<nav_msgs::Odometry>("odom",1000))

       {
          // open run
          ROS_INFO("basic_class_publish_subscribe_node Open");
       }
       ~BasicClassPubilshSubscribe()
       {
          // close run
          ROS_INFO("basic_class_publish_subscribe_node Close");
       }

    void CmdVelCallback(const geometry_msgs::Twist::ConstPtr& cmd_vel);

    void UpdateOdom();

    void SetOdomTF();

    void Publisher();

    void Spin();

private:

    struct CmdVel
    {
      double linear_x = 0;
      double linear_y = 0;
      double linear_z = 0;
      double angular_x = 0;
      double angular_y = 0;
      double angular_z = 0;
    };

    nav_msgs::Odometry odom_;
    tf::TransformBroadcaster odom_broadcaster_;
    ros::Subscriber subscriber_cmd_vel_;
    ros::Publisher publisher_odom_;
    CmdVel Scmd_vel_;

    ros::Time time_now_;
    unsigned int seq_count_ = 0;

};

#endif // BASIC_CLASS_PUBLISH_SUBSCRIBE_H
