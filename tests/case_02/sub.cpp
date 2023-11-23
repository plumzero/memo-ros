
#include <string>
#include <sstream>
#include <fstream>

#include <time.h>
#include <stdlib.h>

#include "ros/ros.h"
#include "std_msgs/String.h"

using namespace ros;

uint32_t g_recv_count = 0;
uint32_t g_sequence = 0;

void callback(const std_msgs::String::ConstPtr& msg)
{
  ++g_recv_count;
}

int main(int argc, char** argv)
{
  ros::init(argc, argv, "incrementing_sequence");

  ros::NodeHandle nh;
  ros::Publisher pub = nh.advertise<std_msgs::String>("test_with_header", 0);
  ros::Subscriber sub = nh.subscribe("test_with_header", 0, callback);

  while (g_recv_count < 50)
  {
    std_msgs::String msg;
    msg.data = "hello world";
    pub.publish(msg);

    ros::spinOnce();
    ros::WallDuration(0.01).sleep();
  }

  return 0;
}


