cmake_minimum_required(VERSION 3.21.1)
project(Haojixing_Electronic_Dictionary C)

set(CMAKE_C_STANDARD 11)

add_executable(Haojixing_Electronic_Dictionary main.c public.c public.h user.c user.h admin.c admin.h List.c List.h ConsoleLib.h ConsoleLib.cpp draw.h draw.c)
