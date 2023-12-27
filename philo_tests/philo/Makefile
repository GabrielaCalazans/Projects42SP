# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/28 16:01:26 by gacalaza          #+#    #+#              #
#    Updated: 2023/12/27 16:46:24 by gacalaza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ==== Name of the program =====
NAME =	philo

# ======= Sources ========
SRCS = philo.c ft_atoi.c ft_init.c
SRCS += philo_rotine.c ft_clean.c

# ====== Folders and Paths ========
INCL_DIR		= ./include/
HEADER			= $(addprefix $(INCL_DIR), philo.h)

MANDATORY	= $(SRCS) 

# ========== OBJS ============
OBJS = $(MANDATORY:.c=.o)

# ====== Flags ========
FLAGS = -Wall -Wextra -Werror -g3

LIBS = -lpthread

VALGRIND		=	valgrind \
					--leak-check=full \
					--show-leak-kinds=all \
					--quiet \
					--suppressions=readline.supp \
					--keep-debuginfo=yes \
					--trace-children=yes

# =================== Rules ==========================

# # Compiling Mandatory or Bonus Objs
%.o: %.c
	cc $(FLAGS) -I $(INCL_DIR) -c $< -o $@

all: $(NAME)

$(OBJS): $(HEADER)

$(NAME): $(OBJS)
	cc $(FLAGS) -I $(INCL_DIR) $^ $(LIBS) -o $@

run:	all
		./$(NAME)

valgrind:	all
			$(VALGRIND) ./$(NAME)

norminette:	all
			norminette

bonus: $(BONUS)

re: fclean all

rebonus: fclean bonus

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)
