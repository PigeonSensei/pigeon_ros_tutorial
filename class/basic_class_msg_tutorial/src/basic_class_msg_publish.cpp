#include "basic_class_msg_tutorial/basic_class_msg_publish.h"

void BasicClassMsgPublish::UpdateTutorialMsg()
{
  tutorial_msg_.Bool = true;
  tutorial_msg_.Int8 = 127;
  tutorial_msg_.UInt8 = 255;
  tutorial_msg_.Int16 = 32767;
  tutorial_msg_.UInt16 = 65535;
  tutorial_msg_.Int32 = 2147483647;
  tutorial_msg_.UInt32 = 4294967295;
  tutorial_msg_.Int64 = 9223372036854775807LL;
  tutorial_msg_.UInt64 = 18446744073709551615ULL;
  tutorial_msg_.Float32 = 123.456f;
  tutorial_msg_.Float64 = 123.456;
  tutorial_msg_.String = "Tutorial";
  tutorial_msg_.Time = ros::Time::now();
  tutorial_msg_.Duration = ros::Duration(5.0);

}

void BasicClassMsgPublish::Publisher()
{
  publisher_tutorial_msg_.publish(tutorial_msg_);
}

void BasicClassMsgPublish::Spin()
{
  UpdateTutorialMsg();
  Publisher();
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "basic_class_msg_publish_node");
  ros::NodeHandle n;

  ros::Rate loop_rate(60);

  BasicClassMsgPublish basic_class_msg_publish(n);
  while (ros::ok())
  {
    basic_class_msg_publish.Spin();
    ros::spinOnce();
    loop_rate.sleep();
  }

  return 0;
}
