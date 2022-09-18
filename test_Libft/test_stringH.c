/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_stringH.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 18:59:48 by gacalaza          #+#    #+#             */
/*   Updated: 2022/09/17 21:52:21 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <bsd/string.h>

int	main(void)
{
	// char	text[] = "GabCal%*+@as\\t351989	\bMeu =-seu.\n";
	// //char	*mention = ft_strchr(text, '@');
	// char	dest[38];
	
	// ft_putstr_fd(text, 1);
	// ft_putstr_fd(mention, 1);
	// ft_putnbr_fd(ft_strlen(text), 1);
	// ft_putchar_fd('\n', 1);
	// printf("mention: %s\n", mention); // pegar a partir da primeira menção do @
	// printf("%zu\n", ft_strlen(text));
	
	// //teste MEMSET
	// ft_putstr_fd(text, 1);
	// ft_memset(text, 'a', 5);
	// ft_putstr_fd("FAKE :", 1);
	// ft_putstr_fd(text, 1);
	// ft_putstr_fd("ORIGINAL :", 1);
	// memset(text, 'b', 5);
	// ft_putstr_fd(text, 1);
	
	// //teste MEMCPY
	// ft_putstr_fd(dest, 1);
	// ft_putchar_fd('\n', 1);
	// memcpy(dest, text, sizeof(char) * 25);
	// ft_putstr_fd(dest, 1);
	// ft_putchar_fd('\n', 1);
	// ft_memcpy(dest, text, sizeof(char) * 25);
	// ft_putstr_fd(dest, 1);

	// memcpy(dest, text, sizeof(char) * 25);
	// printf("%s\n", dest);
	// printf("\n");
	// ft_memcpy(dest, text, sizeof(char) * 25);
	// printf("%s\n", dest);

	// int	source1[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	// int	destination1[10];
	// memcpy(destination1, source1, sizeof(int) * 10);
	// for(int i = 0; i < 10; i++)
	// 	printf("destination1[%d]=%d\n", i, destination1[i]);
	// printf("\n");
	// memcpy(source1+2, source1, sizeof(int) * 8);
	// for(int i = 0; i < 10; i++)
	// printf("ORIGINAL source1[%d]=%d\n", i, source1[i]);
	
	// //teste MEMMOVE
	// int	source[11] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	// int	destination[10];
	// memmove(destination, source, sizeof(int) * 10);
	// for(int i = 0; i < 10; i++)
	// 	printf("ORIGINAL destination[%d]=%d\n", i, destination[i]);
	// printf("\n");
	// memmove(source+2, source, sizeof(int) * 8);
	// for(int i = 0; i < 10; i++)
	// 	printf("ORIGINAL source[%d]=%d\n", i, source[i]);
	
	// ft_memmove(destination, source, sizeof(int) * 10);
	// for(int i = 0; i < 10; i++)
	// 	printf("FAKE destination[%d]=%d\n", i, destination[i]);
	// printf("\n");
	// ft_memmove(source+2, source, sizeof(int) * 8);
	// for(int i = 0; i < 10; i++)
	// 	printf("FAKE source[%d]=%d\n", i, source[i]);
	
	// char sResult[] = {67, 68, 67, 68, 69, 0, 45};
	// char sResult2[] = {67, 67, 68, 68, 69, 0, 45};

	// printf("[%p]pointer", sResult + 1);
	// printf("\n");
	// memmove(sResult + 1, sResult, 2);
	// for(int i = 0; i < 7; i++)
	// 	printf("ORIGINAL sResult[%d]=%d\n", i, sResult[i]);
	// 	printf("[%p]pointer", memmove(sResult + 1, sResult, 2));
	// printf("\n");

	// printf("[%p]pointer", sResult + 1);
	// printf("\n");
	// ft_memmove(sResult + 1, sResult, 2);
	// for(int i = 0; i < 7; i++)
	// printf("FAKE sResult[%d]=%d\n", i, sResult[i]);
	// printf("[%p]pointerFAKE", ft_memmove(sResult + 1, sResult, 2));
	// printf("\n");

		//  //teste MEMCHR
	// char	data[] = {'q', 'r', 's', 't', 'p', 'a', 'x'};
	// char	*pos = memchr(data, 't', 7);
	// printf("ORIGINAL pos = %s\n", pos);
	// printf("ORIGINAL char pos[0] = [%c]\n", pos[0]);
	// char	*fake = ft_memchr(data, 't', 7);
	// printf("FAKE pos = %s\n", pos);
	// printf("FAKE char pos[0] = [%c]\n", fake[0]);
	// char s[] = {0, 1, 2, 3, 4, 5};
	// /* 1 */ printf("ORIGINAL %s\n", ft_memchr(s, 0, 0)); // == NULL
	// /* 2 */ printf("ORIGINAL %s\n", ft_memchr(s, 0, 1)); // == s
	// /* 3 */ printf("ORIGINAL %s\n", ft_memchr(s, 2, 3)); // == s + 2
	// /* 4 */ printf("ORIGINAL %s\n", ft_memchr(s, 6, 6)); // == NULL
	// /* 5 */ printf("ORIGINAL %s\n", ft_memchr(s, 2 + 256, 3)); //Cast check  == s + 2
	
	//  //teste MEMCMP
	// char s[] = {-128, 0, 127, 0};
	// char sCpy[] = {-128, 0, 127, 0};
	// char s2[] = {0, 0, 127, 0};
	// char s3[] = {0, 0, 42, 0};
	// /* 1 */ printf("ORIGINAL %d\n", memcmp(s, sCpy, 4));
	// /* 2 */ printf("ORIGINAL %d\n", memcmp(s, s2, 0));
	// /* 3 */ printf("ORIGINAL %d\n", memcmp(s, s2, 1)); //  > 0)
	// /* 4 */ printf("ORIGINAL %d\n", memcmp(s2, s, 1)); // < 0)
	// /* 5 */ printf("ORIGINAL %d\n", memcmp(s2, s3, 4)); // != 0)
	// /* 6 */ printf("ORIGINAL %d\n", memcmp(s, s3, 4)); // 
	// printf("\n");
	// /* 1 */ printf("FAKE %d\n", ft_memcmp(s, sCpy, 4));
	// /* 2 */ printf("FAKE %d\n", ft_memcmp(s, s2, 0));
	// /* 3 */ printf("FAKE %d\n", ft_memcmp(s, s2, 1)); //  > 0)
	// /* 4 */ printf("FAKE %d\n", ft_memcmp(s2, s, 1)); // < 0)
	// /* 5 */ printf("FAKE %d\n", ft_memcmp(s2, s3, 4)); // != 0)
	// /* 6 */ printf("FAKE %d\n", ft_memcmp(s, s3, 4)); // != 0)
		
	//teste bzero
	// char strbzero[8];
	// bzero(strbzero, 8);
	// ft_putstr_fd(strbzero, 1);
	// ft_putchar_fd('\n', 1);
	// ft_bzero(strbzero, 7);
	// ft_putstr_fd(strbzero, 1);
	// char tab[100];
	// memset(tab, 'A', 100);
	// ft_bzero(tab, 0);
	// /* 1 */ printf("%d", (tab[0] == 'A'));
	// ft_bzero(tab, 42);
	// ft_putstr_fd(tab, 1);
	// int i = 0;
	// for (; i < 100 && tab[i] == 0; ++i)
	// 	;
	// memset(tab, 'A', 100); tab[0] = 0;
	// ft_bzero(tab, 42);
	// i = 0;
	// for (; i < 100 && tab[i] == 0; ++i)
	// ft_putstr_fd(tab, 1);
	
	// // teste STRCHR
	// char s[] = "tripouille";
	// /* 1 */ printf("[String criada: %s]", strchr(s, 't'));
	// printf("\n");
	// /* 2 */ printf("[String criada: %s]", strchr(s, 'l'));
	// printf("\n");
	// /* 3 */ printf("[String criada: %s]", strchr(s, 'z'));
	// printf("\n");
	// /* 4 */ printf("[String criada: %s]", strchr(s, 0));
	// printf("\n");
	// /* 5 */ printf("[String criada: %s]", strchr(s, 't' + 256));
	// printf("\n");

	// // teste MEU STRCHR 
	// printf("MEU STRCHR\n");
	// /* 1 */ printf("[String criada: %s]", ft_strchr(s, 't'));
	// printf("\n");
	// /* 2 */ printf("[String criada: %s]", ft_strchr(s, 'l'));
	// printf("\n");
	// /* 3 */ printf("[String criada: %s]", ft_strchr(s, 'z'));
	// printf("\n");
	// /* 4 */ printf("[String criada: %s]", ft_strchr(s, 0));
	// printf("\n");
	// /* 5 */ printf("[String criada: %s]", ft_strchr(s, 't' + 256));
	// printf("\n");

		// STRRCHR 
	// char s[] = "tripouille";
	// /* 1 */ printf("[String criada: %s]", strrchr(s, 't'));
	// printf("\n");
	// /* 2 */ printf("[String criada: %s]", strrchr(s, 'l'));
	// printf("\n");
	// /* 3 */ printf("[String criada: %s]", strrchr(s, 'z'));
	// printf("\n");
	// /* 4 */ printf("[String criada: %s]", strrchr(s, 0));
	// printf("\n");
	// /* 5 */ printf("[String criada: %s]", strrchr(s, 't' + 256));
	// printf("\n");
	// printf("MEU STRRCHR\n");
	// /* 1 */ printf("[String criada: %s]", ft_strrchr(s, 't'));
	// printf("\n");
	// /* 2 */ printf("[String criada: %s]", ft_strrchr(s, 'l'));
	// printf("\n");
	// /* 3 */ printf("[String criada: %s]", ft_strrchr(s, 'z'));
	// printf("\n");
	// /* 4 */ printf("[String criada: %s]", ft_strrchr(s, 0));
	// printf("\n");
	// /* 5 */ printf("[String criada: %s]", ft_strrchr(s, 't' + 256));
	// printf("\n");

	//  //teste STRNSTR
	// char Grande[] = "This is the way to hell";
	// char pequeno[] = "the";
	// printf("ORIGINAL: %s\n", strnstr(Grande, pequeno, 20));
	// char GrandeF[] = "This is the way to hell";
	// char pequenoF[] = "the";
	// printf("FAKE: %s\n", ft_strnstr(GrandeF, pequenoF, 20));
	// char GrandeJ[] = "This is the way to hell";
	// char pequenoJ[] = "tohe";
	// printf("FAKE tohe: %s\n", ft_strnstr(GrandeJ, pequenoJ, 20));
	// char GrandeO[] = "This is the way to hell";
	// char pequenoO[] = "tohe";
	// printf("ORIGINAL tohe: %s\n", strnstr(GrandeO, pequenoO, 20));

	//  //teste STRNCMP
	// char	str1[] = "Teste";
	// char	str2[] = "Teste1";
	// char	str3[] = "TesTE";
	// printf("Retorno de iguais: %d\n", strncmp(str1, str2, 5));
	// printf("Retorno de diferente: %d\n", strncmp(str1, str3, 5));
	// printf((ft_strncmp("1234", "1235", 3) == 0));

		//teste STRLCPY
	// char src[] = "coucou";
	// char dest[10]; memset(dest, 'A', 10);
	// char src1[] = "coucou";
	// char dest1[10]; memset(dest1, 'A', 10);
	// /* 1 */ printf("ORIGINAL size 0: [%zu] ", strlcpy(dest, src, 0));
	// /* 1 */ printf("FAKE size 0: [%zu]", ft_strlcpy(dest1, src1, 0));
	// printf("\n");
	// /* 2 */ printf("ORIGINAL size 1: [%zu] ", strlcpy(dest, src, 1));
	// /* 2 */ printf("FAKE size 1: [%zu]", ft_strlcpy(dest, src, 1));
	// printf("\n");
	// /* 3 */ printf("ORIGINAL size 2: [%zu] ", strlcpy(dest, src, 2));
	// /* 3 */ printf("FAKE size 2: [%zu]", ft_strlcpy(dest, src, 2));
	// /* 3 */ printf("\ndest: [%s]\n src: [%s]\n", dest, src);
	// printf("\n");
	// /* 4 */ printf("ORIGINAL size -1: [%zu] ", strlcpy(dest, src, -1));
	// /* 4 */ printf("FAKE size -1: [%zu]", ft_strlcpy(dest, src, -1));
	// printf("\n");
	// /* 5 */ printf("ORIGINAL size 6: [%zu] ", strlcpy(dest, src, 6));
	// /* 5 */ printf("FAKE size 6: [%zu]", ft_strlcpy(dest, src, 6));
	// printf("\n");
	// /* 6 */ printf("ORIGINAL size 7: [%zu] ", strlcpy(dest, src, 7));
	// /* 6 */ printf("FAKE size 7: [%zu]", ft_strlcpy(dest, src, 7));
	// /* 6 */ printf("\ndest: [%s]\n src: [%s]\n", dest, src);
	// printf("\n");
	// /* 7 */ printf("ORIGINAL size 8: [%zu] ", strlcpy(dest, src, 8));
	// /* 7 */ printf("FAKE size 8: [%zu]", ft_strlcpy(dest, src, 8));
	// /* 7 */ printf("\ndest: [%s]\n src: [%s]\n", dest, src);
	// printf("\n");
	// /* 8 */ printf("ORIGINAL size 42 p/nada: [%zu] ", strlcpy(dest, "", 42));
	// /* 8 */ printf("FAKE size 42: [%zu]", ft_strlcpy(dest, "", 42));
	// printf("\n");
	// /* 9 */ printf("ORIGINAL size 0 p/1: [%zu] ", strlcpy(dest, "1", 0));
	// /* 9 */ printf("FAKE size 0: [%zu]", ft_strlcpy(dest, "1", 0));
	// /* 9 */ printf("dest: [%s]\n", dest);
	// printf("\n");


		//TESTE STRLCAT
	// char dest[30]; memset(dest, 0, 30);
	// char * src = (char *)"AAAAAAAAA";
	// dest[0] = 'B';
	// printf("src tem 9, dest 1\n");
	// /* 1 */ printf("ORIGINAL size 0: [%zu]\n", strlcat(dest, src, 0));
	// dest[0] = 'B';
	// /* 2 */ printf("ORIGINAL size 1: [%zu]\n", strlcat(dest, src, 1));
	// memset(dest, 'B', 4);
	// printf("src tem 9, dest 4\n");
	// /* 3 */ printf("ORIGINAL size 3: [%zu]\n", strlcat(dest, src, 3));
	// /* 4 */ printf("ORIGINAL size 6: [%zu]\n", strlcat(dest, src, 6));
	// memset(dest, 'C', 5);
	// 	printf("src tem 9, dest 5\n");
	// /* 5 */ printf("ORIGINAL size -1: [%zu]\n", strlcat(dest, src, -1));
	// memset(dest, 'C', 15);
	// 	printf("src tem 9, dest 15\n");
	// /* 6 */ printf("ORIGINAL size 17: [%zu]\n", strlcat(dest, src, 17));
	// memset(dest, 0, 30);
	// printf("src tem 9, dest 30\n");
	// /* 7 */ printf("ORIGINAL size 1: [%zu]\n", strlcat(dest, src, 1));
	// memset(dest, 0, 30); memset(dest, '1', 10);
	// /* 8 */ printf("ORIGINAL size 5: [%zu]\n", strlcat(dest, src, 5));
	// memset(dest, 0, 30); memset(dest, '1', 10);
	// /* 9 */ printf("ORIGINAL size 5: [%zu]\n", strlcat(dest, src, 5));
	// memset(dest, 0, 30); memset(dest, '1', 10);
	// /* 10 */ printf("ORIGINAL size 15 nada em src e 1 em dest: [%zu]\n", strlcat(dest, "", 15));
	// memset(dest, 0, 30);
	// /* 11 */ printf("ORIGINAL size 42 nada em src: [%zu]\n", strlcat(dest, "", 42));
	// memset(dest, 0, 30);
	// /* 12 */ printf("ORIGINAL size 0 nada em src: [%zu]\n", strlcat(dest, "", 0));
	// memset(dest, 0, 30);
	// printf("src tem 3, dest 30\n");
	// /* 13 */ printf("ORIGINAL size 1: [%zu]\n", strlcat(dest, "123", 1));
	// memset(dest, 0, 30);
	// /* 14 */ printf("ORIGINAL size 2: [%zu]\n", strlcat(dest, "123", 2));
	// memset(dest, 0, 30);
	// /* 15 */ printf("ORIGINAL size 3: [%zu]\n", strlcat(dest, "123", 3));
	// memset(dest, 0, 30);
	// /* 16 */ printf("ORIGINAL size 4: [%zu]\n", strlcat(dest, "123", 4));
	// memset(dest, 0, 30);
	// /* 17 */ printf("ORIGINAL size 0: [%zu]\n", strlcat(dest, "123", 0));

	// char dest1[30]; memset(dest1, 0, 30);
	// char * src1 = (char *)"AAAAAAAAA";
	// dest1[0] = 'B';
	// printf("src1 tem 9, dest1 1\n");
	// /* 1 */ printf("FAKE size 0: [%zu]\n", ft_strlcat(dest1, src1, 0));
	// dest1[0] = 'B';
	// /* 2 */ printf("FAKE size 1: [%zu]\n", ft_strlcat(dest1, src1, 1));
	// memset(dest1, 'B', 4);
	// printf("src1 tem 9, dest1 4\n");
	// /* 3 */ printf("FAKE size 3: [%zu]\n", ft_strlcat(dest1, src1, 3));
	// /* 4 */ printf("FAKE size 6: [%zu]\n", ft_strlcat(dest1, src1, 6));
	// memset(dest1, 'C', 5);
	// 	printf("src1 tem 9, dest1 5\n");
	// /* 5 */ printf("FAKE size -1: [%zu]\n", ft_strlcat(dest1, src1, -1));
	// memset(dest1, 'C', 15);
	// 	printf("src1 tem 9, dest1 15\n");
	// /* 6 */ printf("FAKE size 17: [%zu]\n", ft_strlcat(dest1, src1, 17));
	// memset(dest1, 0, 30);
	// printf("src1 tem 9, dest1 30\n");
	// /* 7 */ printf("FAKE size 1: [%zu]\n", ft_strlcat(dest1, src1, 1));
	// memset(dest1, 0, 30); memset(dest1, '1', 10);
	// /* 8 */ printf("FAKE size 5: [%zu]\n", ft_strlcat(dest1, src1, 5));
	// memset(dest1, 0, 30); memset(dest1, '1', 10);
	// /* 9 */ printf("FAKE size 5: [%zu]\n", ft_strlcat(dest1, src1, 5));
	// memset(dest1, 0, 30); memset(dest1, '1', 10);
	// /* 10 */ printf("FAKE size 15 nada em src1 e 1 em dest1: [%zu]\n", ft_strlcat(dest1, "", 15));
	// memset(dest1, 0, 30);
	// /* 11 */ printf("FAKE size 42 nada em src1: [%zu]\n", ft_strlcat(dest1, "", 42));
	// memset(dest1, 0, 30);
	// /* 12 */ printf("FAKE size 0 nada em src1: [%zu]\n", ft_strlcat(dest1, "", 0));
	// memset(dest1, 0, 30);
	// printf("src1 tem 3, dest1 30\n");
	// /* 13 */ printf("FAKE size 1: [%zu]\n", ft_strlcat(dest1, "123", 1));
	// memset(dest1, 0, 30);
	// /* 14 */ printf("FAKE size 2: [%zu]\n", ft_strlcat(dest1, "123", 2));
	// memset(dest1, 0, 30);
	// /* 15 */ printf("FAKE size 3: [%zu]\n", ft_strlcat(dest1, "123", 3));
	// memset(dest1, 0, 30);
	// /* 16 */ printf("FAKE size 4: [%zu]\n", ft_strlcat(dest1, "123", 4));
	// memset(dest1, 0, 30);
	// /* 17 */ printf("FAKE size 0: [%zu]\n", ft_strlcat(dest1, "123", 0));


	
	return (0);
}
