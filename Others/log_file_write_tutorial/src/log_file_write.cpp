#include "log_file_write.h"

void Log_file_write::CmdVelCallback(const geometry_msgs::Twist &cmd_vel)
{
  Scmd_vel_.linear_x = cmd_vel.linear.x;
  Scmd_vel_.linear_y = cmd_vel.linear.y;
  Scmd_vel_.linear_z = cmd_vel.linear.z;
  Scmd_vel_.angular_x = cmd_vel.angular.x;
  Scmd_vel_.angular_y = cmd_vel.angular.y;
  Scmd_vel_.angular_z = cmd_vel.angular.z;
  return;
}

bool Log_file_write::LogFileManagerServiceCallback(log_file_write_tutorial::LogFileCommandRequest &req, log_file_write_tutorial::LogFileCommandResponse &res)
{


  if(req.command == "reset")
  {
      ROS_INFO("Receive Service call logfile_manager command : reset");
      log_file_manager_trigger_ = 0;
      res.message = "Receive success";
      res.result = "true";
  }
  else if(req.command == "save")
  {
      ROS_INFO("Receive Service call logfile_manager command : save");
      log_file_manager_trigger_ = 1;
      res.message = "Receive success";
      res.result = "true";
  }
  else if(req.command == "remove all")
  {
      ROS_INFO("Receive Service call logfile_manager command : remove all");
      log_file_manager_trigger_ = 2;
      res.message = "Receive success";
      res.result = "true";
  }

  else
  {
    ROS_INFO("Receive Service call logfile_manager command : non");
    log_file_manager_trigger_ = -1;
    res.message = "Receive fall";
    res.result = "false";
  }

  return true;

}

bool Log_file_write::LogFileManager()
{
  std::stringstream command;
  command.str("");
  std::system(command.str().c_str());

  if(log_file_manager_trigger_ == 0) // reset
  {
    log_text_.close();
    command << "rm " << log_file_ << std::endl;
    std::system(command.str().c_str());
  }

  else if (log_file_manager_trigger_ == 1)
  {
    log_text_.close();
  }

  else if (log_file_manager_trigger_ == 2)
  {
    log_text_.close();
    command << "rm " << log_file_path_ << "/" << log_file_name_ << "*" << std::endl;
    std::cout << command.str() << std::endl;
    std::system(command.str().c_str());

  }

  OpenLogFile();
  log_file_manager_trigger_ = -1;
  return true;
}

bool Log_file_write::OpenLogFile()
{
  log_file_ = SetLogFile(log_file_name_, log_file_path_);
  log_text_.open(log_file_);
  return true;
}
std::string Log_file_write::GetNowTime()
{
  time_t rawtime;
  struct tm *tm;
  time(&rawtime);
  tm = localtime(&rawtime);
  std::string year = std::to_string(tm->tm_year+1900);
  std::string mon = std::to_string(tm->tm_mon+1);
  std::string day =  std::to_string(tm->tm_mday);
  std::string hour = std::to_string(tm->tm_hour);
  std::string min = std::to_string(tm->tm_min);
  std::string sec = std::to_string(tm->tm_sec);

  std::string now_time;

  if(tm->tm_mon+1 <10) now_time = year + "0" + mon + day + hour + min + sec;
  else now_time = year + mon + day + hour + min + sec;

  return now_time;
}

std::string Log_file_write::SetLogFile(std::string log_file_name, std::string log_file_path)
{
  log_file_name = log_file_name + "-"+ GetNowTime() +".csv";
  log_file_path = log_file_path + "/" + log_file_name;
  std::cout << std::endl;
  std::cout << "log_file_name : " << log_file_name << std::endl;
  std::cout << "log_file_path : " << log_file_path << std::endl;
  return log_file_path;
}

bool Log_file_write::WriteLogFile(std::string text)
{
  log_text_ << text << std::endl;
  return true;

}

std::string Log_file_write::WriteLogText()
{
  std::string text;

  text = std::to_string(time_now_.toSec()) + "," + std::to_string(Scmd_vel_.linear_x) + ","
       + std::to_string(Scmd_vel_.linear_y) + "," + std::to_string(Scmd_vel_.linear_z) + ","
       + std::to_string(Scmd_vel_.angular_x) + "," + std::to_string(Scmd_vel_.angular_y) + ","
       + std::to_string(Scmd_vel_.angular_z);

  return text;
}

bool Log_file_write::Update()
{
  time_now_ = ros::Time::now();
  if(log_file_manager_trigger_ != -1) LogFileManager();
  WriteLogFile(WriteLogText());
  return true;

}

int ReturnInputKey()
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

int main(int argc, char **argv)
{
  ros::init(argc, argv, "log_file_write_node");
  ros::NodeHandle n;

  ros::Rate loop_rate(60);

  Log_file_write log_file_write(n);

  while (ros::ok())
  {
    log_file_write.Update();
    ros::spinOnce();
    loop_rate.sleep();
    if(ReturnInputKey() == 27) break; // Press 'Esc' to exit
  }

  return 0;

}
