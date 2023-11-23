
cmake_minimum_required(VERSION 3.1.0)

add_executable(pub pub.cpp ${ROS_BASE_SRCS} ${ROS_MSG_SRCS} ${ROS_CLI_SRCS})
target_link_libraries(pub boost_chrono boost_filesystem boost_thread)

add_executable(sub sub.cpp ${ROS_BASE_SRCS} ${ROS_MSG_SRCS} ${ROS_CLI_SRCS})
target_link_libraries(sub boost_chrono boost_filesystem boost_thread)
