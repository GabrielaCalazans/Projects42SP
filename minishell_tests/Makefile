# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/28 16:01:26 by gacalaza          #+#    #+#              #
#    Updated: 2023/09/24 14:08:14 by gacalaza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ==== Name of the program =====
NAME =	minishell

# ======= Sources and objs ========
SRCS = minishell.c prompt.c execution.c builtins.c parse.c
SRCS += token.c token_utils_one.c token_utils_two.c
SRCS += handling_lst.c

OBJS = $(SRCS_MAN:.c=.o)

# ====== Folders and Paths ========
LIBFT_DIR	= ./libft/
INCL_DIR	= ./include/
MANDATORY	= ./mandatory/
BONUS		= ./bonus/
LIBFT		= $(addprefix $(LIBFT_DIR), libft.a)
HEADERM		= $(addprefix $(INCL_DIR), minishell.h)
HEADERB		= $(addprefix $(INCL_DIR), minishell_bonus.h)
SRCS_MAN	= $(addprefix $(MANDATORY), $(SRCS))

# ====== Flags ========

FLAGS = -Wall -Wextra -Werror -g3
LIBS = -lreadline
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
	$(CC) $(FLAGS) -I $(INCL_DIR) -c $< -o $@

all: comp_libft $(NAME)

$(OBJS): $(HEADERM)

$(NAME): $(OBJS)
	cc $(FLAGS) $^ $(LIBFT) $(LIBS) -o $@


comp_libft:
	@make -C $(LIBFT_DIR) --no-print-directory

run:	all
		./$(NAME)

valgrind:	all
			$(VALGRIND) ./$(NAME)

norminette:	all
			norminette

bonus: comp_libf $(BONUS)

re: fclean all

rebonus: fclean bonus

clean:
	@rm -rf $(OBJS)
	@make -C $(LIBFT_DIR) clean

fclean: clean
	@rm -rf $(NAME)
	@make -C $(LIBFT_DIR) fclean
