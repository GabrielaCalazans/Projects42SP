/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 23:16:29 by gacalaza          #+#    #+#             */
/*   Updated: 2022/11/13 00:29:01 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "libft/libft.h"
# define HEX_LOW "0123456789abcdef"
# define HEX_UPPER "0123456789ABCDEF"
# define UN_LI unsigned long int

int	ft_printf(const char *format, ...);
int	print_message(char c, va_list args);
int	intputchar(int c);
int	intputstr(char *s);
int	intputnbr(int n);
int	unsputnbr(unsigned int n);
int	puthex(int n);


#endif