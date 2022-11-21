# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gacalaza <gacalaza@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/04 17:03:39 by sguilher          #+#    #+#              #
#    Updated: 2022/11/21 13:21:04 by gacalaza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
# UPDATE THE FOLLOWING PATHS FOR THE TEST WORK WITH YOUR FT_PRINTF:
# **************************************************************************** #
# ft_printf source path - where is the makefile that compiles ft_printf
PRINTF_PATH =		../../

# libftprintf.a path
PRINTF =			$(PRINTF_PATH)libftprintf.a

# **************************************************************************** #

# test sources paths
TEST_PATH =			../test/
MANDATORY_PATH =	./mandatory/
UTILS_PATH =		./utils/
BONUS_CS_PATH =		./bonus/cs/
BONUS_DIU_PATH =	./bonus/diu/
BONUS_PX_PATH =		./bonus/px/

NAME =				mandatory.out
BONUS_CS = 			bonus_cs.out
BONUS_DIU = 		bonus_diu.out
BONUS_PX = 			bonus_px.out
UTILS =				$(wildcard $(UTILS_PATH)*.c)
TEST =				$(wildcard $(MANDATORY_PATH)*.c)
BONUS_CS_TEST =		$(wildcard $(BONUS_CS_PATH)*.c)
BONUS_DIU_TEST =	$(wildcard $(BONUS_DIU_PATH)*.c)
BONUS_PX_TEST =		$(wildcard $(BONUS_PX_PATH)*.c)

# compilation
CC =		clang -w
CFLAGS =	-Wall -Werror -Wextra
RM =		-rm -f

all:	m

m:		printf $(NAME) cat

bcs:	printf $(BONUS_CS) cat

bdiu:	printf $(BONUS_DIU) cat

bpx:	printf $(BONUS_PX) cat

printf:
		@cd $(PRINTF_PATH) && $(MAKE)

$(NAME):
	@$(CC) $(CFLAGS) $(TEST) $(UTILS) $(PRINTF) -o $@
	@./$@
	@$(RM) $@

$(BONUS_CS):
	@$(CC) $(CFLAGS) $(BONUS_CS_TEST) $(UTILS) $(PRINTF) -o $@
	@./$@
	@$(RM) $@

$(BONUS_DIU):
	@$(CC) $(CFLAGS) $(BONUS_DIU_TEST) $(UTILS) $(PRINTF) -o $@
	@./$@
	@$(RM) $@

$(BONUS_PX):
	@$(CC) $(CFLAGS) $(BONUS_PX_TEST) $(UTILS) $(PRINTF) -o $@
	@./$@
	@$(RM) $@

cat:
	@echo "\n"
	@echo "\033[1;33m             /\\_______/\\"
	@echo "            /           \\"
	@echo "           /   \033[1;36m<0   0>   \033[1;33m\\"
	@echo "          (    \033[1;37m=  \033[1;35mY  \033[1;37m=    \033[1;33m)"
	@echo "           \             /"
	@echo "           /    ~~~~~    \\"
	@echo "          /               \    (\\"
	@echo "         /        0        \    \\\\"
	@echo "        /  |      0      |  \    ))"
	@echo "       /   |   |  0  |   |   \  //"
	@echo "      /    |   |     |   |    \(("
	@echo "     (     |   |     |   |     )"
	@echo "      \\    |   |     |   |    /"
	@echo "       \\   |   |     |   |   /"
	@echo "        \\_(_;_;_)___(_;_;_)_/"
	@echo ""
	@echo "         by Sheela G. Khus=al\n"
	@echo ""

clean:
		@$(RM) $(NAME) $(BONUS)
		@cd $(PRINTF_PATH) && $(MAKE) $@

fclean:		clean
		@cd $(PRINTF_PATH) && $(MAKE) $@

re:			fclean all

.PHONY: all clean fclean re
