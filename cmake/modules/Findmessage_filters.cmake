
find_path(message_filters_INCLUDE message_filters/cache.h HINTS "${PROJECT_SOURCE_DIR}/include/ros_comm/utilities/message_filters/include" NO_DEFAULT_PATH)

if (message_filters_INCLUDE)
  set(message_filters_FOUND TRUE)
  message(STATUS "${Green}Found message_filters include at: ${message_filters_INCLUDE}${Reset}")
  file(GLOB message_filters_SRCS
    ${PROJECT_SOURCE_DIR}/include/ros_comm/utilities/message_filters/src/*.cpp
  )
else()
  message(FATAL_ERROR "${Red}Failed to locate message_filters module.${Reset}" )
endif()
