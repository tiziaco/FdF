# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/08 11:38:10 by tiacovel          #+#    #+#              #
#    Updated: 2024/01/11 16:36:29 by tiacovel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

UNAME := $(shell uname)

NAME = fdf
LIBFT_DIR = lib/libft
LIBFT	= lib/libft/libft.a

SRC =	src/main.c src/handle_events.c src/map.c  src/draw.c \
		src/matrix.c src/lst_utils.c src/utils.c src/transform.c

OBJ	= $(SRC:.c=.o)

RM		= rm -f
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
INCLUDE = -I include

ifeq ($(UNAME), Darwin)
    INCLUDE = -I /usr/X11/include
endif

all: $(NAME)

$(NAME): $(OBJ)
		@make -C lib/libft
		$(CC) $(OBJ) -Llib/mlx_linux -lmlx_Linux -L/usr/lib -Llib/libft -lft -Ilib/mlx_linux -lXext -lX11 -lm -lz -o $(NAME)

src/%.o: src/%.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

macos: $(OBJ)
	@echo "Checking if libft.a exists: $(wildcard $(LIBFT_DIR)/libft.a)"
	@if [ ! -f $(LIBFT_DIR)/libft.a ]; then \
 		echo "Building libft..."; \
		make -C $(LIBFT_DIR); \
	else \
		echo "libft.a already exists, skipping build."; \
	fi
	$(CC) $(OBJ) -g -L /usr/X11/lib -lX11 -lmlx -lXext -Llib/libft -lft -o $(NAME)

clean:
	@make clean -C lib/libft
	$(RM) $(OBJ)

fclean: clean
	@make fclean -C lib/libft
	$(RM) $(NAME)

re: fclean all

.PHONY: all macos clean fclean re