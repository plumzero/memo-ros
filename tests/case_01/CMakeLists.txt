
cmake_minimum_required(VERSION 3.1.0)

add_executable(pub_twist pub_twist.cpp ${ROS_BASE_SRCS} ${ROS_MSG_SRCS} ${ROS_CLI_SRCS})
target_link_libraries(pub_twist boost_chrono boost_filesystem boost_thread)

add_executable(sub_twist sub_twist.cpp ${ROS_BASE_SRCS} ${ROS_MSG_SRCS} ${ROS_CLI_SRCS})
target_link_libraries(sub_twist boost_chrono boost_filesystem boost_thread)
