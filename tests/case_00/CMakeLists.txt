
cmake_minimum_required(VERSION 3.1.0)

add_executable(bag_info bag_info.cpp ${ROS_BASE_SRCS} ${ROS_BAG_SRCS})
target_link_libraries(bag_info pthread)
