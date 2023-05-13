#include "basic_class_msg_tutorial/basic_class_msg_subscribe.h"

void BasicClassMsgSubscribe::TutorialMsgCallback(const tutorial_msgs::TutorialMsg::ConstPtr& tutorial_msg)
{
  ROS_INFO("tutorial_msg.Bool = %s", tutorial_msg->Bool ? "true" : "false");
  ROS_INFO("tutorial_msg.Int8 = %d", tutorial_msg->Int8);
  ROS_INFO("tutorial_msg.UInt8 = %u", tutorial_msg->UInt8);
  ROS_INFO("tutorial_msg.Int16 = %d", tutorial_msg->Int16);
  ROS_INFO("tutorial_msg.UInt16 = %u", tutorial_msg->UInt16);
  ROS_INFO("tutorial_msg.Int32 = %d", tutorial_msg->Int32);
  ROS_INFO("tutorial_msg.UInt32 = %lu", (unsigned long)tutorial_msg->UInt32);
  ROS_INFO("tutorial_msg.Int64 = %lld", (long long int)tutorial_msg->Int64);
  ROS_INFO("tutorial_msg.UIn64 = %llu", (unsigned long long int)tutorial_msg->UInt64);
  ROS_INFO("tutorial_msg.Float32 = %.2f", tutorial_msg->Float32);
  ROS_INFO("tutorial_msg.Float64 = %.2lf", tutorial_msg->Float64);
  ROS_INFO("tutorial_msg.String = %s", tutorial_msg->String.c_str());
  ROS_INFO("tutorial_msg.Time = %f", tutorial_msg->Time.toSec());
  ROS_INFO("tutorial_msg.Duration = %f", tutorial_msg->Duration.toSec());
}

void BasicClassMsgSubscribe::Spin()
{

}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "basic_class_msg_subscribe");
  ros::NodeHandle n;

  ros::Rate loop_rate(60);

  BasicClassMsgSubscribe basic_class_msg_subscribe(n);

  while (ros::ok())
  {
    basic_class_msg_subscribe.Spin();
    ros::spinOnce();
    loop_rate.sleep();
  }

}
