
find_path(rosconsole_INCLUDE ros/console.h HINTS "${PROJECT_SOURCE_DIR}/include/rosconsole/include" NO_DEFAULT_PATH)

if (rosconsole_INCLUDE)
  set(rosconsole_FOUND TRUE)
  message(STATUS "${Green}Found rosconsole include at: ${rosconsole_INCLUDE}${Reset}")
  file(GLOB rosconsole_SRCS
    ${PROJECT_SOURCE_DIR}/include/rosconsole/src/rosconsole/*.cpp
    ${PROJECT_SOURCE_DIR}/include/rosconsole/src/rosconsole/impl/rosconsole_print.cpp
  )
else()
  message(FATAL_ERROR "${Red}Failed to locate rosconsole module.${Reset}" )
endif()
