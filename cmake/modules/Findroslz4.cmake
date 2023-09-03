
find_path(roslz4_INCLUDE roslz4/lz4s.h HINTS "${PROJECT_SOURCE_DIR}/include/ros_comm/utilities/roslz4/include" NO_DEFAULT_PATH)
find_path(lz4_INCLUDE lz4.h HINTS "${PROJECT_SOURCE_DIR}/include/ros_comm/utilities/roslz4/src" NO_DEFAULT_PATH)

if (roslz4_INCLUDE)
  set(roslz4_FOUND TRUE)
  message(STATUS "${Green}Found roslz4 include at: ${roslz4_INCLUDE}${Reset}")
  file(GLOB roslz4_SRCS
    ${PROJECT_SOURCE_DIR}/include/ros_comm/utilities/roslz4/src/lz4s.c
    ${PROJECT_SOURCE_DIR}/include/ros_comm/utilities/roslz4/src/xxhash.c
    ${PROJECT_SOURCE_DIR}/include/ros_comm/utilities/roslz4/src/lz4.c
    ${PROJECT_SOURCE_DIR}/include/ros_comm/utilities/roslz4/src/lz4hc.c
    ${PROJECT_SOURCE_DIR}/include/ros_comm/utilities/roslz4/src/lz4io.c
    ${PROJECT_SOURCE_DIR}/include/ros_comm/tools/rosbag_storage/src/lz4_stream.cpp
  )
else()
  message(FATAL_ERROR "${Red}Failed to locate roslz4 module.${Reset}" )
endif()
