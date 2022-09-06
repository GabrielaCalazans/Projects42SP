# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: coder <coder@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/04 20:14:55 by coder             #+#    #+#              #
#    Updated: 2022/09/05 22:15:35 by coder            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

#PATH_INCLUDE = -I "./includes/"

SRCS = ft_isalpha.c ft_isdigt.c ft_isalnum.c ft_isascii.c ft_isprint.c
#SRCS += ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c
#SRCS += ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolwer.c ft_strchr.c
#SRCS += ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c

FLAGS = -Wall \
		-Wextra \
		-Werror

OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	
$(OBJS): $(SRCS)
	gcc $(FLAGS) -c $(SRCS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all