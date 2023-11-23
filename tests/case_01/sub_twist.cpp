
#include "ros/ros.h"
// #include "turtlesim/Pose.h"
#include "geometry_msgs/Twist.h"

void moveCallback(const geometry_msgs::Twist::ConstPtr& msg)
{
  // ROS_INFO("Thanks: [%.2f m/s, %.2f rad/s]", msg->x, msg->y);
  ROS_INFO("Thanks: [%.2f m/s, %.2f rad/s]", msg->linear.x, msg->angular.z);
}

int main(int argc, char **argv)
{
  // 初始化 ROS 节点
  ros::init(argc, argv, "sub_twist");
  // 创建节点句柄
  ros::NodeHandle n;
  // 创建一个 Subscriber，订阅名为 "/turtle1/cmd_vel" 的 topic，注册回调函数 moveCallback
  ros::Subscriber sub = n.subscribe("/turtle1/cmd_vel", 100, moveCallback);
  // 循环等待回调函数
  ros::spin();

  return 0;
}
