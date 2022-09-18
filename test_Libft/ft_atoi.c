/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 22:31:39 by gacalaza          #+#    #+#             */
/*   Updated: 2022/09/18 02:40:47 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *nptr)
{
	size_t	result;
	int		count;
	int		sign;

	count = 0;
	result = 0;
	sign = 1;
	while (!ft_isprint(str[count]) || str[count] == 32)
	{
		count++;
	}
	if (str[count] == '-' || str[count] == '+')
	{
		if (str[count] == '-')
			sign = -1;
		count++;
	}
	while (str[count] != '\0' && ft_isdigit(str[count]))
	{
		result = (result * 10) + (str[count] - '0');
		count++;
	}
	return (result * sign);
}
