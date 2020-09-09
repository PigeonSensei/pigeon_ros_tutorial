#include "pigeon_sub_pub/pigeon_sub.h"

int Pigeon_sub::input_return_key()
{
  struct termios org_term;

  char input_key = 0;

  tcgetattr(STDIN_FILENO, &org_term);

  struct termios new_term = org_term;

  new_term.c_lflag &= ~(ECHO | ICANON);

  new_term.c_cc[VMIN] = 0;
  new_term.c_cc[VTIME] = 0;

  tcsetattr(STDIN_FILENO, TCSANOW, &new_term);

  read(STDIN_FILENO, &input_key, 1);

  tcsetattr(STDIN_FILENO, TCSANOW, &org_term);

  return input_key;
}

void Pigeon_sub::cmd_vel_sub(const geometry_msgs::Twist &cmd_vel)
{
 odom_pub.twist.twist.linear.x = cmd_vel.linear.x;
 odom_pub.twist.twist.angular.z = cmd_vel.angular.z;
 ROS_INFO("Subscribe 'cmd_vel linear.x = %.5f , angular.z = %.5f", cmd_vel_pub.linear.x, cmd_vel_pub.angular.z);
 ROS_INFO("Publish 'odom linear.x = %.5f , angular.z = %.5f", odom_pub.twist.twist.linear.x, odom_pub.twist.twist.angular.z);
 pub.publish(odom_pub);
}

void Pigeon_sub::update()
{

}

void Pigeon_sub::spin()
{
  update();
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "pigeon_sub_node");
  ros::NodeHandle n;

  ros::Rate loop_rate(120);

  Pigeon_sub pigeon_sub(n);

  while (ros::ok())
  {
    pigeon_sub.spin();
    ros::spinOnce();
    loop_rate.sleep();
    if(pigeon_sub.input_return_key() == 27) return 0;
  }

}
