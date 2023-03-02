NAME = fdf_tests

SRCS = test_nfdf.c nfdf.c hooks.c
#SRCS +=

FLAGS = -Wall \
		-Wextra \
		-Werror \
		-g3

FLAGS_MLX = -lmlx -lX11 -Imlx -lXext -lm

#beginNEW:
#FLAGS_MLX = -lmlx -lX11 -Imlx -lXext -lm
#FLAGS_MLX = -lmlx -lm
#MINLBX_DIR = /../../../usr/local/lib
#MINLBX = $(addprefix $(MINLBX_DIR), libmlx.a)
#endNEW

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	cc $(FLAGS) $(OBJS) $(FLAGS_MLX) -o $@
#NEW:
#	cc $(FLAGS_MLX) $(OBJS) -I $(MINLBX_DIR) -o $@

clean:
	rm -f $(OBJS) $(BOBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

%.o: %.c
	@cc $(FLAGS) -c $< -o $@
#NEW:
#	cc $(FLAGS_MLX) -I $(MINLBX_DIR) -c $< -o $@


.PHONY: all clean fclean re
