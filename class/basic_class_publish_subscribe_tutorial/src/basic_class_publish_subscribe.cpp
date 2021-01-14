#include "basic_class_publish_subscribe.h"

void Basic_class_pubilsh_subscribe::CmdVelCallback(const geometry_msgs::Twist &cmd_vel)
{
  Scmd_vel_.linear_x = cmd_vel.linear.x;
  Scmd_vel_.linear_y = cmd_vel.linear.y;
  Scmd_vel_.linear_z = cmd_vel.linear.z;
  Scmd_vel_.angular_y = cmd_vel.angular.x;
  Scmd_vel_.angular_y = cmd_vel.angular.y;
  Scmd_vel_.angular_z = cmd_vel.angular.z;
  ROS_INFO("subscribd cmd_vel : linear.x = %.3f , angular.z = %.3f", cmd_vel.linear.x, cmd_vel.angular.z);

  return;
}

bool Basic_class_pubilsh_subscribe::UpdateOdom()
{
  odom_.header.stamp = time_now;
  odom_.header.frame_id = "odom";
  odom_.child_frame_id = "base_link";
  odom_.header.seq = seq_count;
  odom_.twist.twist.linear.x = Scmd_vel_.linear_x;
  odom_.twist.twist.angular.z = Scmd_vel_.angular_z;

  return true;
}

bool Basic_class_pubilsh_subscribe::SetOdomTF()
{
  geometry_msgs::TransformStamped odom_trans;
  odom_trans.header.stamp = time_now;
  odom_trans.header.frame_id = "odom";
  odom_trans.child_frame_id = "base_link";

  odom_trans.transform.translation.x = 0;
  odom_trans.transform.translation.y = 0;
  odom_trans.transform.translation.z = 0;
  odom_trans.transform.rotation.x = 0;
  odom_trans.transform.rotation.y = 0;
  odom_trans.transform.rotation.z = 0;
  odom_trans.transform.rotation.w = 1;
  odom_broadcaster.sendTransform(odom_trans);
}

bool Basic_class_pubilsh_subscribe::Publisher()
{
  publisher_odom_.publish(odom_);
  seq_count++;

  return true;
}

bool Basic_class_pubilsh_subscribe::Update()
{
  time_now = ros::Time::now();
  SetOdomTF();
  UpdateOdom();
  Publisher();

  return true;
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "basic_class_publish_subscribe_node");
  ros::NodeHandle n;

  ros::Rate loop_rate(60);

  Basic_class_pubilsh_subscribe basic_class_pubilsh_subscribe(n);

  while (ros::ok())
  {
    basic_class_pubilsh_subscribe.Update();
    loop_rate.sleep();
    ros::spinOnce();
//    if(basic_class.ReturnInputKey() == 27) break;
  }

  return 0;


}
