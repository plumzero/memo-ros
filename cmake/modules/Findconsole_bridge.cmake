
find_path(console_bridge_INCLUDE console_bridge/console_bridge_export.h HINTS "${PROJECT_SOURCE_DIR}/include/" NO_DEFAULT_PATH)

if (console_bridge_INCLUDE)
  set(CONSOLE_BRIDGE_FOUND TRUE)
  message(STATUS "${Green}Found console_bridge include at: ${console_bridge_INCLUDE}${Reset}")
  file(GLOB console_bridge_SRCS
    ${PROJECT_SOURCE_DIR}/include/console_bridge/*.cpp
  )
else()
  message(FATAL_ERROR "${Red}Failed to locate console_bridge module.${Reset}" )
endif()
