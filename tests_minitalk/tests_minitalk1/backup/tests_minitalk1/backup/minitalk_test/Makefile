# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/15 16:05:09 by gacalaza          #+#    #+#              #
#    Updated: 2023/04/15 17:15:08 by gacalaza         ###   ########.fr        #
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
SERVER_NAME	=	server
CLIENT_NAME	=	client
NAME		=	server

# ======= Sources and objs ========
SERVER_SRC	= server.c
CLIENT_SRC	= client.c
SERVER_OBJ = $(SERVER_SRC:.c=.o)
CLIENT_OBJ = $(CLIENT_SRC:.c=.o)

SERVER_BSRC = server_bonus.c
CLIENT_BSRC = client_bonus.c
SERVER_BOBJ = $(SERVER_BSRC:.c=.o)
CLIENT_BOBJ = $(CLIENT_BSRC:.c=.o)

HEADER1		= ./include/minitalk.h
HEADER2		= ./include/minitalk_bonus.h

# ====== Folders and Paths ========
LIBFT_DIR = ./libft/
INCL_DIR = ./include/
LIBFT = $(addprefix $(LIBFT_DIR), libft.a)

# ======================= Messages =====================================

COMP_LIFT	=	echo "\n🚀 $(YELLOW)Make: $(NO_COLOR)Starting the compilation...\n"
SERV_READY	=	echo "\n📥 $(GREEN)Server ready!\n$(COLOUR_END)"
CLI_READY	=	echo "\n📟 $(GREEN)Client ready!\n$(COLOUR_END)"
CLEANED		=	echo "\n🗑️ $(YELLOW)Clean: $(NO_COLOR)Removed all the \".o\" files \n"
FCLEANED	=	echo "\n🧹 $(YELLOW)Fclean: $(NO_COLOR)Removed the executables \n"
ERROR		=	echo "\n🚫 $(RED)Erro: $(NO_COLOR)Arquivo de cabeçalho não encontrado"\n"

# ============= Rules =============

all: $(NAME)

$(NAME): comp_libft ft_server ft_client

comp_libft:
	@$(COMP_LIFT)
	@make -C $(LIBFT_DIR) --no-print-directory

ft_server: $(SERVER_OBJ)
	@cc $(FLAGS) $(SERVER_OBJ) $(LIBFT) -o $(SERVER_NAME)
	@$(SERV_READY)

ft_client: $(CLIENT_OBJ)
	@cc $(FLAGS) $(CLIENT_OBJ) $(LIBFT) -o $(CLIENT_NAME)
	@$(CLI_READY)

clean:
	@rm -rf $(CLIENT_OBJ) $(SERVER_OBJ)
	@make -C $(LIBFT_DIR) clean
	@$(CLEANED)

fclean: clean
	@rm -rf $(SERVER_NAME) $(CLIENT_NAME)
	@make -C $(LIBFT_DIR) fclean
	@$(FCLEANED)

# Compiling BONUS OR MANDATORY OBJS
.c.o:
	@if [ -e $(HEADER1) ] || [ -e $(HEADER2) ]; then \
		@cc $(FLAGS) -I $(INCL_DIR) -c $< -o $@; \
	else \
	@$(ERROR); \
		exit 1; \
	fi

re:	fclean all

.PHONY: all minitalk server client clean fclean re libft