#include <ros/ros.h>
#include <qt_demo/qt_location.h>
int main(int argc,char **argv)
{
  ros::init(argc,argv,"qttalker");
  ros::NodeHandle nh;
  qt_demo::qt_location msg;
  msg.x=1.0;
  msg.y=1.0;
  msg.state="working";
  ros::Publisher pub=nh.advertise<qt_demo::qt_location>("location_info",1);
  pub.publish(msg);
  ros::Rate loop_rate(1.0); //定义循环发布的频率
   while (ros::ok())
  {
    msg.x = 1.01 * msg.x ;
    msg.y = 1.02 * msg.y;
    ROS_INFO("Talker: LOCATION: x = %f, y = %f ",  msg.x ,msg.y);
    pub.publish(msg);
    loop_rate.sleep();//休眠1s钟，以一定的频率发布
  }
  return 0;
}

