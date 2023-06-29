# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/15 16:05:09 by gacalaza          #+#    #+#              #
#    Updated: 2023/06/28 16:27:48 by gacalaza         ###   ########.fr        #
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
SRCS = push_swap.c push.c swap.c rotate.c rev_rotate.c 
SRCS += check_args.c check_args_utils.c start.c general_utils.c letfunbegin.c
SRCS += letthefunbegin_utils.c
SRCS += dealing_lst_one.c dealing_lst_two.c dealing_lst_one.c dealing_lst_three.c
SRCS += check_stacks.c do_moves.c

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

COMP_LIFT	=	echo "\n🚀 Make: Starting the compilation...\n"
LIBS		=	echo "\n📂 Libft OK!\n"
PS_READY	=	echo "\n📚 push_swap ready!\n"
BPS_READY	=	echo "\n📚 push_swap_bonus ready!\n"
RECOMP		=	echo "\n🔄 Recompilation done.\n"
RECOMPB		=	echo "\n🔄 Recompilation bonus done.\n"
CLEANED		=	echo "\n🧹 Clean: Removed all the \".o\" files \n"
FCLEANED	=	echo "\n🗑️ Fclean: ﾟ✧Removed the executablesﾟ✧ \n"
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

limpo: all clean
	clear

re:	fclean all

.PHONY: all clean fclean re comp_libft bonus rebonus limpo
