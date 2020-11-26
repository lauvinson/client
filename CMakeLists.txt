cmake_minimum_required(VERSION 3.17)
project(client C)

set(CMAKE_C_STANDARD 11)
link_libraries(ws2_32 wsock32)

add_executable(client main.c client.c client.h client_udp.c)