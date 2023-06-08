# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/15 16:05:09 by gacalaza          #+#    #+#              #
#    Updated: 2023/06/08 16:14:14 by gacalaza         ###   ########.fr        #
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
BUBBLE		=	bubble_sort
SELECT		=	select_sort
INSERTION	=	insertion_sort
QUICK	=		quick_sort
HEAP	=		heap_sort

# ======= Sources and objs ========
SRCS_B = bubble_sort.c sort_utils.c
SRCS_S = select_sort.c sort_utils.c
SRCS_I = insertion_sort.c sort_utils.c
SRCS_Q = quick_sort.c sort_utils.c
SRCS_H = heap_sort.c sort_utils.c

# OBJS_B = $(SRCS_B:.c=.o)
# OBJS_S = $(SRCS_S:.c=.o)
# OBJS_I = $(SRCS_I:.c=.o)
# OBJS_Q = $(SRCS_Q:.c=.o)
# OBJS_H = $(SRCS_H:.c=.o)

# ====== Folders and Paths ========
INCLUDE	= sort_test.h

# ====== Flags ========

FLAGS = -Wall -Wextra -Werror -g3

# ======================= Messages =====================================

SELECT_READY	=	echo "\n🎯 SELECT: OK!...\n"
BUBBLE_READY	=	echo "\n🎈 BUBBLE: OK!\n"
INSERTION_READY	=	echo "\n🔑 INSERTION: OK!\n"
QUICK_READY	=		echo "\n🔀 QUICK: OK!\n"
HEAP_READY	=		echo "\n📦 HEAP: OK!\n"

RECOMP		=	echo "\n🔄 Recompilation done.\n"
RECOMPB		=	echo "\n🔄 Recompilation bonus done.\n"
CLEANED		=	echo "\n🧹 Clean: Removed all the \".o\" files \n"
FCLEANED	=	echo "\n🗑️ Fclean: ﾟ✧Removed the executablesﾟ✧ \n"
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

insertion: $(INSERTION)

$(INSERTION):
	cc $(FLAGS) $(SRCS_I) -o $@
	@$(INSERTION_READY)

quick: $(QUICK)

$(QUICK):
	cc $(FLAGS) $(SRCS_Q) -o $@
	@$(QUICK_READY)

heap: $(HEAP)

$(HEAP):
	cc $(FLAGS) $(SRCS_H) -o $@
	@$(HEAP_READY)

rebubble: fclean bubble

reselect: fclean select

reinsertion: fclean insertion

requick: fclean quick

reheap: fclean heap

clean:
	@rm -rf $(OBJS_B) $(OBJS_S) $(OBJS_I) $(OBJS_Q) $(OBJS_H) a.out
	@$(CLEANED)

fclean: clean
	@rm -rf $(BUBBLE) $(SELECT) $(INSERTION) $(QUICK) $(HEAP)
	@$(FCLEANED)


.PHONY: bubble select insertion heap clean fclean