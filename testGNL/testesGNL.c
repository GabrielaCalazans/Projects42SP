/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testesGNL.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 02:04:13 by gacalaza          #+#    #+#             */
/*   Updated: 2022/10/19 03:05:31 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int	main(void)
{
	int		fd;
	char	BUFFER[864];
	int		line;
	
	// // ******************** WRITE **************************
	
	// fd = open("testGNL2.txt", O_CREAT | O_WRONLY, 0600);

	// if (fd == -1)
	// {
	// 	printf("Failed to create and open the file.\n");
	// 	return (1);
	// }
	// ft_putstr_fd("Ola mundo!\nBlz?\n", fd);
	
	// close(fd);
	// printf("BUFFER: %s\n", BUFFER);
	
	// // *********************** READ **********************

	//printf("ANTES BUFFER: %s\n", BUFFER);
	
	fd = open("testGNL2.txt", O_RDONLY);

	if (fd == -1)
	{
		printf("Failed to open and read the file.\n");
		return (1);
	}

	// read(int fd, void *BUFFER, size_t count)
	line = 0;
	while (read (fd, BUFFER, 6))
	{
		if ('\n')
		{
			printf("line:%d DEPOIS BUFFER: %s\n", line, BUFFER);
			break ;
		}
		line++;
	}

	close(fd);

	//printf("RESTO DO BUFFER: %s\n", BUFFER);


	// *********************** VARIAVEL STATIC **********************

	return (0);
}

// void	test_static_variable(void)
// {
// 	int			localautomatic_var = 2;
// 	localautomatic_var *= 2;

// 	static int	localstatic_var = 2;
// 	localstatic_var *= 2;

// 	printf("Local Automatic Var = %i\n", localautomatic_var);
// 	printf("Local Static Var = %i\n", localstatic_var);
// }
