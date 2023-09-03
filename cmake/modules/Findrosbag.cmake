
find_path(rosbag_INCLUDE rosbag/bag.h HINTS "${PROJECT_SOURCE_DIR}/include/ros_comm/tools/rosbag_storage/include" NO_DEFAULT_PATH)

if (rosbag_INCLUDE)
  set(ROSBAG_FOUND TRUE)
  message(STATUS "${Green}Found rosbag include at: ${rosbag_INCLUDE}${Reset}")
  file(GLOB rosbag_SRCS
    ${PROJECT_SOURCE_DIR}/include/ros_comm/tools/rosbag_storage/src/bag_player.cpp
    ${PROJECT_SOURCE_DIR}/include/ros_comm/tools/rosbag_storage/src/bag.cpp
    ${PROJECT_SOURCE_DIR}/include/ros_comm/tools/rosbag_storage/src/buffer.cpp
    ${PROJECT_SOURCE_DIR}/include/ros_comm/tools/rosbag_storage/src/chunked_file.cpp
    ${PROJECT_SOURCE_DIR}/include/ros_comm/tools/rosbag_storage/src/message_instance.cpp
    ${PROJECT_SOURCE_DIR}/include/ros_comm/tools/rosbag_storage/src/no_encryptor.cpp
    ${PROJECT_SOURCE_DIR}/include/ros_comm/tools/rosbag_storage/src/query.cpp
    ${PROJECT_SOURCE_DIR}/include/ros_comm/tools/rosbag_storage/src/stream.cpp
    ${PROJECT_SOURCE_DIR}/include/ros_comm/tools/rosbag_storage/src/uncompressed_stream.cpp
    ${PROJECT_SOURCE_DIR}/include/ros_comm/tools/rosbag_storage/src/view.cpp
  )
else()
  message(FATAL_ERROR "${Red}Failed to locate rosbag module.${Reset}" )
endif()
