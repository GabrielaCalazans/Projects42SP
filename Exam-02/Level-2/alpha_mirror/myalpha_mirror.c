/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myalpha_mirror.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 17:05:26 by gacalaza          #+#    #+#             */
/*   Updated: 2023/04/28 18:20:15 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	main(int argc, char *argv[])
{
	int		i = 0;
	char	*str;

	if (argc == 2)
	{
		str = argv[1];
		while (str[i] != '\0')
		{
			if (str[i] >= 'a' && str[i] <= 'z')
				str[i] += (25 - ((str[i] - 'a') * 2));
			else if (str[i] >= 'A' && str[i] <= 'Z')
				str[i] += (25 - ((str[i] - 'A') * 2));
			ft_putchar(str[i]);
			i++;
		}
	}
	ft_putchar('\n');

}