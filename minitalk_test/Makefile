# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/04 19:29:58 by gacalaza          #+#    #+#              #
#    Updated: 2023/04/04 20:02:29 by gacalaza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

COLOUR_GREEN=\033[0;32m
COLOUR_RED=\033[0;31m
COLOUR_BLUE=\033[0;34m
COLOUR_END=\033[0m

# Name of the program
NAME = minitalk
SERVER = server
CLIENT = client

# Bonus 
BONUS = minitalk_bonus
SERVER_BONUS = server_bonus
CLIENT_BONUS = client_bonus

# Folders
LIBFT_DIR = ./libft/
INCL_DIR = ./include/

# Paths
LIBFT = $(addprefix $(LIBFT_DIR), libft.a)

# Source files and object files
SRC = mandatory/.c
SRC += 
# B_SRC = 
# B_SRC += 

OBJS = $(SRC:.c=.o)
# BOBJS = $(B_SRCS:.c=.o)

# Compiling flags
FLAGS = -Wall -Wextra -Werror -O3

all: libft $(NAME)

libft:
	@make -C $(LIBFT_DIR) --no-print-directory

# Compiling OBJ
./mandatory/%.o: ./mandatory/%.c ./include/minitalk.h
	@echo "/(◕◕)\・ﾟ✧ MAKING OBJS, Please wait..."
	$(CC) $(FLAGS) -I $(INCL_DIR) -c $< -o $@

# Compiling BONUS OBJ
./bonus/%.o: ./bonus/%.c ./include/minitalk_bonus.h
	@echo "/(◕◕)\・ﾟ✧ MAKING OBJS, Please wait..."
	$(CC) $(FLAGS) -I $(INCL_DIR) -c $< -o $@

# Compiling
$(NAME): $(SERVER) $(CLIENT)
	@echo "(◕◕)・ﾟ✧ Compiling mandatory... Wait a sec."
	@cc $(FLAGS) $(OBJ_FILES) $(LIBFT) -o $(NAME)
	@echo "$(COLOUR_GREEN)Client and Server created$(COLOUR_END)"

bonus: libft $(BONUSFDF)

$(BONUSFDF): $(BOBJ_FILES)
	@echo "(◕◕)・ﾟ✧ Compiling bonus... Wait a sec."
	@cc $(FLAGS) $(BOBJ_FILES) $(LIBFT) -o $(BONUSFDF)
	@echo "$(COLOUR_BLUE)Client_bonus and Server_bonus created$(COLOUR_END)"

clean:
	@rm -Rf $(OBJ_FILES) $(BOBJ_FILES)
	@make -C $(LIBFT_DIR) clean
	@echo "¯\_(ツ)_/¯ Objects removed!"

fclean: clean
	@rm -f $(NAME) $(BONUSFDF)
	@make -C $(LIBFT_DIR) fclean
	@echo "(•̀ᴗ•́)・ﾟ✧$(NAME) and $(BONUSFDF) removed!"

re: fclean all

rebonus: fclean bonus

.PHONY: all clean fclean re libft bonus rebonus
