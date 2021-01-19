#include "basic_class_msg.h"

bool Basic_class_msg::UpdateTutorialMsg()
{
  tutorial_msg_.A = true;
  tutorial_msg_.B = -1;
  tutorial_msg_.C = 1;
  tutorial_msg_.D = -2;
  tutorial_msg_.E = 2;
  tutorial_msg_.F = -3;
  tutorial_msg_.G = 3;
  tutorial_msg_.H = -4;
  tutorial_msg_.I = 4;
  tutorial_msg_.J = -5.5;
  tutorial_msg_.K = -6.6;
  tutorial_msg_.L = "Tutorial";
  tutorial_msg_.M = ros::Time::now();
  tutorial_msg_.N = ros::Duration(5, 1);

  return true;

}

bool Basic_class_msg::Publisher()
{
  publisher_tutorial_msg_.publish(tutorial_msg_);
  return true;
}

bool Basic_class_msg::Update()
{
  UpdateTutorialMsg();
  Publisher();

  return true;
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "basic_class_msg");
  ros::NodeHandle n;

  ros::Rate loop_rate(60);

  Basic_class_msg basic_class_msg(n);
  while (ros::ok())
  {
    basic_class_msg.Update();
    loop_rate.sleep();
    ros::spinOnce();
//    if(basic_class.ReturnInputKey() == 27) break;
  }

  return 0;
}
