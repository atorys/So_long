cmake_minimum_required(VERSION 3.19)
project(solong C)

set(CMAKE_C_STANDARD 99)

add_executable(solong
        files/main.c
        get_next_line/get_next_line.c
        get_next_line/get_next_line_utils.c
        get_next_line/get_next_line.h
        files/main.c
        includes/so_long.h
        files/get_map.c
        libft/ft_putstr_fd.c
        libft/ft_putchar_fd.c files/render.c files/game.c includes/textures.h)