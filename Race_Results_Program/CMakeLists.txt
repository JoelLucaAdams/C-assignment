cmake_minimum_required(VERSION 3.15)
project(Race_Results_Program C)

set(CMAKE_C_STANDARD 11)

add_executable(Race_Results_Program main.c race_results.h members.c race_results.c handicap.c)