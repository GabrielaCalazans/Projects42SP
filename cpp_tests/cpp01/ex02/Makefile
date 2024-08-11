# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/24 14:05:54 by gacalaza          #+#    #+#              #
#    Updated: 2024/08/10 14:04:42 by gacalaza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# =============== VARIABLES ===============

NAME = brain

CPP = c++

FLAGS = -Wall -Werror -Wextra -std=c++98

# =============== SOURCES FILES ===============

SRC		=	main.cpp

SOURCES =	$(SRC)


# =============== RECIPES ===============

all : $(NAME)

$(NAME) : 
	c++ $(FLAGS) $(SOURCES) -o $@

fclean :
	$(RM) $(NAME)

re : fclean all


.PHONY : all clean fclean re