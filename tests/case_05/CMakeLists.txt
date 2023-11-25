
cmake_minimum_required(VERSION 3.1.0)

add_executable(write write.cpp ${ROS_BASE_SRCS} ${ROS_BAG_SRCS} ${roscpp_serialization_SRCS})
target_link_libraries(write pthread ${crypto_LIBRARY} ${gpgerror_LIBRARY} ${assuan_LIBRARY} ${gpgme_LIBRARY})

add_executable(writelog writelog.cpp ${ROS_BASE_SRCS} ${ROS_BAG_SRCS} ${roscpp_serialization_SRCS})
target_link_libraries(writelog pthread ${crypto_LIBRARY} ${gpgerror_LIBRARY} ${assuan_LIBRARY} ${gpgme_LIBRARY})

add_executable(enc_dec_log enc_dec_log.cpp ${ROS_BASE_SRCS} ${ROS_BAG_SRCS} ${roscpp_serialization_SRCS})
target_link_libraries(enc_dec_log pthread ${crypto_LIBRARY} ${gpgerror_LIBRARY} ${assuan_LIBRARY} ${gpgme_LIBRARY})
