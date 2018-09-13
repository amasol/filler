cmake_minimum_required(VERSION 3.7)
project(filler_new)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c)
add_executable(filler_new ${SOURCE_FILES}
        outline.c
        ft_supportive.c
        ft_parsing.c
        main.c
        outline_and_stroke.c
        libft/ft_atoi.c
        libft/ft_isdigit.c
        libft/ft_memalloc.c
        libft/ft_bzero.c
        libft/ft_putchar.c
        libft/ft_putnbr.c
        libft/ft_strdup.c
        libft/ft_strsub.c
        libft/ft_strsplit.c
        libft/ft_strlen.c
        libft/get_next_line.c
        libft/ft_strchr.c
        libft/ft_strcpy.c
        libft/ft_strjoin.c
        libft/ft_strnew.c
        libft/ft_strcat.c
        libft/ft_strncpy.c)