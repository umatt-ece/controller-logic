cmake_minimum_required(VERSION 3.10)
project(TriCoreTest C CXX)

add_executable(test main.c)

message(STATUS "C Compiler: ${CMAKE_C_COMPILER}")
message(STATUS "CXX Compiler: ${CMAKE_CXX_COMPILER}")
