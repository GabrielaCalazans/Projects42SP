/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mylastword.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 15:07:05 by gacalaza          #+#    #+#             */
/*   Updated: 2023/05/01 15:29:03 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

int	ft_strlen(char *str)
{
	int	i = 0;

	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int	main(int argc, char *argv[])
{
	char	*str;

	if (argc == 2)
	{
		str = argv[1];
		int	len = ft_strlen(str) - 1;
		
		while ((str[len] >= 8 && str[len] <= 13) || str[len] == 32)
			len--;
		while (len > 0 && !((str[len] >= 8 && str[len] <= 13) || str[len] == 32))
			len--;
		int	i = len + 1;
		while (i > 0 && str[i] != '\0' && !((str[i] >= 8 && str[i] <= 13) || str[i] == 32))
		{
			ft_putchar(str[i]);
			i++;
		}
	}
	ft_putchar('\n');
}
