NAME = fdf_tests

#SRCS = main_fdf.c draw-fdf.c read-fdf.c hooks.c
SRCS = test_read-fdf.c
#SRCS +=
LIBFT_DIR = ./libft/
LIBFT = $(addprefix $(LIBFT_DIR), libft.a)

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

all: $(LIBFT) $(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(NAME): $(OBJS)
	cc $(FLAGS) $(OBJS) $(LIBFT) $(FLAGS_MLX) -o $@
#NEW:
#	cc $(FLAGS_MLX) $(OBJS) -I $(MINLBX_DIR) -o $@

clean:
	rm -f $(OBJS) $(BOBJS)
	@make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	@make fclean -C $(LIBFT_DIR)

re: fclean all

%.o: %.c
	@cc $(FLAGS) -c $< -o $@
#NEW:
#	cc $(FLAGS_MLX) -I $(MINLBX_DIR) -c $< -o $@


.PHONY: all clean fclean re
