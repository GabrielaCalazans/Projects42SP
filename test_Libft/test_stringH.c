/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_stringH.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 00:39:31 by coder             #+#    #+#             */
/*   Updated: 2022/09/08 22:29:20 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	text[] = "GabCal%*+@as\\t351989	\bMeu =-seu.\n";
	char	*mention = ft_strchr(text, '@');
	char	dest[38];
	
	ft_putstr_fd(text, 1);
	ft_putstr_fd(mention, 1);
	ft_putnbr_fd(ft_strlen(text), 1);
	ft_putchar_fd('\n', 1);
	printf("mention: %s\n", mention); // pegar a partir da primeira menção do @
	printf("%zu\n", ft_strlen(text));

	ft_putstr_fd(text, 1);
	ft_memset(text, 'a', 10);
	ft_putstr_fd(text, 1);
	memset(text, 'a', 10);
	ft_putstr_fd(text, 1);

	ft_putstr_fd(dest, 1);
	ft_putchar_fd('\n', 1);
	memcpy(dest, text, sizeof(char) * 25);
	ft_putstr_fd(dest, 1);
	ft_putchar_fd('\n', 1);
	ft_memcpy(dest, text, sizeof(char) * 25);
	ft_putstr_fd(dest, 1);

	memcpy(dest, text, sizeof(char) * 25);
	printf("%s\n", dest);
	printf("\n");
	ft_memcpy(dest, text, sizeof(char) * 25);
	printf("%s\n", dest);

	int	source1[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int	destination1[10];
	memcpy(destination1, source1, sizeof(int) * 10);
	for(int i = 0; i < 10; i++)
		printf("destination1[%d]=%d\n", i, destination1[i]);
	printf("\n");
	memcpy(source1+2, source1, sizeof(int) * 8);
	for(int i = 0; i < 10; i++)
	printf("ORIGINAL source1[%d]=%d\n", i, source1[i]);

	int	source[11] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int	destination[10];
	memmove(destination, source, sizeof(int) * 10);
	for(int i = 0; i < 10; i++)
		printf("ORIGINAL destination[%d]=%d\n", i, destination[i]);
	printf("\n");
	memmove(source+2, source, sizeof(int) * 8);
	for(int i = 0; i < 10; i++)
		printf("ORIGINAL source[%d]=%d\n", i, source[i]);
	
	ft_memmove(destination, source, sizeof(int) * 10);
	for(int i = 0; i < 10; i++)
		printf("FAKE destination[%d]=%d\n", i, destination[i]);
	printf("\n");
	ft_memmove(source+2, source, sizeof(int) * 8);
	for(int i = 0; i < 10; i++)
		printf("FAKE source[%d]=%d\n", i, source[i]);
	
	//teste bzero
	char strbzero[8];
	bzero(strbzero, 8);
	ft_putstr_fd(strbzero, 1);
	ft_putchar_fd('\n', 1);
	ft_bzero(strbzero, 7);
	ft_putstr_fd(strbzero, 1);
	

	return (0);
}
