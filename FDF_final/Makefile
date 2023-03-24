# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/21 15:56:04 by jaleman           #+#    #+#              #
#    Updated: 2023/03/24 18:25:29 by gacalaza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Name of the program
NAME = fdf

# Compiling flags
FLAGS = -Wall -Wextra -Werror -g
FLAGS_MLX = -lmlx -lX11 -Imlx -lXext -lm

# Folders
LIBFT_DIR = ./libft/
INCL_DIR = ./include/
INCL_BONUS = fdf_bonus.h keys_bonus.h

# Source files and object files
SRC_FILES = main.c fdf_read.c fdf_draw.c hooks.c draw_read_utils.c
B_SRC_FILES = main_bonus.c fdf_read.c fdf_draw_bonus.c hooks_bonus.c draw_read_utils.c
OBJ_FILES = $(SRC_FILES:.c=.o)
BOBJ_FILES = $(B_SRC_FILES:.c=.o)

# Paths
LIBFT = $(addprefix $(LIBFT_DIR), libft.a)
# INCLUDE = $(addprefix $(INCL_DIR), fdf.h)
# BONUS_INCLUDE = $(addprefix $(INCL_DIR), fdf_bonus.h)

all: $(LIBFT) $(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR)

# Compiling OBJ
%.o: %.c
	@echo "/(◕◕)\・ﾟ✧ MAKING OBJS, Please wait..."
#	$(CC) $(FLAGS) -c $<
	$(CC) $(FLAGS) -I $(INCL_DIR) -c $<
#		 @$(cc) $(flags) $< -I $(INCLUDE) -c

# Compiling FDF RESOLVER NO-PIE
$(NAME): $(OBJ_FILES)
	@echo "(◕◕)・ﾟ✧ Compiling mandatory... Wait a sec."
	@cc $(FLAGS) $(OBJ_FILES) $(LIBFT) $(FLAGS_MLX) -o $(NAME)
	@echo "(ﾉ•̀ᴗ•́)و $(NAME) generated!"

bonus: $(BOBJ_FILES)
	@echo "(◕◕)・ﾟ✧ Compiling bonus... Wait a sec."
	$(CC) $(FLAGS) $(BOBJ_FILES) $(LIBFT) $(FLAGS_MLX) -o $(NAME)
	@echo "(ﾉ•̀ᴗ•́)و $(NAME) bonus generated!"

clean:
	@rm -Rf $(OBJ_FILES) $(BOBJ_FILES)
	@make -C $(LIBFT_DIR) clean
	@echo "¯\_(ツ)_/¯ Objects removed!"

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean
	@echo "(ﾉ•̀ᴗ•́)・ﾟ✧$(NAME) removed!"


re: fclean all

.PHONY: all clean fclean re
