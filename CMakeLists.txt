cmake_minimum_required(VERSION 3.16)
project(kryptus_challenge C)

set(CMAKE_C_STANDARD 11)
add_compile_options(-Wall -Wextra -pedantic -Werror)
add_executable(kryptus_challenge prompt.c)