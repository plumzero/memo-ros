
find_path(pluginlib_INCLUDE pluginlib/class_loader.hpp HINTS "${PROJECT_SOURCE_DIR}/include/pluginlib/include" NO_DEFAULT_PATH)

if (pluginlib_INCLUDE)
  set(PLUGINLIB_FOUND TRUE)
  message(STATUS "${Green}Found pluginlib include at: ${pluginlib_INCLUDE}${Reset}")
else()
  message(FATAL_ERROR "${Red}Failed to locate pluginlib module.${Reset}" )
endif()
