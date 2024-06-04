# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/08 11:38:10 by tiacovel          #+#    #+#              #
#    Updated: 2024/06/04 16:18:35 by tiacovel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Main executable
NAME = fdf

# Get the operative system name
OS := $(shell uname)

# Libft library
LIBFT_PATH = lib/libft
LIBFT_FLAGS = -Llib/libft -lft

# MLX library
MLX_PATH = lib/mlx
MLX_FLAGS = -Llib/mlx -lmlx -L/usr/lib/X11 -lXext -lX11 -lm
INCLUDE = -I/usr/include -Ilib/mlx

ifeq ($(OS), Darwin)
    INCLUDE = -I /usr/X11/include
    MLX_FLAGS = -L/usr/X11/lib -lX11 -lmlx -lXext
endif

# Source files directory
SRCDIR = src
# Object files directory
OBJDIR = obj

# Source files (excluding main.c and test files)
SRC = $(wildcard $(SRCDIR)/**/*.c) $(wildcard $(SRCDIR)/*.c)

RM		= rm -f
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

# Object files
OBJ = $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRC))

# Color and styles
COLOR_RESET = \033[0m
BOLD_GREEN = \033[1;32m
GREEN = \033[0;32m
RED = \033[0;31m
HIDE = @

all: dependencies $(NAME)

dependencies:
	@echo "$(GREEN)Checking dependencies...$(COLOR_RESET)"
    # Check if mlx has been downloaded
    ifeq ($(wildcard $(MLX_PATH)/*),)
		@git submodule update --init --recursive
		@echo "$(GREEN)Submodules downloaded.$(COLOR_RESET)"
    endif
    # Check if libft has been downloaded
    ifeq ($(wildcard $(LIBFT_PATH)/*),)
		@git submodule update --init --recursive
		@echo "$(GREEN)Submodules downloaded.$(COLOR_RESET)"
    endif

    # Check if libft is compiled
    ifeq ($(wildcard $(LIBFT_PATH)/libft.a),)
		@make -s -C $(LIBFT_PATH)
    endif
	@echo "$(GREEN)Libft compiled ✅$(COLOR_RESET)"

    # Check if mlx is compiled
    ifeq ($(wildcard $(MLX_PATH)/libmlx.a),)
		@make -s -C $(MLX_PATH)
    endif
	@echo "$(GREEN)Mlx compiled ✅$(COLOR_RESET)"

$(NAME): $(OBJDIR) $(OBJ)
	@$(CC) $(OBJ) $(LIBFT_FLAGS) $(MLX_FLAGS) -o $(NAME)
	@echo "$(BOLD_GREEN)Program Compiled 🔥$(COLOR_RESET)"

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) $(INCLUDE) -c -o $@ $<

$(OBJDIR):
	@mkdir -p $(OBJDIR)


# macos: $(OBJ)
# 	@if [ ! -f $(LIBFT_DIR)/libft.a ]; then \
#  		echo "Building libft..."; \
# 		make -C $(LIBFT_DIR); \
# 	else \
# 		echo "libft.a already exists, skipping build."; \
# 	fi
# 	$(CC) $(OBJ) -g -L /usr/X11/lib -lX11 -lmlx -lXext -Llib/libft -lft -o $(NAME)

clean:
	@rm -rf $(OBJDIR) $(EXECUTABLE)
	@cd $(LIBFT_PATH) && make -s clean
	@echo "$(RED) Objects removed$(COLOR_RESET)"

fclean: clean
	@rm -f $(NAME)
	@rm -f $(MLX_PATH)/*.a
	@cd $(LIBFT_PATH) && make -s fclean
	@echo "$(RED) Full clean$(COLOR_RESET)"

re: fclean all

.PHONY: all clean fclean re