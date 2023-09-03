
find_path(roscpp_traits_INCLUDE ros/message_traits.h HINTS "${PROJECT_SOURCE_DIR}/include/roscpp_core/roscpp_traits/include" NO_DEFAULT_PATH)

if (roscpp_traits_INCLUDE)
  set(ROSCPP_TRAITS_FOUND TRUE)
  message(STATUS "${Green}Found roscpp_traits include at: ${roscpp_traits_INCLUDE}${Reset}")
else()
  message(FATAL_ERROR "${Red}Failed to locate roscpp_traits module.${Reset}" )
endif()
