# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/25 18:32:42 by gacalaza          #+#    #+#              #
#    Updated: 2024/08/23 20:08:19 by gacalaza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# =============== VARIABLES ===============

NAME = fightTime

CPP = c++

FLAGS = -Wall -Werror -Wextra -std=c++98

# ==================================================

# ++++++++++ SOURCES DIRECTORIES ++++++++++

DIR_SOURCE	=	source/
# DIR_OBJECTS	=	source/objs/

# =============== SOURCES FILES ===============

SRC	=	HumanA.cpp HumanB.cpp main.cpp Weapon.cpp

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

INCLUDES_A = $(wildcard ./includes/*)

# =============== RECIPES ===============

all : $(NAME)

$(NAME) : $(OBJECTS)
	$(CPP) $(FLAGS) $(OBJECTS) -o $@
#	mv $(OBJECTS) $(DIR_OBJECTS)

# $(OBJECTS) : $(DIR_OBJECTS)

# $(DIR_OBJECTS):
# 	mkdir -p $(DIR_OBJECTS)

# %.o: %.cpp | $(DIR_OBJECTS)
%.o: %.cpp $(INCLUDES_A)
	$(CPP) $(FLAGS) $(INCLUDES_F) -c $< -o $@

run:	all
		./$(NAME)

clean:
	$(RM) -rf $(OBJECTS) $(DIR_OBJECTS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re