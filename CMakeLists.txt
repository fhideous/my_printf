cmake_minimum_required(VERSION 3.17)
project(ft_printf_git2.0 C)
set(CMAKE_C_STANDARD 99)

#указывается полный путь до статической библиотеки
set(SOURCE_DIR /Users/fhideous/Desktop/fhideous/printf3.0/git/libft/libft.a)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Werror")

set(SOURCES main.c git/src/ft_printf.c git/src/print_naked_line.c git/src/find_operation.c
        git/src/writing_specifier.c git/src/some_common_fun.c git/src/implement_operatios.c
        git/src/writing_c_arg.c git/src/writing_int_arg.c git/src/sstuff_hex.c
        git/src/writing_s_arg.c git/src/writing_hex_arg.c git/src/star_processing.c)

set(HEADERS git/headers/libft.h git/headers/ev_y_need_printf.h git/headers/ft_printf.h)

add_executable(ft_printf_git2.0 ${SOURCES})

target_link_libraries(ft_printf_git2.0  ${SOURCE_DIR})
