#ifndef LOG_FILE_WRITE_H
#define LOG_FILE_WRITE_H

#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include "log_file_write_tutorial/LogFileCommand.h"

#include <fstream>
#include <termios.h>
#include <unistd.h>
#include <stdlib.h>
#include <unistd.h>

struct CmdVel
{
  double linear_x = 0;
  double linear_y = 0;
  double linear_z = 0;
  double angular_x = 0;
  double angular_y = 0;
  double angular_z = 0;
};

class Log_file_write
{
public:
    Log_file_write(ros::NodeHandle &n)
    : subscriber_cmd_vel_(n.subscribe("cmd_vel", 100, &Log_file_write::CmdVelCallback, this)),
      log_file_service_server_(n.advertiseService("logfile_manager",&Log_file_write::LogFileManagerServiceCallback, this))
       {
          // open run
          ROS_INFO("log_file_write_node Open");
          char temp_path[255];
          getcwd(temp_path, 255);
          n.param<std::string>("log_file_path", log_file_path_ ,temp_path);
          n.param<std::string>("log_file_name", log_file_name_ ,"NonNameLogFile");
          OpenLogFile();
       }
       ~Log_file_write()
       {
          // close run
          ROS_INFO("log_file_write_node Close");
          log_text_.close();
       }

    void CmdVelCallback(const geometry_msgs::Twist &cmd_vel);

    bool LogFileManagerServiceCallback(log_file_write_tutorial::LogFileCommandRequest &req,
                                       log_file_write_tutorial::LogFileCommandResponse &res);

    bool LogFileManager();

    bool OpenLogFile();

    std::string GetNowTime();

    std::string SetLogFile(std::string log_file_path, std::string log_file_name);

    bool WriteLogFile(std::string text);

    std::string WriteLogText();

    bool Update();

private:
    ros::Subscriber subscriber_cmd_vel_;
    ros::ServiceServer log_file_service_server_;
    ros::Time time_now_;

    std::string log_file_path_;
    std::string log_file_name_;
    std::string log_file_;
    std::ofstream log_text_;

    CmdVel Scmd_vel_;
    int log_file_manager_trigger_ = -1;
};


#endif // LOG_FILE_WRITE_H
