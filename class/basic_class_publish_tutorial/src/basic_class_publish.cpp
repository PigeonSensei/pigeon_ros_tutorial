#include "basic_class_publish.h"

bool Basic_class_pubilsh::UpdateCmdVel()
{
  cmd_vel_.linear.x = 10;
  cmd_vel_.angular.z = 10;

  return true;
}

bool Basic_class_pubilsh::Publisher()
{
  publisher_cmd_vel_.publish(cmd_vel_);
  return true;
}

bool Basic_class_pubilsh::Update()
{
  UpdateCmdVel();
  Publisher();
  return true;
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "basic_class_publish_node");
  ros::NodeHandle n;

  ros::Rate loop_rate(60);

  Basic_class_pubilsh basic_class_publish(n);
  while (ros::ok())
  {
    basic_class_publish.Update();
    loop_rate.sleep();
    ros::spinOnce();
//    if(basic_class.ReturnInputKey() == 27) break;
  }

  return 0;

}
