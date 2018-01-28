cmake_minimum_required(VERSION 3.5)

project(http_server)


SET(CMAKE_CXX_FLAGS "-std=c++11 -g")
#SET(SRC_LIST test.cc HttpContext.cc HttpResponse.cc HttpServer.cc HttpRequest.hpp)
SET(CMAKE_CXX_COMPILER)

find_library(muduo_net muduo_net)
find_library(muduo_base muduo_base)

MESSAGE(STATUS ${muduo_net})
MESSAGE(STATUS ${muduo_base})

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/../bin)
MESSAGE(STATUS ${PROJECT_BINARY_DIR})

add_executable(http_server httpd.cc HttpContext.cc HttpResponse.cc HttpServer.cc HttpRequest.hpp Util.hpp)


target_link_libraries(http_server ${muduo_net})
target_link_libraries(http_server ${muduo_base})
target_link_libraries(http_server pthread)
