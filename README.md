#printf


cmake:

    cmake_minimum_required(VERSION 3.17)   
    project(ft_printf_git2.0 C)

    set(CMAKE_C_STANDARD 99)


    file(GLOB LIBFT_FILES
    "lib/*.c"
    )
    set(SOURCES main.c git/ft_printf.c git/headers/ft_printf.h lib/libft.h)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror")

    add_library(my_libft STATIC ${LIBFT_FILES})
    add_executable(ft_printf_git2.0 ${SOURCES})

    target_link_libraries(ft_printf_git2.0  PUBLIC my_libft)

