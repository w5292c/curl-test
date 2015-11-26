cmake_minimum_required (VERSION 2.6)

project (curl-test)

set ( CURL_TEST_TOP ${CMAKE_SOURCE_DIR}/ )
include_directories ("${CURL_TEST_TOP}/src/")

set ( SRC_LIST
  ${CURL_TEST_TOP}/src/main.c
)

# add the executable
add_executable ( curl-test ${SRC_LIST} )
