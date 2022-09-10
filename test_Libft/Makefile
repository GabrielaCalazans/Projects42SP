# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: coder <coder@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/04 20:14:55 by coder             #+#    #+#              #
#    Updated: 2022/09/11 00:27:40 by coder            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_memchr.c
SRCS += ft_isprint.c ft_toupper.c ft_tolower.c ft_putchar_fd.c ft_putstr_fd.c
SRCS += ft_putnbr_fd.c ft_memcpy.c ft_memset.c ft_memmove.c ft_putendl_fd.c
SRCS += ft_strchr.c ft_strdup.c ft_strlen.c ft_bzero.c ft_strncmp.c
#SRCS += ft_strlcpy.c ft_strlcat.c ft_strrchr.c
#SRCS += ft_memcmp.c ft_strnstr.c ft_atoi.c

FLAGS = -Wall \
		-Wextra \
		-Werror

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	
$(OBJS): $(SRCS)
	gcc $(FLAGS) -c $(SRCS) $(PATH_INCLUDE)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all