cmake_minimum_required(VERSION 2.8)

project(http_server CXX)

set(CMAKE_CXX_COMPILER "g++")
set(CMAKE_CXX_FLAGS "-g -pthread -std=c++11 ")


find_library(muduo_base muduo_base)
find_library(muduo_net muduo_net)
message(STATUS ${muduo_base})
message(STATUS ${muduo_net})

add_executable(out test.cc  HttpServer.cc  HttpResponse.cc HttpContext.cc)

target_link_libraries(out ${muduo_net})
target_link_libraries(out ${muduo_base})
target_link_libraries(out pthread rt)