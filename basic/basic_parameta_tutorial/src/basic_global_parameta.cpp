#include <ros/ros.h>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "basic_global_parameta_node");
  ros::NodeHandle n;

  ROS_INFO("basic_global_parameta_node Open");

  ros::Rate loop_rate(60);

  std::string parameta_string;
  int parameta_int;
  double parameta_double;
  bool parameta_bool;

  std::vector<int> parameta_array_int;
  std::vector<double> parameta_array_double;
  std::vector<std::string> parameta_array_string;

  n.param<std::string>("ParametaString",parameta_string,"Non");
  n.param<int>("ParametaInt",parameta_int,0);
  n.param<double>("ParametaDouble",parameta_double,0.0);
  n.param<bool>("ParametaBool",parameta_bool,false);

  n.param<std::vector<int>>("ParametaArrayInt",parameta_array_int, {0});
  n.param<std::vector<double>>("ParametaArrayDouble",parameta_array_double, {0.0});
  n.param<std::vector<std::string>>("ParametaArrayString",parameta_array_string, {"Non"});

  ROS_INFO("ParametaString : %s", parameta_string.c_str());
  ROS_INFO("ParametaInt : %d", parameta_int);
  ROS_INFO("ParametaDouble : %f", parameta_double);
  if(parameta_bool == true) ROS_INFO("ParametaBool : true");
  else if(parameta_bool == false) ROS_INFO("ParametaBool : false");

  for (uint i=0; i<parameta_array_int.size(); i ++) ROS_INFO("ParametaArrayInt[%d] : %d", i, parameta_array_int[i]);
  for (uint i=0; i<parameta_array_double.size(); i ++) ROS_INFO("ParametaArrayDouble[%d] : %f", i, parameta_array_double[i]);
  for (uint i=0; i<parameta_array_string.size(); i ++) ROS_INFO("ParametaArrayString[%d] : %s", i, parameta_array_string[i].c_str());

  while(ros::ok())
  {
    ros::spinOnce();
    loop_rate.sleep();
  }

  ROS_INFO("basic_global_parameta_node Close");

  return 0;

}
