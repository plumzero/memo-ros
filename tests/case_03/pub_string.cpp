
#include "ros/ros.h"
#include "std_msgs/String.h"

int main(int argc, char **argv)
{
  // ROS 节点初始化
  ros::init(argc, argv, "puber");
  // 创建节点句柄
  ros::NodeHandle n;
  // 创建一个 Publisher，发布名为 "/topic/message" 的 topic，消息类型为 std_msgs::String，队列长度为 100
  ros::Publisher pub = n.advertise<std_msgs::String>("/topic/message", 100);
  // 设置循环的频率(也可以说是发布的频率)
  ros::Rate loop_rate(10);
 
  while (ros::ok())
  {
    std_msgs::String msg;
    msg.data = "hello world";

    pub.publish(msg);

    ros::spinOnce();
    loop_rate.sleep();

    ROS_INFO("node publish: %s", msg.data.c_str());
  }
  return 0;
}
