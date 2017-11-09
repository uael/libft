cmake_minimum_required(VERSION 3.1 FATAL_ERROR)
cmake_policy(SET CMP0054 OLD)
cmake_policy(SET CMP0045 OLD)

project(libft C)

set(BUILD_SHARED_LIBS OFF)

set(libft_INC_DIR ${CMAKE_CURRENT_LIST_DIR})
set(libft_SRC_DIR ${CMAKE_CURRENT_LIST_DIR})

set(CMAKE_C_FLAGS "")
set(CMAKE_C_FLAGS_DEBUG "")
set(CMAKE_C_FLAGS_RELEASE "")

option(COVERAGE "Turn on COVERAGE support" OFF)
if (COVERAGE AND NOT MSVC)
  set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} --coverage")
endif ()

file(GLOB libft_SRCS ${libft_SRCS} ${libft_SRC_DIR}/ft_*.c)

add_library(ft ${libft_SRCS} libft.h)
set_property(TARGET ft PROPERTY C_STANDARD 90)
target_include_directories(ft PUBLIC ${libft_INC_DIR})
target_compile_definitions(ft PRIVATE U_COMPILE)

target_compile_definitions(ft
  PRIVATE $<$<CONFIG:Debug>:DEBUG>$<$<CONFIG:Release>:NDEBUG>
  PRIVATE API_COMPILE)
if (MSVC)
  target_compile_options(ft
    PRIVATE /MT$<$<CONFIG:Debug>:d> /Oy /W3
    PRIVATE /D_CRT_SECURE_NO_WARNINGS /Dinline=__inline
    PRIVATE /O$<$<CONFIG:Debug>:d>$<$<CONFIG:Release>:x>)
else ()
  target_compile_options(ft
    PRIVATE -Wall -Werror -Wextra -fomit-frame-pointer -ansi
    PRIVATE -Wno-missing-field-initializers -Wno-missing-braces
    PRIVATE -O$<$<CONFIG:Debug>:0 -g3>$<$<CONFIG:Release>:3>)
endif ()
