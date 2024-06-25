# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/25 18:32:42 by gacalaza          #+#    #+#              #
#    Updated: 2024/06/25 18:32:55 by gacalaza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# =============== VARIABLES ===============

NAME = megaphone

CPP = c++

FLAGS = -Wall -Werror -Wextra -std=c++98

# =============== SOURCES FILES ===============

SRC		=	megaphone.cpp

SOURCES =	$(SRC)


# =============== RECIPES ===============

all : $(NAME)

$(NAME) : 
	c++ $(FLAGS) $(SOURCES) -o $@

fclean :
	$(RM) $(NAME)

re : fclean all


.PHONY : all clean fclean re