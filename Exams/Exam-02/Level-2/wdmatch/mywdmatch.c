/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mywdmatch.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 17:56:42 by gacalaza          #+#    #+#             */
/*   Updated: 2023/05/03 18:11:04 by gacalaza         ###   ########.fr       */
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
	while (str[i] != '\0')
		i++;
	return (i);
}

int	main(int argc, char *argv[])
{
	int		i = 0;
	int		j = 0;
	int		count = 0;
	char	*str1;
	char	*str2;
	
	if (argc == 3)
	{
		str1 = argv[1];
		str2 = argv[2];
		int	len1 = ft_strlen(str1);

		while (str1[i] != '\0')
		{
			while (str2[j] != '\0')
			{
				if (str2[j] == str1[i])
				{
					count++;
					break ;
				}
				j++;
			}
			i++;
		}
		if (count == len1)
		{
			i = 0;
			while (str1[i] != '\0')
			{
				ft_putchar(str1[i]);
				i++;
			}
		}
	}
	ft_putchar('\n');
}
