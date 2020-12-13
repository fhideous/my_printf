cmake_minimum_required(VERSION 3.17)
project(ft_printf_git2.0 C)
set(CMAKE_C_STANDARD 99)

##file(GLOB LIBFT_FILES
##        "lib/*.c"
##        )

#указывается полный путь до статической библиотеки
set(SOURCE_DIR /Users/fhideous/Desktop/fhideous/ft_printf_git2.0/git/libft/libft.a)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror")

set(SOURCES main.c git/ft_printf.c git/print_naked_line.c git/find_operation.c
        git/writing_specifier.c git/some_common_fun.c git/implement_operatios.c )
set(HEADERS git/headers/libft.h git/headers/ev_y_need_printf.h git/headers/ft_printf.h)

##add_library(my_libft STATIC ${LIBFT_FILES})
add_executable(ft_printf_git2.0 ${SOURCES} ${HEADERS})

##target_link_libraries(ft_printf_git2.0  PUBLIC my_libft)
target_link_libraries(ft_printf_git2.0  ${SOURCE_DIR})
