# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/24 14:05:54 by gacalaza          #+#    #+#              #
#    Updated: 2024/06/24 15:22:13 by gacalaza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# =============== VARIABLES ===============

NAME = cpp

CC = -std=c++98

FLAGS = -Wall -Werror -Wextra

# ==================================================

# ++++++++++ SOURCES DIRECTORIES ++++++++++

DIR_SOURCE	=	source/

# =============== SOURCES FILES ===============

SOURCES		=	megaphone.cpp

# =============== INCLUDES FILES ===============
INCLUDES =	includes/


# =============== SOURCES FILES + ITS DIRECTORIES ===============
SOURCES_F			= $(addprefix $(DIR_SOURCE), $(SOURCES))

# =============== INCLUDES FILES + ITS DIRECTORIES ===============
INCLUDES_F = $(addprefix -I, $(INCLUDES))

SOURCES =	$(SOURCES)




# =============== RECIPES ===============

all : $(NAME)

all : $(NAME)

$(NAME) : $(LIBS) $(OBJECTS)
	$(CC) $(OBJECTS) -o $@

%.o : %.c
	$(CC) $(FLAGS) $(INCLUDES_F) -MMD -c $< -o $@

clean :
	$(RM) $(OBJECTS)
	$(RM) $(DEPENDS)

fclean : clean
	$(RM) $(NAME)

re : fclean all


.PHONY : all clean fclean re bonus