cmake_minimum_required(VERSION 3.17)
project(ft_printf_git2.0 C)
set(CMAKE_C_STANDARD 99)

##file(GLOB LIBFT_FILES
##        "lib/*.c"
##        )

#указывается полный путь до статической библиотеки
set(SOURCE_DIR /home/fhideous/CLionProjects/my_printf/libft/libft.a)
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror")

set(SOURCES main.c src/ft_printf.c src/print_naked_line.c src/find_operation.c
        src/writing_specifier.c src/some_common_fun.c src/implement_operatios.c)

set(HEADERS headers/libft.h headers/ev_y_need_printf.h headers/ft_printf.h)

##add_library(my_libft STATIC ${LIBFT_FILES})
add_executable(ft_printf_git2.0 ${SOURCES} ${HEADERS})

##target_link_libraries(ft_printf_git2.0  PUBLIC my_libft)
target_link_libraries(ft_printf_git2.0  ${SOURCE_DIR})
