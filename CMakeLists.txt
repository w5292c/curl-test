cmake_minimum_required (VERSION 2.6)

project (curl-test)

find_package ( PkgConfig REQUIRED )

pkg_check_modules ( CURL        libcurl     REQUIRED )
link_directories ( ${CURL_LIBRARY_DIRS} )

set ( CURL_TEST_TOP ${CMAKE_SOURCE_DIR}/ )
include_directories ( "${CURL_TEST_TOP}/src/" ${CURL_INCLUDE_DIRS} )

set ( SRC_LIST
  ${CURL_TEST_TOP}/src/main.c
)

# add the executable
add_executable ( curl-test ${SRC_LIST} )
target_link_libraries ( curl-test ${CURL_LIBRARIES} )
