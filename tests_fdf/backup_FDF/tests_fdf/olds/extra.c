/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 17:43:13 by gacalaza          #+#    #+#             */
/*   Updated: 2023/03/04 00:53:29 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h> // CLOSE READ WRITE
#include <fcntl.h> // OPEN
#include <stdio.h> // PERROR
#include <math.h>

int main(int argc, char **argv)
{
	// int	x = -100;
	// printf ("abs: %d", abs(x));

	int fd = open(argv[1], O_RDONLY);
	printf("fd:%d\n", fd);
	if (fd < 0)
			printf("Error opening file! :(");
	else
		printf("SENHHOOOOR!");
	close (fd);
	return (0);
}
