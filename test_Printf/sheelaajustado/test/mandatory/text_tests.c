/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text_tests.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 01:29:24 by sguilher          #+#    #+#             */
/*   Updated: 2021/08/21 03:33:37 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils/test.h"

void	text_tests()
{
	int	result1;
	int	result2;

	printf(PINK("\n\nTest 1.1: printing a simple text:\n"));
	printf(LIGHT_BLUE2("%20s"), "printf result:\n");
	result1 = printf("test\n");
	printf(LIGHT_BLUE2("%20s"), "ft_printf result: ");
	printf("\n");
	result2 = ft_printf("test\n");
	check_return(result1, result2);

	printf(PINK("\nTest 1.2: printing a bigger text: Harry Potter and Philosopher's Stone\n"));
	printf(LIGHT_BLUE2("%20s"), "printf result:\n");
	result1 = printf("Mr and Mrs Dursley, of number four, Privet Drive, were proud to say that they were perfectly normal, thank you very much.\nThey were the last people you'd expect to be involved in anything strange or mysterious, because they just didn't hold with such nonsense.\nMr Dursley was the director of a firm called Grunnings, which made drills. He was a big, beefy man with hardly nay neck, although he did have a very large muoustache.\nMrs Dursley was thin and blonde and had nearly twice the usual amount of neck, which came in very useful as she spent so much of her time craning over garden fences, spying on the neigbours.\nThe Dursleys had a small son called Dudley and in their opinion there was no finer boy anywhere.\nThe Dursley had everything they wanted, but they also had a secret, and their greatest fear was that somebody would discover it.\nThey didn't think they could bear it if anyone found out about the Potters.\n");
	printf(LIGHT_BLUE2("%20s"), "ft_printf result: ");
	printf("\n");
	result2 = ft_printf("Mr and Mrs Dursley, of number four, Privet Drive, were proud to say that they were perfectly normal, thank you very much.\nThey were the last people you'd expect to be involved in anything strange or mysterious, because they just didn't hold with such nonsense.\nMr Dursley was the director of a firm called Grunnings, which made drills. He was a big, beefy man with hardly nay neck, although he did have a very large muoustache.\nMrs Dursley was thin and blonde and had nearly twice the usual amount of neck, which came in very useful as she spent so much of her time craning over garden fences, spying on the neigbours.\nThe Dursleys had a small son called Dudley and in their opinion there was no finer boy anywhere.\nThe Dursley had everything they wanted, but they also had a secret, and their greatest fear was that somebody would discover it.\nThey didn't think they could bear it if anyone found out about the Potters.\n");
	check_return(result1, result2);

	printf(PINK("\nTest 2: printing special characters\n"));
	result1 = printf("\\\"\',\n");
	result2 = ft_printf("\\\"\',\n");
	check_return(result1, result2);
	result1 = printf("alert: \\a\a\n");
	result2 = ft_printf("alert: \\a\a\n");
	check_return(result1, result2);
	result1 = printf("\bbackspace \\b\n");
	result2 = ft_printf("\bbackspace \\b\n");
	check_return(result1, result2);
	result1 = printf("\fform feed \\f\n");
	result2 = ft_printf("\fform feed \\f\n");
	check_return(result1, result2);
	result1 = printf("\rcarriage return \\r\n");
	result2 = ft_printf("\rcarriage return \\r\n");
	check_return(result1, result2);
	result1 = printf("\vvertical tab \\v\n");
	result2 = ft_printf("\vvertical tab \\v\n");
	check_return(result1, result2);
	result1 = printf("\thorizontal tab \\t\n");
	result2 = ft_printf("\thorizontal tab \\t\n");
	check_return(result1, result2);
	result1 = printf("\nnew line \\n\n");
	result2 = ft_printf("\nnew line \\n\n");
	check_return(result1, result2);
	printf("--------------------------------\n");
	printf(PINK("\nTest 3: special character \\c - ignore remaining characters in this string\n"));
	printf(PINK("obs: It doesn't work on guacamole\n"));
	result1 = printf("This should be printed.\cThis should not be printed.\n");
	result2 = ft_printf("This should be printed.\cThis should not be printed.\n");
	check_return(result1, result2);
	result1 = printf("Putting as a variable %%s: %s", "This should be printed.\cThis should not be printed.\n");
	result2 = ft_printf("Putting as a variable %%s: %s", "This should be printed.\cThis should not be printed.\n");
	check_return(result1, result2);
	printf("--------------------------------\n");
	printf(PINK("\nTest 4: special character \\num - write a byte whose value is the 1-, 2- or 3- digit octal number num. Multiple characters can be constructed using multiple \\num sequeces.\n"));
	result1 = printf("This is the octal number \\57 = \57 in the ascii table\n");
	result2 = ft_printf("This is the octal number \\57 = \57 in the ascii table\n");
	check_return(result1, result2);
	result1 = printf("This is the octal number \\60 = \60 in the ascii table\n");
	result2 = ft_printf("This is the octal number \\60 = \60 in the ascii table\n");
	check_return(result1, result2);
	result1 = printf("This is the octal number \\71 = \71 in the ascii table\n");
	result2 = ft_printf("This is the octal number \\71 = \71 in the ascii table\n");
	check_return(result1, result2);
	result1 = printf("This is the octal number \\72 = \72 in the ascii table\n");
	result2 = ft_printf("This is the octal number \\72 = \72 in the ascii table\n");
	check_return(result1, result2);
	result1 = printf("This is the octal number \\100 = \100 in the ascii table\n");
	result2 = ft_printf("This is the octal number \\100 = \100 in the ascii table\n");
	check_return(result1, result2);
	result1 = printf("This is the octal number \\101 = \101 in the ascii table\n");
	result2 = ft_printf("This is the octal number \\101 = \101 in the ascii table\n");
	check_return(result1, result2);
	result1 = printf("This is the octal number \\132 = \132 in the ascii table\n");
	result2 = ft_printf("This is the octal number \\132 = \132 in the ascii table\n");
	check_return(result1, result2);
	result1 = printf("This is the octal number \\133 = \133 in the ascii table\n");
	result2 = ft_printf("This is the octal number \\133 = \133 in the ascii table\n");
	check_return(result1, result2);
	result1 = printf("This is the octal number \\140 = \140 in the ascii table\n");
	result2 = ft_printf("This is the octal number \\140 = \140 in the ascii table\n");
	check_return(result1, result2);
	result1 = printf("This is the octal number \\141 = \141 in the ascii table\n");
	result2 = ft_printf("This is the octal number \\141 = \141 in the ascii table\n");
	check_return(result1, result2);
	result1 = printf("This is the octal number \\172 = \172 in the ascii table\n");
	result2 = ft_printf("This is the octal number \\172 = \172 in the ascii table\n");
	check_return(result1, result2);
	result1 = printf("This is the octal number \\173 = \173 in the ascii table\n");
	result2 = ft_printf("This is the octal number \\173 = \173 in the ascii table\n");
	check_return(result1, result2);
	result1 = printf("This is the octal number \\165 = \165\045\n");
	result2 = ft_printf("This is the octal number \\165 = \165\045\n");
	check_return(result1, result2);
}
