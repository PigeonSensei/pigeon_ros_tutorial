#ifndef PIGEON_PUB_H
#define PIGEON_PUB_H

#include <ros/ros.h>
#include <geometry_msgs/Twist.h>

#include <termios.h>

struct CMD_VEL
{
  double linear_x = 0;
  double angular_z = 0;
};

class Pigeon_pub
{
public:
    Pigeon_pub(ros::NodeHandle &n)
           : pub(n.advertise<geometry_msgs::Twist>("cmd_vel",10)) // MSG
       {
          // open run
          ROS_INFO("PIGEON_PUB_NODE OPNE");
       }
       ~Pigeon_pub()
       {
          // close run
          ROS_INFO("PIGEON_PUB_NODE CLOSE");
       }

    int input_return_key();

    void update();

    void spin();

private:
    ros::Publisher pub;
    geometry_msgs::Twist cmd_vel_pub;

    CMD_VEL data_name_1;

};


#endif // PIGEON_PUB_H
