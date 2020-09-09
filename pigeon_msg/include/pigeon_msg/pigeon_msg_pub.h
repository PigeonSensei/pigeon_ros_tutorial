#ifndef PIGEON_MSG_PUB_H
#define PIGEON_MSG_PUB_H

#include <ros/ros.h>
#include <pigeon_msg/tutorial.h> //MSG
#include <termios.h>
class Pigeon_msg_pub
{
public:
    Pigeon_msg_pub(ros::NodeHandle &n)
           : pub(n.advertise<pigeon_msg::tutorial>("pigeon_msg",10)) // MSG
//             sub(n.subscribe("pigeon_msg", 100, &Pigeon_msg_sub::msg_sub, this))
       {
          // open run
          ROS_INFO("PIGEON_MSG_PUB_NODE OPNE");
       }
       ~Pigeon_msg_pub()
       {
          // close run
          ROS_INFO("PIGEON_MSG_PUB_NODE CLOSE");
       }

//    void msg_sub(const pigeon_msg::tutorial)

    int keybord_input();

    void update();

    void spin();

private:
    ros::Publisher pub;
    pigeon_msg::tutorial pigeon_msg_pub;

};

#endif // PIGEON_MSG_PUB_H
