/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 17:23:02 by gacalaza          #+#    #+#             */
/*   Updated: 2023/03/21 17:28:23 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int	ft_atoh(char *hex)
{
	int	len;
	int	base;
	int	dec;

	len = strlen(hex) - 1;
	base = 1;
	dec = 0;
	while (len >= 0)
	{
		if (hex[len] >= '0' && hex[len] <= '9')
			dec += (hex[len] - 48) * base;
		if (hex[len] >= 'A' && hex[len] <= 'F')
			dec += (hex[len] - 55) * base;
		if (hex[len] >= 'a' && hex[len] <= 'f')
			dec += (hex[len] - 87) * base;
		base *= 16;
		len--;
	}
	return (dec);
}

int main()
{
	char *hex1 = "0xff";
	char *hex2 = "0xffffff";

	printf("hex1: %d hex2: %d", ft_atoh(hex1), ft_atoh(hex2));

	return 0;
}