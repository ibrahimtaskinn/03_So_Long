# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: itaskin <itaskin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/26 15:43:08 by itaskin           #+#    #+#              #
#    Updated: 2022/05/26 15:43:11 by itaskin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = solong.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

MLX = -framework OpenGL -framework AppKit -L./mlx -lmlx

FRAMEWORK = ft_printf/libftprintf.a get_next_line/getnextline.a

SRC = $(wildcard *.c)

OBJ = $(SRC:.c=.o)

all : $(NAME) run

run: make-diff
	$(CC) $(CFLAGS) $(NAME) $(FRAMEWORK) $(MLX) -o so_long

make-diff:
	@make -C mlx
	@make -C ft_printf
	@make -C get_next_line

$(NAME) : $(OBJ)
	ar -rcs $(NAME) $(OBJ)

clean :
	rm -rf $(OBJ)
	@make clean -C mlx
	@make fclean -C ft_printf
	@make fclean -C get_next_line

fclean : clean
	rm -rf $(NAME) so_long

re : fclean all

.PHONY : all clean fclean re
