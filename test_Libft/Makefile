# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gacalaza <gacalaza@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/12 19:45:45 by gacalaza          #+#    #+#              #
#    Updated: 2022/09/20 01:59:34 by gacalaza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_memchr.c
SRCS += ft_isprint.c ft_toupper.c ft_tolower.c ft_putchar_fd.c ft_putstr_fd.c
SRCS += ft_putnbr_fd.c ft_memcpy.c ft_memset.c ft_memmove.c ft_putendl_fd.c
SRCS += ft_strchr.c ft_strdup.c ft_strlen.c ft_bzero.c ft_strncmp.c ft_atoi.c
SRCS += ft_strnstr.c ft_strrchr.c ft_memcmp.c ft_strlcpy.c ft_strlcat.c ft_calloc.c

FLAGS = -Wall \
		-Wextra \
		-Werror

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	
$(OBJS): $(SRCS)
	cc $(FLAGS) -c $(SRCS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all