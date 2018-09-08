# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amasol <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/07 12:48:51 by amasol            #+#    #+#              #
#    Updated: 2018/09/07 12:48:52 by amasol           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = filler

SRC = main.c ft_parsing.c outline.c

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	make -C ./libft/
	gcc $(CFLAGS) $(OBJ) -Llibft -lft -o $(NAME)

%.o: ./%.c
	gcc -o $@ -c $<

clean:
	make clean -C ./libft
	rm -f $(OBJ)

fclean: clean
	make fclean -C ./libft
	rm -f $(NAME)

re: fclean all
