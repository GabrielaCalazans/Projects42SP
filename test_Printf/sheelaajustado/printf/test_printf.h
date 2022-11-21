/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_printf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 19:53:27 by sguilher          #+#    #+#             */
/*   Updated: 2021/08/18 20:14:04 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_PRINTF_H
# define TEST_PRINTF_H

# include "../test/utils/colors.h"
# include <stdio.h>
# include <unistd.h>

# define PURPLE(string)			"\033[38;5;200m" string "\033[0m"
# define PURPLE2(string)		"\033[0;35m" string "\033[0m"
# define LIGHT_PURPLE(string)	"\033[1;35m" string "\033[0m"
# define PINK(string)			"\033[38;5;212m" string "\033[0m"
# define LIGHT_RED(string)		"\033[1;31m" string "\033[0m"
# define RED(string)			"\033[38;5;196m" string "\033[0m"
# define GREEN(string)			"\033[0;32m" string "\033[0m"
# define GREEN2(string)			"\033[38;5;83m" string "\033[0m"
# define GREEN_BOLD(string)		"\033[1;32m" string "\033[0m"
# define GREEN3(string)		"\033[38;5;43m" string "\033[0m"
# define BLUE(string)			"\033[0;34m" string "\033[0m"
# define LIGHT_BLUE(string)		"\033[1;34m" string "\033[0m"
# define LIGHT_BLUE2(string)			"\033[38;5;75m" string "\033[0m"
# define CYAN(string)			"\033[0;36m" string "\033[0m"
# define LIGHT_CYAN(string)		"\033[1;36m" string "\033[0m"
# define YELLOW(string)			"\033[1;33m" string "\033[0m"
# define BROWN(string)			"\033[0;33m" string "\033[0m"
# define BLACK(string)			"\033[0;30m" string "\033[0m"
# define DARK_GREY(string)			"\033[38;5;240m" string "\033[0m"
# define GREY(string)			"\033[38;5;244m" string "\033[0m"
# define LIGHT_GREY(string)		"\033[0;37m" string "\033[0m"
# define WHITE(string)			"\033[1;37m" string "\033[0m"
# define RESET					"\033[0m"

# define NOT_OK	0
# define OK		1

#endif