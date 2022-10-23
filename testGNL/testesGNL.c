/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testesGNL.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 02:04:13 by gacalaza          #+#    #+#             */
/*   Updated: 2022/10/23 21:55:10 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

char	*read_line(char	*BUFFER, int fd, char *static_var);

int	main(void)
{
	int			fd;
	char		*BUFFER;
	static char	*static_var;

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
	
	// // // *********************** READ **********************

	// printf("ANTES BUFFER: %s\n", BUFFER);
	
	fd = open("testGNL1.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("Failed to open and read the file.\n");
		return (1);
	}
	if (BUFFER_SIZE < 1)
	{
		printf("Que burro! Dá zero pra ele.");
		return (0);
	}
	// printf ("fd1: %d\n", fd);
	printf("strlen1: %zd", ft_strlen(static_var));
	static_var = read_line(BUFFER, fd, static_var);
	//printf ("static: %s\n", static_var);
	// read(fd, BUFFER, BUFFER_SIZE);
	// printf("BUFFER: %s\n", BUFFER);
	//static_var = read_line(BUFFER, fd, static_var);
	
	// // read(int fd, void *BUFFER, size_t count)
	// line = 0;
	// i = 0;
	// read_bytes = 1;
	// while (!ft_strchr(BUFFER, '\n'))
	// {
	// 	read_bytes = read (fd, BUFFER, BUFFER_SIZE);
		
	// 	if (read_bytes == -1)
	// 		return (0);
		
	// 	printf("\nBUFFER: %s read_bytes:%zd", BUFFER, read_bytes);
	// }
	// while (BUFFER[i] != '\0')
	// {
	// 	printf("BUFFER: %s", BUFFER);
	// 	if (ft_strchr(&BUFFER[i], '\n'))
	// 	{
	// 		printf("\nline:%d\n", line);
	// 		line++;
	// 	}
	// 	i++;
	// }

	//printf("RESTO DO BUFFER: %s\n", BUFFER);
	close(fd);

	// *********************** VARIAVEL STATIC **********************

	// test_static_variable();
	// test_static_variable();
	// test_static_variable();

	return (0);
}

char	*read_line(char	*BUFFER, int fd, char *static_var)
{
	int		i;
	int		line;
	ssize_t	read_bytes;
	
	line = 0;
	i = 0;
	read_bytes = 1;
	printf("strlen2: %zd static: %s\n", ft_strlen(static_var), static_var);
	while (!ft_strchr(static_var, '\n'))
	{
		printf("\nread:%zd\n", read_bytes);
		BUFFER = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
		printf("BUFFER1: %s", BUFFER);
		read_bytes = read(fd, BUFFER, BUFFER_SIZE);
		printf("\nBUFFER2: %s read_bytes2:%zd\n", BUFFER, read_bytes);
		if (read_bytes == -1)
			return (NULL);
		static_var = ft_strjoin(static_var, BUFFER);
		printf("static: %s", static_var);
		printf("\nBUFFER3: %s read_bytes3:%zd", BUFFER, read_bytes);
		free (BUFFER);
		i++;
	}
	printf("\ni:%d\n", i);
	return (static_var);
}

// void	test_static_variable(void)
// {
// 	int			localAutomatic_var = 2;
// 	localAutomatic_var *= 2;

// 	static int	localStatic_var = 2;
// 	localStatic_var *= 2;
	
// localStatic_var = 2;
// 	printf("Local Automatic Var = %i\n", localAutomatic_var);
// 	printf("Local Static Var = %i\n", localStatic_var);
// }
