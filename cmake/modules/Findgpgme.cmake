
find_library(gpgme_LIBRARY gpgme HINTS "${PROJECT_SOURCE_DIR}/gpgme/lib" "/usr/local/gpgme/lib" NO_DEFAULT_PATH)

find_path(gpgme_INCLUDE gpgme.h HINTS "${PROJECT_SOURCE_DIR}/gpgme/lib" "/usr/local/gpgme/include" NO_DEFAULT_PATH)

if(gpgme_LIBRARY AND gpgme_INCLUDE)
    set(GPGME_FOUND TRUE)
    
    message(STATUS "${Green}Found gpgme library at: ${gpgme_LIBRARY}${Reset}")
    message(STATUS "${Green}Found gpgme include at: ${gpgme_INCLUDE}${Reset}")
else()
    message(FATAL_ERROR "${Red}Failed to locate gpgme dependency.${Reset}")
endif()
