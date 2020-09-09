#ifndef PIGEON_SUB_H
#define PIGEON_SUB_H

#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <nav_msgs/Odometry.h>

#include <termios.h>
#include <unistd.h>

class Pigeon_sub
{
public:
    Pigeon_sub(ros::NodeHandle &n)
           : sub(n.subscribe("cmd_vel", 100, &Pigeon_sub::cmd_vel_sub, this)),
             pub(n.advertise<nav_msgs::Odometry>("odom",1000))
       {
          // open run
          ROS_INFO("PIGEON_SUB_NODE OPNE");
       }
       ~Pigeon_sub()
       {
          // close run
          ROS_INFO("PIGEON_SUB_NODE CLOSE");
       }

    int input_return_key();

    void cmd_vel_sub(const geometry_msgs::Twist &cmd_vel);

    void update();

    void spin();

private:
    ros::Subscriber sub;
    ros::Publisher pub;

    nav_msgs::Odometry odom_pub;
    geometry_msgs::Twist cmd_vel_pub;


};


#endif // PIGEON_SUB_H
