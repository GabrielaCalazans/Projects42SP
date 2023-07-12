/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myprinthex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 23:11:57 by gacalaza          #+#    #+#             */
/*   Updated: 2023/05/11 00:49:45 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

int	ft_atoi(char *str)
{
	int	i = 0;
	int	digit = 0;
	int	result = 0;

	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
			digit = str[i] - '0';
		result *= 10;
		result += digit;
		i++;
	}
	return(result);
}

void	printhex(int numb)
{
	char	*hex = "0123456789abcdef";

	if (numb >= 16)
	{
		printhex(numb / 16);
	}
	ft_putchar(hex[numb % 16]);
}

int	main(int argc, char *argv[])
{
	int		numb;

	if (argc == 2)
	{
		if (argv[1][0] == '-')
		{
			ft_putchar('\n');
			return 0;
		}
		numb = ft_atoi(argv[1]);
		printhex(numb);
	}
	ft_putchar('\n');
	return 0;
}
