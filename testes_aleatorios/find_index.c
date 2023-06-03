/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_index.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 16:14:57 by gacalaza          #+#    #+#             */
/*   Updated: 2023/06/03 16:43:46 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <unistd.h>
# include <stdlib.h>
#include <stdio.h>

void	ft_putendl_fd(char *s, int fd)
{
	int	count;

	count = 0;
	while (s[count] != '\0')
	{
		write(fd, &s[count], 1);
		count++;
	}
	if (s[count] == '\0')
	{
		write(fd, "\n", 1);
	}
}


int	ft_isdigit(int argument)
{
	if (argument >= '0' && argument <= '9')
		return (1);
	else
		return (0);
}

void	ft_puterror(void)
{
	ft_putendl_fd("Error", 1);
	exit(1);
}

int	ft_atoi_error(const char *nptr)
{
	long	result;
	int		count;
	int		sign;

	count = 0;
	result = 0;
	sign = 1;
	while ((nptr[count] >= 9 && nptr[count] <= 13) || nptr[count] == 32)
		count++;
	if (nptr[count] == '-' || nptr[count] == '+')
	{
		if (nptr[count] == '-')
			sign = -1;
		count++;
	}
	while (nptr[count] != '\0' && ft_isdigit(nptr[count]))
	{
		result = (result * 10) + (nptr[count] - '0');
		count++;
	}
	if ((sign * result) > 2147483647 || (sign * result) < -2147483648)
		ft_puterror();
	return (result * sign);
}

int	find_index(char **str, int nbr)
{
	int	index;
	int	comp;
	int	i;

	index = 0;
	i = 1;
	if (!str)
		return (0);
	while (str[i] != NULL)
	{
		comp = ft_atoi_error(str[i]);
		if (comp < nbr)
			index++;
		i++;
	}
	return (index);
}

int	main(int argc, char *argv[])
{
	int	nbr;
	int	index;
	int	i;

	if (argc > 2)
	{
		i = 1;
		index = 0;
		while (argv[i] != NULL)
		{
			nbr = atoi(argv[i]);
			index = find_index(argv, nbr);
			i++;
			printf("Index: %d, Number: %d\n", index, nbr);
		}
	}
	else
		printf ("\t*** Insufficient number of args ***\n");
	return 0;
}