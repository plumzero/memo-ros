
find_path(bzip2_INCLUDE bzlib.h HINTS "${PROJECT_SOURCE_DIR}/include/bzip2" NO_DEFAULT_PATH)

if (bzip2_INCLUDE)
  set(BZIP2_FOUND TRUE)
  add_definitions(-D_BZIP2)
  message(STATUS "${Green}Found bzip2 include at: ${bzip2_INCLUDE}${Reset}")
  set(bzip2_SRCS
    ${PROJECT_SOURCE_DIR}/include/bzip2/blocksort.c
    ${PROJECT_SOURCE_DIR}/include/bzip2/bzlib.c
    ${PROJECT_SOURCE_DIR}/include/bzip2/crctable.c
    ${PROJECT_SOURCE_DIR}/include/bzip2/huffman.c
    ${PROJECT_SOURCE_DIR}/include/bzip2/compress.c
    ${PROJECT_SOURCE_DIR}/include/bzip2/decompress.c
    ${PROJECT_SOURCE_DIR}/include/bzip2/randtable.c
    ${PROJECT_SOURCE_DIR}/include/ros_comm/tools/rosbag_storage/src/bz2_stream.cpp
  )
else()
  message(FATAL_ERROR "${Red}Failed to locate bzip2 module.${Reset}" )
endif()
