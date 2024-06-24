# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/16 18:53:57 by gacalaza          #+#    #+#              #
#    Updated: 2024/03/30 14:22:17 by gacalaza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ==== Name of the program =====
NAME =	miniRT

# ======= Sources ========
SRCS = minirt.c 

# ====== Folders and Paths ========
LIBFT_DIR		= ./libft/
INCL_DIR		= ./include/
LIBFT			= $(addprefix $(LIBFT_DIR), libft.a)
HEADERM			= $(addprefix $(INCL_DIR), minirt.h)
SRCS_MAIN		= $(addprefix ./mandatory/, $(SRCS))


MANDATORY	:= $(SRCS_MAIN)

# ========== OBJS ============
OBJS = $(MANDATORY:.c=.o)

# ====== Flags ========
FLAGS = -Wall -Wextra -Werror -g3
FLAGS_MLX = -lmlx -lX11 -Imlx -lXext
LIBS = -lm
VALGRIND		=	valgrind \
					--leak-check=full \
					--show-leak-kinds=all \

# =================== Rules ==========================

# # Compiling Mandatory or Bonus Objs
%.o: %.c
	$(CC) $(FLAGS) -I $(INCL_DIR) -c $< -o $@

all: comp_libft $(NAME)

$(OBJS): $(HEADERM)

$(NAME): $(OBJS)
	cc $(FLAGS) -I $(INCL_DIR) $^ $(LIBFT) $(LIBS) -o $@


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

.PHONY: all clean fclean re libft bonus rebonus
