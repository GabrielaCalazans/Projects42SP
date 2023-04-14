# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/04 19:29:58 by gacalaza          #+#    #+#              #
#    Updated: 2023/04/13 16:02:51 by gacalaza         ###   ########.fr        #
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
SERVER_SRC = test_server.c
CLIENT_SRC = test_client.c
SERVER_OBJS = $(SERVER_SRC:.c=.o)
CLIENT_OBJS = $(CLIENT_SRC:.c=.o)

# SERVER_BSRC = test_server.c
# CLIENT_BSRC = test_client.c
# SERVER_BOBJS = $(B_SRCS:.c=.o)
# CLIENT_BOBJS = $(B_SRCS:.c=.o)

# Compiling flags
FLAGS = -Wall -Wextra -Werror -O3


all: libft $(NAME)

# Compiling Mandatory OBJS
%.o:%.c ./include/minitalk.h
	@echo "/(◕◕)\・ﾟ✧ MAKING OBJS, Please wait..."
	$(CC) $(FLAGS) -I $(INCL_DIR) -c $< -o $@

# Compiling
$(NAME): $(SERVER) $(CLIENT)
	@echo "$(COLOUR_GREEN)Client and Server created$(COLOUR_END)"

$(SERVER): $(SERVER_OBJS) libft
	@echo "(◕◕)・ﾟ✧ Compiling mandatory... Wait a sec."
	@$(CC) $(FLAGS) $(SERVER_OBJS) $(LIBFT) -o $(SERVER)

$(CLIENT): $(CLIENT_OBJS) libft
	@$(CC) $(CLIENT_OBJS) $(LIBFT) -o $(CLIENT)

bonus: libft $(BONUS)

# Compiling BONUS OBJS
# ./bonus/%.o: ./bonus/%.c ./include/minitalk_bonus.h
# 	@echo "/(◕◕)\・ﾟ✧ MAKING OBJS, Please wait..."
# 	$(CC) $(FLAGS) -I $(INCL_DIR) -c $< -o $@

# $(BONUS): $(BOBJS)
# 	@echo "(◕◕)・ﾟ✧ Compiling bonus... Wait a sec."
# 	@cc $(FLAGS) $(BOBJS) $(LIBFT) -o $(BONUS)
# 	@echo "$(COLOUR_GREEN)Client_bonus and Server_bonus created$(COLOUR_END)"

libft:
	@make -C $(LIBFT_DIR) --no-print-directory

clean:
	@rm -Rf $(CLIENT_OBJS) $(SERVER_OBJS)
	@make -C $(LIBFT_DIR) clean
	@echo "¯\_(ツ)_/¯ Objects removed!"

fclean: clean
	@rm -f $(NAME) $(SERVER) $(CLIENT) $(BONUS) $(SERVER_BONUS) $(CLIENT_BONUS)
	@make -C $(LIBFT_DIR) fclean
	@echo "$(COLOUR_BLUE)All clean$(COLOUR_END)"

re: fclean all

rebonus: fclean bonus

.PHONY: all clean fclean re libft bonus rebonus
