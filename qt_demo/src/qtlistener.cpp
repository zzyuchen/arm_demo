#include <ros/ros.h>
#include <qt_demo/qt_location.h>
#include <std_msgs/Float32.h>

void locationCallback(const qt_demo::qt_location::ConstPtr &msg)
{
    std_msgs::Float32 distance;
    distance.data = sqrt(pow(msg->x,2)+pow(msg->y,2));
    ROS_INFO("Listener: Distance to origin = %f, state: %s",distance.data,msg->state.c_str());
}


int main(int argc, char **argv)
{
  ros::init(argc, argv, "qtlistener");
  ros::NodeHandle n;
  ros::Subscriber sub = n.subscribe("location_info", 1, locationCallback);
  ros::spin();//反复查询是否可调用回调函数
  return 0;
}


