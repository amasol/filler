cmake_minimum_required(VERSION 3.9)
project(filler_git C)

set(CMAKE_C_STANDARD 99)

add_executable(filler_git main.c
        filler.h
        ft_parsing.c
        libft/get_next_line.c
        libft/get_next_line.h
        libft/ft_strchr.c
        libft/ft_strdel.c
        libft/ft_strdup.c
        libft/ft_strjoin.c
        libft/ft_strlen.c
        libft/ft_strnew.c
        libft/ft_bzero.c
        libft/ft_strsub.c
        libft/ft_atoi.c
        libft/ft_isdigit.c
        libft/ft_isspace)