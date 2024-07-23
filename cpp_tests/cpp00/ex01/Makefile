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

NAME = phonebook

CPP = c++

FLAGS = -Wall -Werror -Wextra -std=c++98

# ==================================================

# ++++++++++ SOURCES DIRECTORIES ++++++++++

DIR_SOURCE	=	source/
# DIR_OBJECTS	=	source/objs/

# =============== SOURCES FILES ===============

SRC	=	PhoneBook.cpp Contact.cpp manipstr.cpp main.cpp
SRC	+=	setContact.cpp getContact.cpp

SOURCES =	$(SRC)

# =============== INCLUDES FILES ===============
INCLUDES =	includes/

# =============== SOURCES FILES + ITS DIRECTORIES ===============
SOURCES_F			= $(addprefix $(DIR_SOURCE), $(SOURCES))


# =============== OBJECTS ===============
OBJECTS = $(SOURCES_F:.cpp=.o)
# OBJECTS	=	$(patsubst %.cpp, $(OBJECTS_PATH)%.o, $(SOURCES))


# =============== INCLUDES FILES + ITS DIRECTORIES ===============
INCLUDES_F = $(addprefix -I, $(INCLUDES))


# =============== RECIPES ===============

all : $(NAME)

$(NAME) : $(OBJECTS)
	$(CPP) $(FLAGS) $(OBJECTS) -o $@
#	mv $(OBJECTS) $(DIR_OBJECTS)

$(OBJECTS) : $(DIR_OBJECTS)

# $(DIR_OBJECTS):
# 	mkdir -p $(DIR_OBJECTS)

%.o: %.cpp | $(DIR_OBJECTS)
	$(CPP) $(FLAGS) $(INCLUDES_F) -c $< -o $@

run:	all
		./$(NAME)

clean:
	$(RM) -rf $(OBJECTS) $(DIR_OBJECTS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re