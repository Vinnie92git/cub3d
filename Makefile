# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rcastano <rcastano@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/05 15:58:33 by vini              #+#    #+#              #
#    Updated: 2024/09/03 13:44:14 by rcastano         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RM = rm -f

CC = gcc
FLAGS_MLX = -Lmlx -lmlx -Llibft -lft -lX11 -lXext -lm -lz
FLAGS = -Wall -Wextra -Werror #-g3 -fsanitize=address

LIBFT= -L libft -lft

NAME = Cub3D
SRC = src/main.c src/parser.c src/parser_utils.c src/parser_utils_2.c \
		src/map_validation.c src/info_validation.c src/data_initialisation.c \
		src/render.c src/keys.c src/raycasting.c src/raycast_utils.c \
		src/utils.c src/utils_2.c

OBJ = $(SRC:.c=.o)

%.o: %.c
	$(CC) $(FLAGS) $(FLAGS_MLX) -c -o $@ $<

#%.o: %.c
#	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft
	$(CC) $(OBJ) $(FLAGS) $(FLAGS_MLX) $(LIBFT) -o $(NAME)

clean:
	$(RM) $(OBJ)
	make clean -C libft

fclean: clean
	$(RM) $(NAME)
	make fclean -C libft

re: fclean all

.PHONY: bonus all clean fclean re
