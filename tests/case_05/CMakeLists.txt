
cmake_minimum_required(VERSION 3.1.0)

add_executable(write_read write_read.cpp ${ROS_BASE_SRCS} ${ROS_BAG_SRCS} ${roscpp_serialization_SRCS})
target_link_libraries(write_read pthread ${crypto_LIBRARY} ${gpgerror_LIBRARY} ${assuan_LIBRARY} ${gpgme_LIBRARY})

add_executable(rosbag_without_pgp rosbag_without_pgp.cpp ${ROS_BASE_SRCS} ${ROS_BAG_SRCS} ${roscpp_serialization_SRCS})
target_link_libraries(rosbag_without_pgp pthread ${crypto_LIBRARY} ${gpgerror_LIBRARY} ${assuan_LIBRARY} ${gpgme_LIBRARY})

add_executable(rosbag_with_pgp rosbag_with_pgp.cpp ${ROS_BASE_SRCS} ${ROS_BAG_SRCS} ${roscpp_serialization_SRCS})
target_link_libraries(rosbag_with_pgp pthread ${crypto_LIBRARY} ${gpgerror_LIBRARY} ${assuan_LIBRARY} ${gpgme_LIBRARY})
