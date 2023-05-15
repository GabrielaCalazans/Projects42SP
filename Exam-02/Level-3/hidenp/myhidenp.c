/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myhidenp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 17:38:36 by gacalaza          #+#    #+#             */
/*   Updated: 2023/05/10 17:56:59 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

int	main(int argc, char *argv[])
{
	int		i = 0;
	int		check = 0;
	int		len = 0;
	int		j = 0;
	char	*str1;
	char	*str2;

	if (argc == 3)
	{
		str1 = argv[1];
		str2 = argv[2];

		while (str1[len] != '\0')
			len++;
		while (str1[i]!= '\0')
		{
			while (str2[j] != '\0')
			{
				if (str1[i] == str2[j])
				{
					check++;
					break ;
				}
				j++;
			}
			i++;
		}
		if(len == check)
			ft_putchar('1');
		else
			ft_putchar('0');
	}
	ft_putchar('\n');
}
