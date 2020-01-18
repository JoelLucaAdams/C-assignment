cmake_minimum_required(VERSION 3.15)
project(Membership_Program C)

set(CMAKE_C_STANDARD 11)

add_executable(Membership_Program main.c membership.h membership.c search_members.c print.c)