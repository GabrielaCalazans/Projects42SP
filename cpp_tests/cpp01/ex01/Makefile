# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/25 18:32:42 by gacalaza          #+#    #+#              #
#    Updated: 2024/07/20 18:38:47 by gacalaza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# =============== VARIABLES ===============

NAME = zombieHorde

CPP = c++

FLAGS = -Wall -Werror -Wextra -std=c++98

# ==================================================

# ++++++++++ SOURCES DIRECTORIES ++++++++++

DIR_SOURCE	=	source/
# DIR_OBJECTS	=	source/objs/

# =============== SOURCES FILES ===============

SRC	=	Zombie.cpp zombieHorde.cpp main.cpp

SOURCES =	$(SRC)

# =============== INCLUDES FILES ===============
INCLUDES =	includes/

# =============== SOURCES FILES + ITS DIRECTORIES ===============
SOURCES_F			= $(addprefix $(DIR_SOURCE), $(SOURCES))


# =============== OBJECTS ===============
OBJECTS	=	$(SOURCES_F:.cpp=.o)
# OBJECTS	=	$(patsubst %.cpp, $(DIR_OBJECTS)%.o, $(SOURCES_F))


# =============== INCLUDES FILES + ITS DIRECTORIES ===============
INCLUDES_F = $(addprefix -I, $(INCLUDES))


# =============== RECIPES ===============

all : $(NAME)

$(NAME) : $(OBJECTS)
	$(CPP) $(FLAGS) $(OBJECTS) -o $@
#	mv $(OBJECTS) $(DIR_OBJECTS)

# $(OBJECTS) : $(DIR_OBJECTS)

# $(DIR_OBJECTS):
# 	mkdir -p $(DIR_OBJECTS)

# %.o: %.cpp | $(DIR_OBJECTS)
%.o: %.cpp
	$(CPP) $(FLAGS) $(INCLUDES_F) -c $< -o $@

run:	all
		./$(NAME)

clean:
	$(RM) -rf $(OBJECTS) $(DIR_OBJECTS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re