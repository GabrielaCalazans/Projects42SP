/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 14:55:33 by gacalaza          #+#    #+#             */
/*   Updated: 2023/04/05 21:14:53 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minitalk.h"
#include "stdio.h"

void	handler(int num)
{
	write(STDOUT_FILENO, "I won't die!\n", 13);
}

int	main()
{
	signal(SIGINT, handler); // kill -KILL id
	while (1)
	{
		printf("Days left in your life [%d]\n", getpid());
		sleep(3);
	}
	return 0;
}
