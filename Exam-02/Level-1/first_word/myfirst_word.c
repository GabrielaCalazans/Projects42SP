/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myfirst_word.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 22:30:03 by gacalaza          #+#    #+#             */
/*   Updated: 2023/04/28 00:06:52 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	main(int argc, char *argv[])
{
	char	*str;
	int		i = 0;

	if (argc == 2)
	{
		str = argv[1];
		while (str[i] != '\0')
		{
			if(!(str[i] == 32 || str[i] == 9))
			{
				while (!(str[i] == 32 || str[i] == 9))
				{
					ft_putchar(str[i]);
					i++;
				}
				// break ;
			}
			i++;
		}
	}
	ft_putchar('\n');
	return 0;
}