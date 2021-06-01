#include <ros/ros.h>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "basic_parameta_node");
  ros::NodeHandle n("~");

  std::string parameta_string;
  int parameta_int;
  double parameta_double;
  bool parameta_bool;
  std::vector<int> parameta_array_int;
  std::vector<double> parameta_array_double;
  std::vector<std::string> parameta_array_string;

  parameta_array_int.push_back(0);
  parameta_array_double.push_back(0.0);
  parameta_array_string.push_back("Non");

  n.param<std::string>("ParametaString",parameta_string,"Non");
  n.param<int>("ParametaInt",parameta_int,0);
  n.param<double>("ParametaDouble",parameta_double,0.0);
  n.param<bool>("ParametaBool",parameta_bool,false);
  n.param<std::vector<int>>("ParametaArrayInt",parameta_array_int, parameta_array_int);
  n.param<std::vector<double>>("ParametaArrayDouble",parameta_array_double, parameta_array_double);
  n.param<std::vector<std::string>>("ParametaArrayString",parameta_array_string, parameta_array_string);

  ROS_INFO("ParametaString : %s", parameta_string.c_str());
  ROS_INFO("ParametaDouble : %f", parameta_double);
  if(parameta_bool == true) ROS_INFO("ParametaBool : true");
  else if(parameta_bool == false) ROS_INFO("ParametaBool : false");

  for (uint i=0; i<parameta_array_int.size(); i ++) ROS_INFO("ParametaArrayInt[%d] : %d", i, parameta_array_int[i]);
  for (uint i=0; i<parameta_array_double.size(); i ++) ROS_INFO("ParametaArrayDouble[%d] : %f", i, parameta_array_double[i]);
  for (uint i=0; i<parameta_array_string.size(); i ++) ROS_INFO("ParametaArrayString[%d] : %s", i, parameta_array_string[i].c_str());

  while(ros::ok())
  {

  }

  return 0;

}
