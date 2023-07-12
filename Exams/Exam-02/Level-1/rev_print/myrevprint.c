/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myrevprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 02:13:00 by gacalaza          #+#    #+#             */
/*   Updated: 2023/05/20 15:26:27 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	if (!str)
		return (0);
	while (str[len] != '\0')
		len++;
	return (len);
}

int	main(int argc, char *argv[])
{
	if (argc == 2)
	{
		int	len = ft_strlen(argv[1]);
		while (len > 0)
		{
			len--;
			ft_putchar(argv[1][len]);
		}
	}
	ft_putchar('\n');
	return (0);
}