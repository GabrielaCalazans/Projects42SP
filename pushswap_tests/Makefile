# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/15 16:05:09 by gacalaza          #+#    #+#              #
#    Updated: 2023/05/18 22:44:47 by gacalaza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ======= COLORS ========
BLACK	=	\033[1;30m
RED		=	\033[1;31m
GREEN	=	\033[1;32m
YELLOW	=	\033[1;33m
BLUE	=	\033[1;34m
PURPLE	=	\033[1;35m
CYAN	=	\033[1;36m
WHITE	=	\033[1;37m
END_COL	=	\033[0m

# ==== Name of the program =====
NAME =	push_swap
BONUS =	push_swap_bonus

# ======= Sources and objs ========
SRCS = push_swap.c
OBJS = $(SRCS:.c=.o)

BSRC = 
BOBJS = $(BSRC:.c=.o)

# ====== Folders and Paths ========
LIBFT_DIR	= ./libft/
INCL_DIR	= ./include/
MANDATORY	= ./mandatory/
BONUS		= ./bonus/
LIBFT		= $(addprefix $(LIBFT_DIR), libft.a)
HEADERM		= $(addprefix $(INCL_DIR), push_swap.h)
HEADERB		= $(addprefix $(INCL_DIR), push_swap_bonus.h)
SRCS_MAN	= $(addprefix $(MANDATORY), $(SRCS))
BSRCS_BON	= $(addprefix $(BONUS), $(BSRCS))

# ====== Flags ========

FLAGS = -Wall -Wextra -Werror -g3

# ======================= Messages =====================================

COMP_LIFT	=	echo "\n🚀 $(YELLOW)Make:$(NO_COLOR)Starting the compilation...\n"
LIBS		=	echo "\n📂 $(GREEN)Libft$(NO_COLOR)OK!\n"
PS_READY	=	echo "\n📚 $(GREEN)push_swap ready!\n$(COLOUR_END)"
BPS_READY	=	echo "\n📚 $(GREEN)push_swap_bonus ready!\n$(COLOUR_END)"
RECOMP		=	echo "\n🔄 $(YELLOW)Recompilation done.\n$(COLOUR_END)"
RECOMPB		=	echo "\n🔄 $(YELLOW)Recompilation bonus done.\n$(COLOUR_END)"
CLEANED		=	echo "\n🧹 $(YELLOW)Clean:$(NO_COLOR)Removed all the \".o\" files \n"
FCLEANED	=	echo "\n🗑️ $(YELLOW)Fclean:$(NO_COLOR)ﾟ✧Removed the executablesﾟ✧ \n"
ERROR		=	echo "\n🚫 $(RED)Erro:$(NO_COLOR)File/Header not found ¯\_(ツ)_/¯"\n"

# =================== Rules ==========================

# # Compiling Mandatory or Bonus Objs
%.o: %.c
	$(CC) $(FLAGS) -I $(INCL_DIR) -c $< -o $@

all: comp_libft $(NAME)

$(OBJS): $(HEADERM)

$(BOBJS): $(HEADERB)

$(NAME): $(OBJS)
	cc $(FLAGS) $^ $(LIBFT) -o $@
	@$(PS_READY)

$(BONUS): $(BOBJS)
	cc $(FLAGS) $^ $(LIBFT) -o $@
	@$(BPS_READY)

comp_libft:
	@$(COMP_LIFT)
	@make -C $(LIBFT_DIR) --no-print-directory
	@$(LIBS)

bonus: comp_libf $(BONUS)

re: fclean all
	@$(RECOMP)

rebonus: fclean bonus
	@$(RECOMPB)

clean:
	@rm -rf $(BOBJS) $(OBJS)
	@make -C $(LIBFT_DIR) clean
	@$(CLEANED)

fclean: clean
	@rm -rf $(NAME)
	@make -C $(LIBFT_DIR) fclean
	@$(FCLEANED)


re:	fclean all

.PHONY: all clean fclean re comp_libft bonus rebonus
