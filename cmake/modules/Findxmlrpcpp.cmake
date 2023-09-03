
find_path(xmlrpcpp_INCLUDE xmlrpcpp/XmlRpc.h HINTS "${PROJECT_SOURCE_DIR}/include/ros_comm/utilities/xmlrpcpp/include" NO_DEFAULT_PATH)
find_path(xmlrpcpp_b64_INCLUDE b64/encode.h HINTS "${PROJECT_SOURCE_DIR}/include/ros_comm/utilities/xmlrpcpp/libb64/include" NO_DEFAULT_PATH)

if (xmlrpcpp_INCLUDE)
  set(_FOUND TRUE)
  message(STATUS "${Green}Found xmlrpcpp include at: ${xmlrpcpp_INCLUDE}${Reset}")
  file(GLOB xmlrpcpp_SRCS
    ${PROJECT_SOURCE_DIR}/include/ros_comm/utilities/xmlrpcpp/src/*.cpp
    ${PROJECT_SOURCE_DIR}/include/ros_comm/utilities/xmlrpcpp/libb64/src/*.c
  )
else()
  message(FATAL_ERROR "${Red}Failed to locate xmlrpcpp module.${Reset}" )
endif()
