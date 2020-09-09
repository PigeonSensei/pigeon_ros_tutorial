#include <pigeon_msg/pigeon_msg_sub.h>

int Pigeon_msg_sub::keybord_input()
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

void Pigeon_msg_sub::update()
{

}

void Pigeon_msg_sub::msg_sub(const pigeon_msg::tutorial &msg)
{
  ROS_INFO("Subscribe : A = %d, B = %d",msg.A, msg.B);
}

void Pigeon_msg_sub::spin()
{
  update();
}


int main(int argc, char **argv)
{
    ros::init(argc, argv, "PIGEON_MSG_SUB_NODE");
    ros::NodeHandle n;

    Pigeon_msg_sub pigeon_msg_sub(n);
    ros::Rate loop_rate(60);


    while (ros::ok())
    {
      pigeon_msg_sub.spin();
      loop_rate.sleep();
      ros::spinOnce();
      if(pigeon_msg_sub.keybord_input() == 27) return 0;
    }
    return 0;
}
