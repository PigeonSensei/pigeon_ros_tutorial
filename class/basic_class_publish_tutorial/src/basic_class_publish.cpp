#include "basic_class_publish_tutorial/basic_class_publish.h"

bool BasicClassPubilsh::UpdateCmdVel()
{
  cmd_vel_.linear.x = 10;
  cmd_vel_.angular.z = 10;

  return true;
}

bool BasicClassPubilsh::Publisher()
{
  publisher_cmd_vel_.publish(cmd_vel_);
  return true;
}

void BasicClassPubilsh::Spin()
{
  UpdateCmdVel();
  Publisher();
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "basic_class_publish_node");
  ros::NodeHandle n;

  ros::Rate loop_rate(60);

  BasicClassPubilsh basic_class_publish(n);
  while (ros::ok())
  {
    basic_class_publish.Spin();
    ros::spinOnce();
    loop_rate.sleep();
  }

  return 0;

}
