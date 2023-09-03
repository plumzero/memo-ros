
find_path(cpp_common_INCLUDE ros/datatypes.h HINTS "${PROJECT_SOURCE_DIR}/include/roscpp_core/cpp_common/include" NO_DEFAULT_PATH)

if (cpp_common_INCLUDE)
  set(CPP_COMMON_FOUND TRUE)
  message(STATUS "${Green}Found cpp_common include at: ${cpp_common_INCLUDE}${Reset}")
  file(GLOB cpp_common_SRCS
    ${PROJECT_SOURCE_DIR}/include/roscpp_core/cpp_common/src/*.cpp
  )
else()
  message(FATAL_ERROR "${Red}Failed to locate cpp_common module.${Reset}" )
endif()
