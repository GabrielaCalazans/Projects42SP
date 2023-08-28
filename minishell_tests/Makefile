# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/28 16:01:26 by gacalaza          #+#    #+#              #
#    Updated: 2023/08/28 16:17:09 by gacalaza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ==== Name of the program =====
NAME =	minishell
BONUS =	

# ======= Sources and objs ========
SRCS = 


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

FLAGS = -Wall -Wextra -Werror -O3

# =================== Rules ==========================

# # Compiling Mandatory or Bonus Objs
%.o: %.c
	$(CC) $(FLAGS) -I $(INCL_DIR) -c $< -o $@

all: comp_libft $(NAME)

$(OBJS): $(HEADERM)

$(BOBJS): $(HEADERB)

$(NAME): $(OBJS)
	cc $(FLAGS) $^ $(LIBFT) -o $@

$(BONUS): $(BOBJS)
	cc $(FLAGS) $^ $(LIBFT) -o $@
	@$(LIBS)

bonus: comp_libf $(BONUS)

re: fclean all

rebonus: fclean bonus

clean:
	@rm -rf $(BOBJS) $(OBJS)
	@make -C $(LIBFT_DIR) clean

fclean: clean
	@rm -rf $(NAME)
