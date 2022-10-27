# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gacalaza <gacalaza@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/12 19:45:45 by gacalaza          #+#    #+#              #
#    Updated: 2022/10/18 04:12:25 by gacalaza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = gnl

SRCS = ft_putnbr_fd.c ft_putendl_fd.c ft_putchar_fd.c ft_putstr_fd.c

FLAGS = -Wall \
		-Wextra \
		-Werror

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@ar rcs $(NAME)

$(OBJS): $(SRCS)
	@cc $(FLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

# run: $(NAME)
# 	./gnl
# 	@echo Done!

.PHONY: all clean fclean re run