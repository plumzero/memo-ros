
find_path(roscpp_serialization_INCLUDE ros/serialization.h HINTS "${PROJECT_SOURCE_DIR}/include/roscpp_core/roscpp_serialization/include" NO_DEFAULT_PATH)

if (roscpp_serialization_INCLUDE)
  set(ROSCPP_SERIALIZATION_FOUND TRUE)
  message(STATUS "${Green}Found roscpp_serialization include at: ${roscpp_serialization_INCLUDE}${Reset}")
  file(GLOB roscpp_serialization_SRCS
    ${PROJECT_SOURCE_DIR}/include/roscpp_core/roscpp_serialization/src/*.cpp
  )
else()
  message(FATAL_ERROR "${Red}Failed to locate roscpp_serialization module.${Reset}" )
endif()
