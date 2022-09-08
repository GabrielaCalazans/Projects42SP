/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ctypeH.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 16:17:30 by coder             #+#    #+#             */
/*   Updated: 2022/09/07 20:08:27 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<unistd.h>
#include"libft.h"

int	main(void)
{
	char	text[] = "GabCal%*+@as\\t351989	\bMeu =-seu.\n";
	int		count;

	ft_putstr_fd(text, 1);
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
