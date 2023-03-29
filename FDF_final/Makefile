# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/21 15:56:04 by jaleman           #+#    #+#              #
#    Updated: 2023/03/29 15:48:24 by gacalaza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Name of the program
NAME = fdf

# Folders
LIBFT_DIR = ./libft/
INCL_DIR = ./include/
BONUSFDF = fdf_bonus

# Paths
LIBFT = $(addprefix $(LIBFT_DIR), libft.a)

# Source files and object files
SRC_FILES = mandatory/main.c mandatory/fdf_read.c mandatory/fdf_draw.c mandatory/hooks.c mandatory/draw_read_utils.c
B_SRC_FILES = ./bonus/main_bonus.c ./bonus/fdf_read_bonus.c ./bonus/fdf_draw_bonus.c ./bonus/hooks_bonus.c ./bonus/draw_read_utils_bonus.c
OBJ_FILES = $(SRC_FILES:.c=.o)
BOBJ_FILES = $(B_SRC_FILES:.c=.o)

# Compiling flags
FLAGS = -Wall -Wextra -Werror -O3
FLAGS_MLX = -lmlx -lX11 -Imlx -lXext -lm

all: libft $(NAME)

libft:
	make -C $(LIBFT_DIR)

# Compiling OBJ
%.o: %.c
	@echo "/(◕◕)\・ﾟ✧ MAKING OBJS, Please wait..."
	$(CC) $(FLAGS) -I $(INCL_DIR) -c $< -o $@

# Compiling FDF
$(NAME): $(OBJ_FILES)
	@echo "(◕◕)・ﾟ✧ Compiling mandatory... Wait a sec."
	@cc $(FLAGS) $(OBJ_FILES) $(LIBFT) $(FLAGS_MLX) -o $(NAME)
	@echo "(ﾉ•̀ᴗ•́)و $(NAME) generated!"

# bonus:
#	make SRC_FILES = $(BOBJ_FILES)

# bonus: libft $(BOBJ_FILES)
# 	@echo "(◕◕)・ﾟ✧ Compiling bonus... Wait a sec."
# 	$(CC) $(FLAGS) $(BOBJ_FILES) $(LIBFT) $(FLAGS_MLX) -o $(NAME)
# 	@echo "(ﾉ•̀ᴗ•́)و $(NAME) bonus generated!"

bonus: libft $(BONUSFDF)

$(BONUSFDF): $(BOBJ_FILES)
#	 ar rcs $(BONUSFDF) $^
	@echo "(◕◕)・ﾟ✧ Compiling bonus... Wait a sec."
	@cc $(FLAGS) $(BOBJ_FILES) $(LIBFT) $(FLAGS_MLX) -o $(BONUSFDF)
	@echo "(ﾉ•̀ᴗ•́)و $(NAME) bonus generated!"

clean:
	@rm -Rf $(OBJ_FILES) $(BOBJ_FILES)
	@make -C $(LIBFT_DIR) clean
	@echo "¯\_(ツ)_/¯ Objects removed!"

fclean: clean
	@rm -f $(NAME) $(BONUSFDF)
	@make -C $(LIBFT_DIR) fclean
	@echo "(ﾉ•̀ᴗ•́)・ﾟ✧$(NAME) and $(BONUSFDF) removed!"

re: fclean all

rebonus: fclean bonus

.PHONY: all clean fclean re libft rebonus
