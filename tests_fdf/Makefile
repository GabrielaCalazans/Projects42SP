NAME = fdf_tests

SRCS = test.c
#SRCS +=

#BSRCS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c
#BSRCS += ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

FLAGS = -Wall \
		-Wextra \
		-Werror \
		-g3

FLAGS_MLX = -lmlx -lX11 -Imlx -lXext

OBJS = $(SRCS:.c=.o)

BOBJS = $(BSRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	cc $(CFLAGS) $^ $(FLAGS_MLX) -o $@

$(OBJS): $(SRCS)

#bonus: $(BOBJS)

#$(BOBJS): $(BSRCS)

clean:
	rm -f $(OBJS) $(BOBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

%.o: %.c
	@cc $(FLAGS) -c $< -o $@


.PHONY: all clean fclean re
