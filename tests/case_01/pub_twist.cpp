
#include "ros/ros.h"
#include "geometry_msgs/Twist.h"

int main(int argc, char **argv)
{
  // ROS 节点初始化
  ros::init(argc, argv, "pub_twist");
  // 创建节点句柄
  ros::NodeHandle n;
  // 创建一个 Publisher，发布名为 "/turtle1/cmd_vel" 的 topic，消息类型为 geometry_msgs::Twist，队列长度为 100
  ros::Publisher pub = n.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 100);
  // 设置循环的频率(也可以说是发布的频率)
  ros::Rate loop_rate(10);
 
  while (ros::ok())
  {
    geometry_msgs::Twist msg;
    msg.linear.x = 0.5;
    msg.angular.z = 0.2;

    pub.publish(msg);

    // ros::spinOnce();
    loop_rate.sleep();

    ROS_INFO("Publish turtle velocity command[%.2f m/s, %.2f rad/s]", msg.linear.x, msg.angular.z);
  }

  return 0;
}
