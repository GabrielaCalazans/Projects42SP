/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ctype.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 16:17:30 by coder             #+#    #+#             */
/*   Updated: 2022/09/06 02:24:27 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<unistd.h>
#include"libft.h"

static	void	ft_putchar(char c);
static	void	ft_putstr(char *str);

int	main(void)
{
	char	text[] = "GabCal%*+@as\\t351989	\bMeu =-seu.\n";
	int		count;

	ft_putstr(text);
	count = 0;
	while (count < ft_strlen(text))
	{
		if (ft_isalpha(text[count]))
		{
			printf("[%c]alp", text[count]);
		}
		if (ft_isdigit(text[count]))
		{
			printf("[%c]dig\n", text[count]);
		}
		if (ft_isdigit(text[count]))
		{
			printf("[%c]aln\n", text[count]);
		}
		if (ft_isascii(text[count]))
		{
			printf("[%c]ascii\n", text[count]);
		}
		if (ft_isprint(text[count]))
		{
			printf("[%c]printable\n", text[count]);
		}
		if (ft_toupper(text[count]))
		{
			printf("[%c]toupper\n", text[count]);
		}
		if (ft_tolower(text[count]))
		{
			printf("[%c]tolower\n", text[count]);
		}
		count++;
	}
	printf("%zu\n", ft_strlen(text));
	return (0);
}

static	void	ft_putstr(char *str)
{
	int	count;

	count = 0;
	while (str[count] != '\0')
	{
		ft_putchar(str[count]);
		count++;
	}
}

static	void	ft_putchar(char c)
{
	write(1, &c, 1);
}
