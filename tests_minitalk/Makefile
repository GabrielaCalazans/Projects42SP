# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/15 16:05:09 by gacalaza          #+#    #+#              #
#    Updated: 2023/04/24 11:19:08 by gacalaza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ======= COLORS ========
BLACK = \033[1;30m
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
BLUE = \033[1;34m
PURPLE = \033[1;35m
CYAN = \033[1;36m
WHITE = \033[1;37m
END_COL = \033[0m

# ==== Name of the program =====
CLIENT_NAME	=	client
SERVER_NAME	=	server
NAME		=	minitalk
SERVER_BONUS = server_bonus
CLIENT_BONUS = client_bonus

# ======= Sources and objs ========
SERVER_SRC	= ./mandatory/server.c
CLIENT_SRC	= ./mandatory/client.c
SERVER_OBJ = $(SERVER_SRC:.c=.o)
CLIENT_OBJ = $(CLIENT_SRC:.c=.o)

SERVER_BSRC = ./bonus/server_bonus.c
CLIENT_BSRC = ./bonus/client_bonus.c
SERVER_BOBJ = $(SERVER_BSRC:.c=.o)
CLIENT_BOBJ = $(CLIENT_BSRC:.c=.o)

HEADERM		= ./include/minitalk.h
HEADERB		= ./include/minitalk_bonus.h

FLAGS = -Wall -Wextra -Werror -g3

# ====== Folders and Paths ========
LIBFT_DIR = ./libft/
INCL_DIR = ./include/
LIBFT = $(addprefix $(LIBFT_DIR), libft.a)

# ======================= Messages =====================================

COMP_LIFT	=	echo "\n🚀 $(YELLOW)Make: $(NO_COLOR)Starting the compilation...\n"
LIBS		=	echo "\n🚀 $(GREEN)Libft$(NO_COLOR)OK!\n"
SERV_READY	=	echo "\n🖥️ $(GREEN)Server ready!\n$(COLOUR_END)"
CLI_READY	=	echo "\n📱 $(GREEN)Client ready!\n$(COLOUR_END)"
SERVB_READY	=	echo "\n🖥️ $(GREEN)Server_bonus ready!\n$(COLOUR_END)"
CLIB_READY	=	echo "\n📱 $(GREEN)Client_bonus ready!\n$(COLOUR_END)"
RECOMP		=	echo "\n🔄 $(YELLOW)Recompilation done.\n$(COLOUR_END)"
RECOMPB		=	echo "\n🔄 $(YELLOW)Recompilation bonus done.\n$(COLOUR_END)"
CLEANED		=	echo "\n🗑️ $(YELLOW)Clean: $(NO_COLOR)Removed all the \".o\" files \n"
FCLEANED	=	echo "\n🧹 $(YELLOW)Fclean: $(NO_COLOR)ﾟ✧Removed the executablesﾟ✧ \n"
ERROR		=	echo "\n🚫 $(RED)Erro: $(NO_COLOR)File/Header not found ¯\_(ツ)_/¯"\n"

# =================== Rules ==========================

all: $(NAME)

$(NAME): comp_libft $(SERVER_NAME) $(CLIENT_NAME)

comp_libft:
	@$(COMP_LIFT)
	@make -C $(LIBFT_DIR) --no-print-directory

$(SERVER_NAME): $(SERVER_OBJ)
	@cc $(FLAGS) $^ $(LIBFT) -o $@
	@$(SERV_READY)

$(CLIENT_NAME): $(CLIENT_OBJ)
	@cc $(FLAGS) $^ $(LIBFT) -o $@
	@$(CLI_READY)

bonus: comp_libft $(SERVER_BONUS) $(CLIENT_BONUS)

$(SERVER_BONUS): $(SERVER_BOBJ)
	@cc $(FLAGS) $^ $(LIBFT) -o $@
	@$(SERV_READY)

$(CLIENT_BONUS): $(CLIENT_BOBJ)
	@cc $(FLAGS) $^ $(LIBFT) -o $@
	@$(CLI_READY)

re: fclean all
	@$(RECOMP)

rebonus: fclean bonus
	@$(RECOMPB)

clean:
	@rm -rf $(CLIENT_OBJ) $(SERVER_OBJ) $(CLIENT_BOBJ) $(SERVER_BOBJ)
	@make -C $(LIBFT_DIR) clean
	@$(CLEANED)

fclean: clean
	@rm -rf $(SERVER_NAME) $(CLIENT_NAME) $(SERVER_BONUS) $(CLIENT_BONUS)
	@make -C $(LIBFT_DIR) fclean
	@$(FCLEANED)

# Compiling Mandatory or Bonus Objs
./mandatory/%.o: ./mandatory/%.c $(HEADERM)
	$(CC) $(FLAGS) -I $(INCL_DIR) -c $< -o $@

./bonus/%.o: ./bonus/%.c $(HEADERB)
	$(CC) $(FLAGS) -I $(INCL_DIR) -c $< -o $@

re:	fclean all

.PHONY: all ft_server ft_client clean fclean re comp_libft ft_client_bonus ft_server_bonus bonus