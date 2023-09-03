
find_path(rostime_INCLUDE ros/time.h HINTS "${PROJECT_SOURCE_DIR}/include/roscpp_core/rostime/include" NO_DEFAULT_PATH)

if (rostime_INCLUDE)
  set(ROSTIME_FOUND TRUE)
  message(STATUS "${Green}Found rostime include at: ${rostime_INCLUDE}${Reset}")
  file(GLOB rostime_SRCS
    ${PROJECT_SOURCE_DIR}/include/roscpp_core/rostime/src/*.cpp
  )
else()
  message(FATAL_ERROR "${Red}Failed to locate rostime module.${Reset}" )
endif()
