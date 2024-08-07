
#include <cassert>
#include <iostream>
#include "rosbag/view.h"
#include "helper.h"

const char *MESSAGE = "message foo";
const char *TOPIC_NAME = "topic_bar";

int main()
{
  ros::Time::init();

  // Write a message to a bag file
  std::string bag_file_name = "log.bag";
  rosbag::Bag bag(bag_file_name, rosbag::bagmode::Write);

  {
    roslog::detail thelog = genlog(roslog::detail::INFO, __FILE__, __LINE__, "this is an info log");
    bag.write(TOPIC_NAME, ros::Time::now(), thelog);
  }

  {
    roslog::detail thelog = genlog(roslog::detail::WARN, __FILE__, __LINE__, "this is an warn log");
    bag.write(TOPIC_NAME, ros::Time::now(), thelog);
  }
  
  bag.close();

  // Test the message from the bag file
  bag.open(bag_file_name, rosbag::bagmode::Read);
  rosbag::View view(bag);
  assert(view.size() >= 1u);
  assert(TOPIC_NAME == view.begin()->getTopic());
  for (rosbag::View::iterator it = view.begin(); it != view.end(); it++) {
    print(*it->instantiate<roslog::detail>());
  }

  bag.close();

  std::cout << "===== success =====" << std::endl;

  return 0;
}