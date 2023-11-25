
#include <cstdio>
#include <cassert>
#include <iostream>
#include "std_msgs/String.h"
#include "rosbag/bag.h"
#include "rosbag/view.h"

const char *MESSAGE = "message foo";
const char *TOPIC_NAME = "topic_bar";

int main()
{
  ros::Time::init();

  // Write a message to an encrypted bag file
  std::string bag_file_name = "foo.bag";
  rosbag::Bag bag(bag_file_name, rosbag::bagmode::Write);
  std_msgs::String msg;
  msg.data = MESSAGE;
  bag.write(TOPIC_NAME, ros::Time::now(), msg);
  bag.close();

  // Test the message decrypted from the bag file
  bag.open(bag_file_name, rosbag::bagmode::Read);
  rosbag::View view(bag);
  assert(view.size() == 1u);
  assert(TOPIC_NAME == view.begin()->getTopic());
  assert(MESSAGE == view.begin()->instantiate<std_msgs::String>()->data);
  bag.close();

  std::cout << "===== success =====" << std::endl;

  return 0;
}