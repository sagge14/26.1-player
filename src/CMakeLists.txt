cmake_minimum_required(VERSION 3.22)

add_executable(player main.cpp player.cpp  ${MY_INCLUDE_DIR}/player.h)

target_include_directories(player PUBLIC ${MY_INCLUDE_DIR})