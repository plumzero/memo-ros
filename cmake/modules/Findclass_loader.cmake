
find_path(class_loader_INCLUDE class_loader/multi_library_class_loader.hpp HINTS "${PROJECT_SOURCE_DIR}/class_loader/include/" NO_DEFAULT_PATH)

if (class_loader_INCLUDE)
  set(CLASS_LOADER_FOUND TRUE)
  message(STATUS "${Green}Found class_loader include at: ${class_loader_INCLUDE}${Reset}")
  file(GLOB class_loader_SRCS
    ${PROJECT_SOURCE_DIR}/class_loader/src/multi_library_class_loader.cpp
  )
else()
  message(FATAL_ERROR "${Red}Failed to locate class_loader module.${Reset}" )
endif()
