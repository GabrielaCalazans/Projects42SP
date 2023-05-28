# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/15 16:05:09 by gacalaza          #+#    #+#              #
#    Updated: 2023/05/27 15:43:40 by gacalaza         ###   ########.fr        #
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
BUBBLE =	bubble_sort
SELECT =	select_sort

# ======= Sources and objs ========
SRCS_B = bubble_sort.c sort_utils.c
SRCS_S = select_sort.c sort_utils.c

# OBJS_B = $(SRCS_B:.c=.o)
# OBJS_S = $(SRCS_S:.c=.o)


# ====== Folders and Paths ========
INCLUDE	= sort_test.h

# ====== Flags ========

FLAGS = -Wall -Wextra -Werror -g3

# ======================= Messages =====================================

SELECT_READY	=	echo "\n🎯 $(YELLOW)SELECT:$(NO_COLOR)OK!...\n"
BUBBLE_READY	=	echo "\n🔀 $(GREEN)BUBBLE:$(NO_COLOR)OK!\n"


RECOMP		=	echo "\n🔄 $(YELLOW)Recompilation done.\n$(COLOUR_END)"
RECOMPB		=	echo "\n🔄 $(YELLOW)Recompilation bonus done.\n$(COLOUR_END)"
CLEANED		=	echo "\n🧹 $(YELLOW)Clean:$(NO_COLOR)Removed all the \".o\" files \n"
FCLEANED	=	echo "\n🗑️ $(YELLOW)Fclean:$(NO_COLOR)ﾟ✧Removed the executablesﾟ✧ \n"
ERROR		=	echo "\n🚫 $(RED)Erro:$(NO_COLOR)File/Header not found ¯\_(ツ)_/¯"\n"

# =================== Rules ==========================

# # Compiling Mandatory or Bonus Objs
bubble: $(BUBBLE)

$(BUBBLE):
	cc $(FLAGS) $(SRCS_B) -o $@
	@$(BUBBLE_READY)

select: $(SELECT)

$(SELECT):
	cc $(FLAGS) $(SRCS_S) -o $@
	@$(SELECT_READY)

clean:
	@rm -rf $(OBJS_B) $(OBJS_S)
	@$(CLEANED)

fclean: clean
	@rm -rf $(BUBBLE) $(SELECT)
	@$(FCLEANED)


.PHONY: bubble select clean fclean