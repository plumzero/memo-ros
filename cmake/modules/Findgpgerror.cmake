
find_library(gpgerror_LIBRARY gpg-error HINTS  "${PROJECT_SOURCE_DIR}/libgpg-error/lib" "/usr/local/libgpg-error/lib" NO_DEFAULT_PATH)

find_path(gpgerror_INCLUDE gpg-error.h HINTS "${PROJECT_SOURCE_DIR}/libgpg-error/include" "/usr/local/libgpg-error/include" NO_DEFAULT_PATH)

if(gpgerror_LIBRARY AND gpgerror_INCLUDE)
    set(GPGERROR_FOUND TRUE)
    
    message(STATUS "${Green}Found gpg-error library at: ${gpgerror_LIBRARY}${Reset}")
    message(STATUS "${Green}Found gpg-error include at: ${gpgerror_INCLUDE}${Reset}")
else()
    message(FATAL_ERROR "${Red}Failed to locate gpg-error dependency.${Reset}")
endif()
