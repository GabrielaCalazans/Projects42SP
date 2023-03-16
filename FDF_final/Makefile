# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/21 15:56:04 by jaleman           #+#    #+#              #
#    Updated: 2023/03/16 01:28:30 by gacalaza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Name of the program
NAME = fdf

# Compiling flags
FLAGS = -Wall -Wextra -Werror -g
FLAGS_MLX = -lmlx -lX11 -Imlx -lXext -lm

# Folders
LIBFT_DIR = ./libft/

# Source files and object files
SRC_FILES = main.c fdf_read.c fdf_draw.c hooks.c draw_read_utils.c
OBJ_FILES = $(SRC_FILES:.c=.o)

# Paths
LIBFT = $(addprefix $(LIBFT_DIR), libft.a)

all: $(LIBFT) $(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR)

# Compiling OBJ
%.o: %.c 
	@echo "¯\_(ツ)_/¯ MAKING OBJS, Please wait..."
	$(CC) $(FLAGS) -c $<

# Compiling FDF
$(NAME): $(OBJ_FILES)
	@echo "(ﾉ◕ヮ◕)ﾉ*:・ﾟ✧ Compiling... Wait a sec."
	@cc -no-pie $(FLAGS) $(OBJ_FILES) $(LIBFT) $(FLAGS_MLX) -o $(NAME)
	@echo "(•̀ᴗ•́)و $(NAME) generated!".

clean:
	@rm -Rf $(OBJ_FILES)
	@make -C $(LIBFT_DIR) clean
	@echo "¯\_(ツ)_/¯ Objects removed!"

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean
	@echo "(╯°□°）╯︵ ┻━┻ $(NAME) removed!"

re: fclean all

.PHONY: all clean fclean re
