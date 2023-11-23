
cmake_minimum_required(VERSION 3.1.0)

add_executable(pub_string pub_string.cpp ${ROS_BASE_SRCS} ${ROS_MSG_SRCS} ${ROS_CLI_SRCS})
target_link_libraries(pub_string boost_chrono boost_filesystem boost_thread)

add_executable(sub_string sub_string.cpp ${ROS_BASE_SRCS} ${ROS_MSG_SRCS} ${ROS_CLI_SRCS})
target_link_libraries(sub_string boost_chrono boost_filesystem boost_thread)
