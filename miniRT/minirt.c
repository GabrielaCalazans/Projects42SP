/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 18:53:28 by gacalaza          #+#    #+#             */
/*   Updated: 2024/03/16 19:17:57 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minirt.h"

int	ft_equal(float a, float b)
{
	const float	epsilon = 0.00001;

	if (abs(a - b) < epsilon)
		return (1);
	return (0);
}

int main (int argc, char *argv[])
{

}