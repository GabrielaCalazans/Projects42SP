# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/25 18:32:42 by gacalaza          #+#    #+#              #
#    Updated: 2024/06/25 19:17:31 by gacalaza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# =============== VARIABLES ===============

NAME = phonebook

CPP = c++

FLAGS = -Wall -Werror -Wextra -std=c++98

# ==================================================

# ++++++++++ SOURCES DIRECTORIES ++++++++++

DIR_SOURCE	=	source/

# =============== SOURCES FILES ===============

SRC		=	phonebook.cpp

SOURCES =	$(SRC)

# =============== INCLUDES FILES ===============
INCLUDES =	includes/

# =============== SOURCES FILES + ITS DIRECTORIES ===============
SOURCES_F			= $(addprefix $(DIR_SOURCE), $(SOURCES))

# =============== INCLUDES FILES + ITS DIRECTORIES ===============
INCLUDES_F = $(addprefix -I, $(INCLUDES))

# =============== RECIPES ===============

all : $(NAME)

$(NAME) : 
	$(CPP) $(FLAGS) $(INCLUDES_F) $(SOURCES_F) -o $@

fclean :
	$(RM) $(NAME)

re : fclean all


.PHONY : all clean fclean re