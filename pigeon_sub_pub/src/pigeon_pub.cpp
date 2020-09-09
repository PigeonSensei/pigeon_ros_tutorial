#include <pigeon_sub_pub/pigeon_pub.h>

int Pigeon_pub::input_return_key()
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

void Pigeon_pub::update()
{
  cmd_vel_pub.linear.x++;
  cmd_vel_pub.angular.z++;
  if(cmd_vel_pub.linear.x > 10) cmd_vel_pub.linear.x = 0;
  if(cmd_vel_pub.angular.z > 10) cmd_vel_pub.angular.z = 0;
}

void Pigeon_pub::spin()
{
  update();
  pub.publish(cmd_vel_pub);
  ROS_INFO("Publish 'cmd_vel linear.x = %.5f , angular.z = %.5f", cmd_vel_pub.linear.x, cmd_vel_pub.angular.z);
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "pigeon_pub_node");
  ros::NodeHandle n;

  ros::Rate loop_rate(60);

  Pigeon_pub pigeon_pub(n);

  while (ros::ok())
  {
    pigeon_pub.spin();
    ros::spinOnce();
    loop_rate.sleep();
    if(pigeon_pub.input_return_key() == 27) return 0;
  }

}
