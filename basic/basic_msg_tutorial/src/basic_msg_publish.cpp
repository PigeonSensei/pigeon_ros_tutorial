#include <ros/ros.h>
#include "tutorial_msgs/TutorialMsg.h"

int main(int argc, char **argv)
{
  ros::init(argc, argv, "basic_msg_publish_node");

  ROS_INFO("basic_msg_publish_node Open");
  ros::NodeHandle n;

  tutorial_msgs::TutorialMsg tutorial_msg;
  ros::Publisher publisher_tutorial_msg = n.advertise<tutorial_msgs::TutorialMsg>("tutorial_msg", 1000);

  ros::Rate loop_rate(60);

  while (ros::ok())
  {
    tutorial_msg.Bool = true;
    tutorial_msg.Int8 = 127;
    tutorial_msg.UInt8 = 255;
    tutorial_msg.Int16 = 32767;
    tutorial_msg.UInt16 = 65535;
    tutorial_msg.Int32 = 2147483647;
    tutorial_msg.UInt32 = 4294967295;
    tutorial_msg.Int64 = 9223372036854775807LL;
    tutorial_msg.UInt64 = 18446744073709551615ULL;
    tutorial_msg.Float32 = 123.456f;
    tutorial_msg.Float64 = 123.456;
    tutorial_msg.String = "Tutorial";
    tutorial_msg.Time = ros::Time::now();
    tutorial_msg.Duration = ros::Duration(5.0);

    publisher_tutorial_msg.publish(tutorial_msg);

    ros::spinOnce();
    loop_rate.sleep();
  }

  ROS_INFO("basic_msg_publish_node Close");

  return 0;
}
