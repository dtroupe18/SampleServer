cmake_minimum_required(VERSION 3.6)
project(SampleServer)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES server.c client.c)
add_executable(SampleServer ${SOURCE_FILES})