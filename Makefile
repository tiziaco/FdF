# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/08 11:38:10 by tiacovel          #+#    #+#              #
#    Updated: 2024/01/08 14:26:23 by tiacovel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
LIBFT	= lib/libft/libft.a

SRC = src/main.c src/handle_events.c src/map.c src/matrix.c src/lst_utils.c

OBJ	= $(SRC:.c=.o)

RM		= rm -f
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
INCLUDE = -I include

all: $(NAME)

$(NAME): $(OBJ)
		@make -C lib/libft
		$(CC) $(OBJ) -Llib/mlx_linux -lmlx_Linux -L/usr/lib -Llib/libft -lft -Ilib/mlx_linux -lXext -lX11 -lm -lz -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	@make clean -C lib/libft
	$(RM) $(OBJ)

fclean: clean
	@make fclean -C lib/libft
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re