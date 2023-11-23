
cmake_minimum_required(VERSION 3.1.0)

project("rosdev" C CXX)

#
# Version
#
set(rosdev_VERSION_MAJOR 1)
set(rosdev_VERSION_MINOR 0)
set(rosdev_VERSION_FIXED 0)
set(rosdev_VERSION ${rosdev_VERSION_MAJOR}.${rosdev_VERSION_MINOR}.${rosdev_VERSION_FIXED})
set(PACKAGE_VERSION ${rosdev_VERSION})
set(VERSION "${rosdev_VERSION}")

#
# C++
#
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_EXTENSIONS ON)
# set(CMAKE_VERBOSE_MAKEFILE on)

#
# if u wanna debug, do like this `cmake -DCMAKE_BUILD_TYPE=Debug`
#
if (NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug)
endif()

#
# Build Options
#
option(BUILD_TESTS  "Build all available test suites"           ON)

#
# Configuration
#
include("${PROJECT_SOURCE_DIR}/cmake/configuration.cmake")

#
# Modules
#
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake/modules")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DBOOST_BIND_GLOBAL_PLACEHOLDERS")

#
# Boost Required
#
find_package(boost REQUIRED)
include_directories(SYSTEM ${boost_INCLUDE})
link_directories(${boost_LIBRARY})

#
# Module Required
#
find_package(console_bridge REQUIRED)
include_directories(SYSTEM ${console_bridge_INCLUDE})

find_package(roscpp_traits REQUIRED)
include_directories(SYSTEM ${roscpp_traits_INCLUDE})

find_package(rosbag REQUIRED)
include_directories(SYSTEM ${rosbag_INCLUDE})

find_package(rostime REQUIRED)
include_directories(SYSTEM ${rostime_INCLUDE})

find_package(cpp_common REQUIRED)
include_directories(SYSTEM ${cpp_common_INCLUDE})

find_package(roscpp_serialization REQUIRED)
include_directories(SYSTEM ${roscpp_serialization_INCLUDE})

# find_package(pluginlib REQUIRED)
# include_directories(SYSTEM ${pluginlib_INCLUDE})

find_package(clients REQUIRED)
include_directories(SYSTEM ${clients_INCLUDE})

find_package(message_filters REQUIRED)
include_directories(SYSTEM ${message_filters_INCLUDE})

find_package(rosconsole REQUIRED)
include_directories(SYSTEM ${rosconsole_INCLUDE})

find_package(xmlrpcpp REQUIRED)
include_directories(SYSTEM ${xmlrpcpp_INCLUDE})
include_directories(SYSTEM ${xmlrpcpp_b64_INCLUDE})

find_package(bzip2 REQUIRED)
include_directories(SYSTEM ${bzip2_INCLUDE})

find_package(roslz4 REQUIRED)
include_directories(SYSTEM ${roslz4_INCLUDE} ${lz4_INCLUDE})

set(ROS_BASE_SRCS
  ${console_bridge_SRCS}
  ${cpp_common_SRCS}
  ${rostime_SRCS}
)

set(ROS_BAG_SRCS
  ${rosbag_SRCS}
  ${roslz4_SRCS}
  ${bzip2_SRCS}
)

set(ROS_MSG_SRCS
  ${roscpp_serialization_SRCS}
  ${message_filters_SRCS}
  ${rosconsole_SRCS}
)

set(ROS_CLI_SRCS
  ${client_SRCS}
  ${xmlrpcpp_SRCS}
)

#
# Other
#
include_directories(util)
include_directories(realize)
include_directories(SYSTEM ${PROJECT_SOURCE_DIR}/devel)
include_directories(SYSTEM ${PROJECT_SOURCE_DIR}/devel/ros)

#
# Support large bags (>2GB) on 32-bit systems
#
add_definitions(-D_FILE_OFFSET_BITS=64)

#
# Build
#
add_subdirectory(tests)
