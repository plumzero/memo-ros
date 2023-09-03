
find_path(boost_INCLUDE boost/config.hpp HINTS "${PROJECT_SOURCE_DIR}/include" NO_DEFAULT_PATH)
find_library(boost_LIBRARY boost_thread HINTS "${PROJECT_SOURCE_DIR}/libs/boost" NO_DEFAULT_PATH)
get_filename_component(boost_LIBRARY ${boost_LIBRARY} PATH)

if (boost_INCLUDE AND boost_LIBRARY)
  set(BOOST_FOUND TRUE)
  message(STATUS "${Green}Found boost include(${boost_INCLUDE}) and library(${boost_LIBRARY})${Reset}")
else()
  message(FATAL_ERROR "${Red}Failed to locate boost module.${Reset}" )
endif()
