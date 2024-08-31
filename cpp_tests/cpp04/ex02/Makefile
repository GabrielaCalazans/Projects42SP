# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/25 18:32:42 by gacalaza          #+#    #+#              #
#    Updated: 2024/08/30 21:29:21 by gacalaza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# =============== VARIABLES ===============

NAME = brain

CPP = c++

FLAGS = -Wall -Werror -Wextra -std=c++98

# =============== SOURCES FILES ===============

SRC	=	AAnimal.cpp Cat.cpp Dog.cpp Brain.cpp main.cpp

# =============== OBJECTS ===============
OBJECTS	=	$(SRC:.cpp=.o)

# =============== RECIPES ===============

all : $(NAME)

$(NAME) : $(OBJECTS)
	$(CPP) $(FLAGS) $(OBJECTS) -o $@

%.o: %.cpp
	$(CPP) $(FLAGS) -c $< -o $@

run:	all
		./$(NAME)

clean:
	$(RM) -rf $(OBJECTS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re