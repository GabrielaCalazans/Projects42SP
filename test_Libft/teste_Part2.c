/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teste_Part2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 18:32:18 by gacalaza          #+#    #+#             */
/*   Updated: 2022/10/04 22:04:34 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
static size_t	countletters(char const *s, char c);
static void	checkcols(char const *s, char c, int rows, int **cols);
static int sumofarray(int **array);
char	**ft_split(char const *s, char c);

int	main(void)
{
	// ****************** TESTE SUBSTR ***********************
	// char *s = ft_substr("tripouille", 100, 1);
	// /* 5 */ printf("%s", !strcmp(s, ""));
	// /* 6 */ printf("%s", s, 1);
	// free(s);

	// ****************** TESTE ATOI ***********************
	// char * s = ft_itoa(2147483647);
	// /* 1 */ printf("[%s] ", s);
	// /* 2 */ printf("TEM QUE SER 10: [%zu]\n", ft_strlen(s));
	// free(s);

	// s = ft_itoa(-2147483648);
	// /* 3 */ printf("[%s] ", s);
	// /* 4 */ printf("TEM QUE SER 11: [%zu]\n", ft_strlen(s));
	// free(s);

	// s = ft_itoa(0);
	// /* 5 */ printf("[%s] ", s);
	// /* 6 */ printf("TEM QUE SER 1: [%zu]\n", ft_strlen(s));
	// free(s);

	// s = ft_itoa(1);
	// /* 7 */ printf("[%s] ", s);
	// /* 8 */ printf("TEM QUE SER 1: [%zu]\n", ft_strlen(s));
	// free(s);

	// s = ft_itoa(-1);
	// /* 9 */ printf("[%s] ", s);
	// /* 10 */ printf("TEM QUE SER 2: [%zu]\n", ft_strlen(s));
	// free(s);

	// s = ft_itoa(42);
	// /* 11 */ printf("[%s] ", s);
	// /* 12 */ printf("TEM QUE SER 2: [%zu]\n", ft_strlen(s));
	// free(s);
	
	// ****************** TESTE STRTRIM ***********************
	// char * s = ft_strtrim("Gabriel", "l");
	// /* 1 */ printf("%s", s);
	// /* 2 */ printf(s, strlen("tripouille") + 1); free(s);

	// s = ft_strtrim("tripouille   xxx", " x");
	// /* 3 */ printf(!strcmp(s, "tripouille"));
	// /* 4 */ printf(s, strlen("tripouille") + 1); free(s);

	// s = ft_strtrim("   xxxtripouille   xxx", " x");
	// /* 5 */ printf(!strcmp(s, "tripouille"));
	// /* 6 */ printf(s, strlen("tripouille") + 1); free(s);

	// s = ft_strtrim("   xxx   xxx", " x");
	// /* 7 */ printf(!strcmp(s, ""));
	// /* 8 */ printf(s, 1); free(s);

	// s = ft_strtrim("", "123");
	// /* 9 */ printf(!strcmp(s, ""));
	// /* 10 */ printf(s, 1); free(s);

	// s = ft_strtrim("123", "");
	// /* 11 */ printf(!strcmp(s, "123"));
	// /* 12 */ printf(s, 4); free(s);

	// s = ft_strtrim("", "");
	// /* 13 */ printf(!strcmp(s, ""));
	// /* 14 */ printf(s, 1); free(s);

	// s = ft_strtrim("abcdba", "acb");
	// /* opsec-infosec 15 */ printf(!strcmp(s, "d"));
	// /* opsec-infosec 16 */ printf(s, 2); free(s);

	// ****************** TESTE SPLIT ***********************
	char const *s = "   lorem   ipsum dolor     sit amet, consectetur   adipiscing elit. Sed non risus. Suspendisse   ";
	char c = ' ';
	char **array = ft_split(s, c);
	char const *s2 = "xxfabcxxffcd";
	char c2 = 'f';
	char **array2 = ft_split(s2, c2);
	char const *s3 = "fxxxxxx";
	char c3 = 'f';
	char **array3 = ft_split(s3, c3);
	char const *s4 = "xxxxxx";
	char c4 = 'f';
	char **array4 = ft_split(s4, c4);
	int i = 0;

	printf("String: %s\n", s);
	while(array[i] != (char *)'\0')
	{
		printf("%s\n", array[i]);
		++i;
	}
	i = 0;
	printf("String: %s\n", s2);
	while(array2[i] != (char *)'\0')
	{
		printf("%s\n", array2[i]);
		++i;
	}
	i = 0;
	printf("String: %s\n", s3);
	while(array3[i] != (char *)'\0')
	{
		printf("%s\n", array3[i]);
		++i;
	}
	i = 0;
	printf("String: %s\n", s4);
	while(array4[i] != (char *)'\0')
	{
		printf("%s\n", array4[i]);
		++i;
	}

	// ****************** TESTE APLICAÇÕES SPLIT ***********************
	// int		rows;
	// // int		*cols;
	// // int		result;

	// rows = countletters(s, c);
	// printf("%d\n", rows);
	// checkcols(s, c, rows, &cols);
	// for(int loop = 0; loop < 12; loop++)
	// 	printf("%d ", cols[loop]);
	// printf("%d", sumofarray (&cols));

	
	return (0);
}

// static int	sumofarray(int **array)
// {
// 	int	result;
// 	size_t	i;
// 	size_t	len;

// 	i = 0;
// 	len = sizeof(array) / sizeof(int);
// 	while (i < len)
// 	{
// 		result += *array[i];
// 		i++;
// 	}
// 	return (result);
// }

// static size_t	countletters(char const *s, char c)
// {
// 	size_t	letters;
// 	int	count;

// 	letters = 0;
// 	count = 0;
// 	while (s[count] != '\0')
// 	{
// 		if (s[count] != c && s[count] != '\0')
// 			letters++;
// 		count++;
// 	}
// 	return (letters);
// }

// static void	checkcols(char const *s, char c, int rows, int **cols)
// {
// 	int	count;
// 	int	strlen;
// 	int	rowpos;

// 	count = 0;
// 	rowpos = 0;
// 	strlen = 0;
// 	*cols = malloc(rows * sizeof(int));
// 	if (!*cols)
// 		return ;
// 	while (s[count] != '\0')
// 	{
// 		if (s[count] != c)
// 			strlen++;
// 		if ((s[count] != c && s[count + 1] == c) || (s[count] != c && s[count + 1] == '\0'))
// 		{
// 			(*cols)[rowpos] = strlen;
// 			rowpos++;
// 			strlen = 0;
// 		}
// 		count++;
// 	}
// }

// static size_t	countletters(char const *s, char c)
// {
// 	size_t	letters;
// 	int		count;

// 	letters = 0;
// 	count = 0;
// 	if (!*s)
// 		return (0);
// 	while (s[count] != '\0')
// 	{
// 		if (s[count] != c && s[count] != '\0')
// 			letters++;
// 		count++;
// 	}
// 	return (letters);
// }

// char	**ft_split(char const *s, char c)
// {
// 	char	**array;
// 	size_t	substr_len;
// 	int		i;

// 	array = (char **)malloc(sizeof(char *) * (countletters(s, c) + 1));
// 	if (!array || !s)
// 		return (0);
// 	i = 0;
// 	while (*s)
// 	{
// 		while (*s == c && *s)
// 			s++;
// 		if (*s)
// 		{
// 			if (!ft_strchr(s, c))
// 				substr_len = ft_strlen(s);
// 			else
// 				substr_len = ft_strchr(s, c) - s;
// 			(array)[i++] = ft_substr(s, 0, substr_len);
// 			s += substr_len;
// 		}
// 	}
// 	array[i] = NULL;
// 	return (array);
// }
