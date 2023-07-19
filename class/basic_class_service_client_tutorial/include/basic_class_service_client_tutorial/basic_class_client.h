#ifndef BASIC_CLASS_CLIENT_H
#define BASIC_CLASS_CLIENT_H

#include <ros/ros.h>
#include "tutorial_srvs/TutorialSrv.h"

class BasicClassClient
{
public:
    BasicClassClient(ros::NodeHandle &n)
      : service_client_tutorial_command_(n.serviceClient<tutorial_srvs::TutorialSrv>("tutorial_command"))
       {
          // open run
          ROS_INFO("basic_class_service_client_node Open");
       }
       ~BasicClassClient()
       {
          // close run
          ROS_INFO("basic_class_service_client_node Close");
       }

    void Spin();

    bool TutorialCommandServiceCall();

private:
    ros::ServiceClient service_client_tutorial_command_;

    tutorial_srvs::TutorialSrv tutorial_command_;



};


#endif // BASIC_CLASS_CLIENT_H
