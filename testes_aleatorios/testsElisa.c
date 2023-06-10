/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testsElisa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 14:50:45 by gacalaza          #+#    #+#             */
/*   Updated: 2023/06/10 15:17:32 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort_test.h"

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

int	ft_strlen(char *str)
{
	int	len = 0;

	if (!str)
		return (0);
	while (str[len] != '\0')
		len++;
	return (len);
}

int	ft_strlen_ptr(char *str)
{
	int	len = 0;
	
	if (!str)
		return (0);
	while (*str++)
		len++;
	return (len);
}

char	*str_rev(char *str)
{
	int	len = ft_strlen(str) - 1;
	
	while (str[len] != '\0') // ou (len >= 0) 
	{
		ft_putchar(str[len]);
		len--;
	}
	return (str);
}

int	main()
{
	char	*str1 = "GABRIELA";
	char	str2[] = {"GABRIELA" " CALAZANS"};
	int		len1 = ft_strlen(str1);
	int		len2 = ft_strlen_ptr(str1);

	printf("str1: %s \t str2: %s \n", str1, str2);
	printf("len1: %d \t len2: %d \n", len1, len2);

	str_rev(str2);
	ft_putchar('\n');

	str_rev(str1);
	ft_putchar('\n');

	return 0;
}