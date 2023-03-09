#include "basic_class_msg_tutorial/basic_class_msg.h"

void BasicClassMsg::UpdateTutorialMsg()
{
  tutorial_msg_.Bool = true;
  tutorial_msg_.Int8 = -1;
  tutorial_msg_.UInt8 = 1;
  tutorial_msg_.Int16 = -2;
  tutorial_msg_.UInt16 = 2;
  tutorial_msg_.Int32 = -3;
  tutorial_msg_.UInt32 = 3;
  tutorial_msg_.Int64 = -4;
  tutorial_msg_.UInt64 = 4;
  tutorial_msg_.Float32 = -5.5;
  tutorial_msg_.Float64 = -6.6;
  tutorial_msg_.String = "Tutorial";
  tutorial_msg_.Time = ros::Time::now();
  tutorial_msg_.Duration = ros::Duration(5, 1);

}

void BasicClassMsg::Publisher()
{
  publisher_tutorial_msg_.publish(tutorial_msg_);
}

void BasicClassMsg::Spin()
{
  UpdateTutorialMsg();
  Publisher();
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "basic_class_msg");
  ros::NodeHandle n;

  ros::Rate loop_rate(60);

  BasicClassMsg basic_class_msg(n);
  while (ros::ok())
  {
    basic_class_msg.Spin();
    ros::spinOnce();
    loop_rate.sleep();
  }

  return 0;
}
