/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testesGNL.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 02:04:13 by gacalaza          #+#    #+#             */
/*   Updated: 2022/10/26 04:32:56 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

char	*read_line(int fd, char *static_var);
void	*check_line(char *static_var);

int	main(void)
{
	int			fd;
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
	//printf("strlen1: %zd", ft_strlen(static_var));
	static_var = read_line(fd, static_var);
	static_var = read_line(fd, static_var);
	//static_var = read_line(BUFFER, fd, static_var);
	//static_var = read_line(BUFFER, fd, static_var);
	printf ("static main: %s\n", static_var);
	check_line(static_var);
	
	printf ("static main pos: %s\n", static_var);
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

char	*read_line(int fd, char *static_var)
{
	int		i;
	int		line;
	ssize_t	read_bytes;
	char	*BUFFER;

	line = 0;
	i = 0;
	read_bytes = 1;
	while (!(ft_strchr(static_var, '\n')) && read_bytes > 0)
	{
		BUFFER = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
		read_bytes = read(fd, BUFFER, BUFFER_SIZE);
		if (read_bytes == -1)
			return (NULL);
		BUFFER[read_bytes] = '\0';
		static_var = ft_strjoin(static_var, BUFFER);
		//printf("static: %s", static_var);
		printf("\nBUFFER: %s - read_bytes:%zd\n", BUFFER, read_bytes);
		free (BUFFER);
		printf("read: %zd\n", read_bytes);
	}
	return (static_var);
}

void	*check_line(char *static_var)
{
	char	*linebreak;
	int		quebra;

	quebra = 0;
	while (*static_var != '\0')
	{
		if (!(ft_strchr(static_var, '\n')))
			printf ("line: %s\n", static_var);
		else
			linebreak = ft_strchr(static_var, '\n');
			printf("quebra %d: %s\n", quebra, linebreak);
			quebra++;
		static_var++;
	}
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
