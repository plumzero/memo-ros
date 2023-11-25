
cmake_minimum_required(VERSION 3.1.0)

add_executable(write write.cpp ${ROS_BASE_SRCS} ${ROS_BAG_SRCS} ${roscpp_serialization_SRCS})
target_link_libraries(write pthread ${crypto_LIBRARY} ${gpgerror_LIBRARY} ${assuan_LIBRARY} ${gpgme_LIBRARY})
