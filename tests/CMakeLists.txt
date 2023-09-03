
cmake_minimum_required(VERSION 3.1.0)

add_executable(bag_info bag_info.cpp ${ROS_BASE_SRCS} ${ROS_BAG_SRCS})
target_link_libraries(bag_info pthread)

# add_executable(pub pub.cpp ${ROS_BASE_SRCS} ${ROS_MSG_SRCS} ${ROS_CLI_SRCS})

# add_executable(pub_string pub_string.cpp ${ROS_ALL_SRCS})
# target_link_libraries(pub_string -lboost_thread -lpthread)
