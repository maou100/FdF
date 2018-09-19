# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: feedme <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/18 15:19:45 by feedme            #+#    #+#              #
#    Updated: 2018/08/16 21:41:59 by feedme           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

FLAGS = -Wall -Wextra -Werror -g
SRC = srcs/main.c srcs/parsing.c srcs/errors.c srcs/window.c srcs/ft_putline.c srcs/keyboard.c srcs/mouse.c
OBJ = $(patsubst %.c, %.o, $(SRC))

all: $(NAME)

$(NAME): $(OBJ) includes/fdf.h 
		make -C libft/
		gcc $(FLAGS) -I libft -c $(SRC)
		gcc -o $(NAME) $(OBJ) -I libft/ -I mlx/ libft/libft.a mlx/libmlx.a  -framework OpenGL -framework AppKit

clean:
	make -C libft/ clean
	rm -f $(OBJ) *.o

fclean: clean
	make -C libft/ fclean
	rm -f $(NAME)

re: fclean all
