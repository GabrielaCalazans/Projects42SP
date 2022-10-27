/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testesGNL.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 02:04:13 by gacalaza          #+#    #+#             */
/*   Updated: 2022/10/27 01:27:53 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

char	*read_line(int fd, char *static_var);
char	*get_line(char *static_var);
char	*rest_static_var(char *static_var);
char	*get_next_line(int fd);

int	main(void)
{
	int			fd;

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
	
	fd = open("testGNL2.txt", O_RDONLY);
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
	// static_var = read_line(fd, static_var);
	// printf ("MAIN static: %s", static_var);
	// line = get_line(static_var);
	// printf ("MAIN line: %s", line);
	// static_var = rest_static_var(static_var);
	// printf ("MAIN static pos: %s", static_var);
	
	// static_var = read_line(fd, static_var);
	// printf ("MAIN static: %s", static_var);
	// line = get_line(static_var);
	// printf ("MAIN line: %s", line);
	// static_var = rest_static_var(static_var);
	// printf ("MAIN static pos: %s", static_var);

	printf ("get1: %s", get_next_line (fd));
	printf ("get2: %s", get_next_line (fd));
	printf ("get3: %s", get_next_line (fd));
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
	//int		i;
	//int		line;
	ssize_t	n_bytes;
	char	*buff;

	//line = 0;
	//i = 0;
	n_bytes = 1;
	while (/*!(ft_strchr(static_var, '\n')) &&*/ n_bytes > 0)
	{
		buff = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
		n_bytes = read(fd, buff, BUFFER_SIZE);
		if (n_bytes == -1)
		{
			free (buff);
			return (NULL);
		}
		buff[n_bytes] = '\0';
		static_var = ft_strjoin(static_var, buff);
		//printf("static: %s", static_var);
		printf("\nbuff: %s - n_bytes:%zd\n", buff, n_bytes);
	}
	//free (buff);
	return (static_var);
}

char	*get_line(char *static_var)
{
	char	*line;
	int		i;
	//int		quebra;

	//quebra = 0;
	i = 0;
	if (!static_var)
		return (NULL);
	while (static_var[i] && static_var[i] != '\n')
		i++;
	line = malloc(sizeof(char) * i + 2);
	if (!line)
		return (NULL);
	i = 0;
	while (static_var[i] && static_var[i] != '\n')
	{
		line[i] = static_var[i];
		i++;
	}
	if (static_var[i] == '\n')
	{
		line[i] = static_var[i];
		i++;
	}
	line[i] = '\0';
	return (line);
	// while (*static_var != '\0')
	// {
	// 	if (!(ft_strchr(static_var, '\n')))
	// 		printf ("line: %s\n", static_var);
	// 	else
	// 		line = ft_strchr(static_var, '\n');
	// 		printf("quebra %d: %s\n", quebra, line);
	// 		quebra++;
	// 	static_var++;
	// }
}

char	*rest_static_var(char *static_var)
{
	int i;
	int j;
	char *rest;

	if (!static_var)
		return (NULL);
	while (static_var[i] && static_var[i] != '\n')
		i++;
	rest = malloc(sizeof(char) * (ft_strlen(static_var) - i) + 1);
	if (!rest)
		return (NULL);
	i++;
	j = 0;
	while (static_var[i])
	{
		rest[j++] = static_var[i++];
	}
	rest[j] = '\0';
	return (rest);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*static_var;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	static_var = read_line(fd, static_var);
	line = get_line(static_var);
	static_var = rest_static_var(static_var);
	return (line);
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
