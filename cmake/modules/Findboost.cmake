
find_path(boost_INCLUDE boost/config.hpp HINTS "/home/libei/gitlab/data_collection/thirdparty_lib/boost/include/" NO_DEFAULT_PATH)

if (boost_INCLUDE)
  set(BOOST_FOUND TRUE)
  message(STATUS "${Green}Found boost include at: ${boost_INCLUDE}${Reset}")
else()
  message(FATAL_ERROR "${Red}Failed to locate boost module.${Reset}" )
endif()
