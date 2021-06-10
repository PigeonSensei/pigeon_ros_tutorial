#include <ros/ros.h>
#include "basic_msg_tutorial/TutorialMsg.h"

int main(int argc, char **argv)
{
  ros::init(argc, argv, "basic_msg_node");

  ROS_INFO("basic_msg_node Open");
  ros::NodeHandle n;

  basic_msg_tutorial::TutorialMsg tutorial_msg;
  ros::Publisher publisher_tutorial_msg = n.advertise<basic_msg_tutorial::TutorialMsg>("tutorial_msg", 1000);

  ros::Rate loop_rate(60);

  while (ros::ok())
  {
    tutorial_msg.Bool = true;
    tutorial_msg.Int8 = -1;
    tutorial_msg.UInt8 = 1;
    tutorial_msg.Int16 = -2;
    tutorial_msg.UInt16 = 2;
    tutorial_msg.Int32 = -3;
    tutorial_msg.UInt32 = 3;
    tutorial_msg.Int64 = -4;
    tutorial_msg.UInt64 = 4;
    tutorial_msg.Float32 = -5.5;
    tutorial_msg.Float64 = -6.6;
    tutorial_msg.String = "Tutorial";
    tutorial_msg.Time = ros::Time::now();
    tutorial_msg.Duration = ros::Duration(5, 1);

    publisher_tutorial_msg.publish(tutorial_msg);

    ros::spinOnce();
    loop_rate.sleep();
  }

  ROS_INFO("basic_msg_node Close");

  return 0;
}
