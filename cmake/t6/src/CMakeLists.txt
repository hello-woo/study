#INCLUDE_DIRECTORIES(/usr/include)
#TARGET_LINK_LIBRARIES(curltest curl)
FIND_PACKAGE(CURL)
IF(CURL_FOUND)
    INCLUDE_DIRECTORIES(${CURL_INCLUDE_DIR})
    TARGET_LINK_LIBRARIES(curltest ${CURL_LIBRARY})
ELSE(CUEL_FOUND)
    MESSAGE(FATAL_ERROR "CURL library not found")
endif(CURL_FOUND)
add_executable(curltest main.c)
