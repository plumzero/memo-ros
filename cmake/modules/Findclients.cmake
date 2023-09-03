
find_path(clients_INCLUDE ros/ros.h HINTS "${PROJECT_SOURCE_DIR}/include/ros_comm/clients/roscpp/include" NO_DEFAULT_PATH)
# find_path(clients_roscpp_INCLUDE roscpp/GetLoggers.h HINTS "${PROJECT_SOURCE_DIR}/include/ros_comm/clients/roscpp/build/devel/include" NO_DEFAULT_PATH)
# find_path(clients_ros_INCLUDE common.h HINTS "${PROJECT_SOURCE_DIR}/include/ros_comm/clients/roscpp/build/devel/include/ros" NO_DEFAULT_PATH)

if (clients_INCLUDE)
  set(_FOUND TRUE)
  message(STATUS "${Green}Found rosclients include at: ${clients_INCLUDE}${Reset}")
  file(GLOB client_SRCS
    ${PROJECT_SOURCE_DIR}/include/ros_comm/clients/roscpp/src/libros/*.cpp
    ${PROJECT_SOURCE_DIR}/include/ros_comm/clients/roscpp/src/libros/transport/*.cpp
  )
else()
  message(FATAL_ERROR "${Red}Failed to locate rosclients module.${Reset}" )
endif()
