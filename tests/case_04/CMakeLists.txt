
cmake_minimum_required(VERSION 3.1.0)

add_executable(encrypt encrypt.cpp ${ROS_BASE_SRCS} ${ROS_BAG_SRCS} ${roscpp_serialization_SRCS})
target_link_libraries(encrypt pthread ${crypto_LIBRARY} ${gpgerror_LIBRARY} ${assuan_LIBRARY} ${gpgme_LIBRARY})

add_executable(enc_dec enc_dec.cpp ${ROS_BASE_SRCS} ${ROS_BAG_SRCS} ${roscpp_serialization_SRCS})
target_link_libraries(enc_dec pthread ${crypto_LIBRARY} ${gpgerror_LIBRARY} ${assuan_LIBRARY} ${gpgme_LIBRARY})