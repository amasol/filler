# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amasol <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/14 14:23:58 by amasol            #+#    #+#              #
#    Updated: 2018/09/14 14:24:12 by amasol           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = filler

SRC = ft_parsing.c\
	  outline.c\
	  outline_and_stroke.c\
	  ft_supportive.c\
	  start.c\
	  main.c

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	make -C ./libft/
	gcc $(CFLAGS) $(OBJ) -Llibft -lft -o $(NAME)

%.o: ./%.c
	gcc $(CFLAGS) -o $@ -c $<

clean:
	make clean -C ./libft
	rm -f $(OBJ)

fclean: clean
	make fclean -C ./libft
	rm -f $(NAME)

re: fclean all
