
#include "ros/ros.h"
#include "std_msgs/String.h"

void messageCallback(const std_msgs::String::ConstPtr& msg)
{
  ROS_INFO("Thanks: [%s]", msg->data.c_str());
}

int main(int argc, char **argv)
{
  // 初始化 ROS 节点
  ros::init(argc, argv, "suber");
  // 创建节点句柄
  ros::NodeHandle n;
  // 创建一个 Subscriber，订阅名为 "/topic/message" 的 topic，注册回调函数 messageCallback
  ros::Subscriber sub = n.subscribe("/topic/message", 100, messageCallback);
  // 循环等待回调函数
  ros::spin();

  return 0;
}
