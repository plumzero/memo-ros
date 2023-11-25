
find_library(assuan_LIBRARY assuan HINTS "${PROJECT_SOURCE_DIR}/libassuan/lib" "/usr/local/libassuan/lib" NO_DEFAULT_PATH)

find_path(assuan_INCLUDE assuan.h HINTS "${PROJECT_SOURCE_DIR}/libassuan/include" "/usr/local/libassuan/include" NO_DEFAULT_PATH)

if(assuan_LIBRARY AND assuan_INCLUDE)
    set(ASSUAN_FOUND TRUE)
    
    message(STATUS "${Green}Found assuan library at: ${assuan_LIBRARY}${Reset}")
    message(STATUS "${Green}Found assuan include at: ${assuan_INCLUDE}${Reset}")
else()
    message(FATAL_ERROR "${Red}Failed to locate assuan dependency.${Reset}")
endif()
