#ifndef PIGEON_MSG_SUB_H
#define PIGEON_MSG_SUB_H

#include <ros/ros.h>
//#include <pigeon_msg/tutorial.h> //MSG
#include "pigeon_msg/tutorial.h"
#include <termios.h>

class Pigeon_msg_sub
{
public:
    Pigeon_msg_sub(ros::NodeHandle &n)
           : sub(n.subscribe("pigeon_msg", 100, &Pigeon_msg_sub::msg_sub, this)), // MSG
             loop_Rate(120)
       {
          // open run
          ROS_INFO("PIGEON_MSG_SUB_NODE OPNE");
       }
       ~Pigeon_msg_sub()
       {
          // close run
          ROS_INFO("PIGEON_MSG_SUB_NODE CLOSE");
       }

    void msg_sub(const pigeon_msg::tutorial &msg);

    int keybord_input();

    void update();

    void spin();

private:
    ros::Subscriber sub;
    ros::Rate loop_Rate;
//    pigeon_msg::tutorial pigeon_msg_pub;

};

#endif // PIGEON_MSG_SUB_H
