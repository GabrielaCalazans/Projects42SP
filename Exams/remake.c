/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remake.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 15:40:15 by gacalaza          #+#    #+#             */
/*   Updated: 2024/06/01 16:05:00 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "microshell.h"

int	err(char *str)
{
	int	i;
	
	i = 0;
	while (str[i] != '\0')
	{
		write(2, &str[i], 1);
		i++;
	}
	return (1);
}

int	cd(char *argv[], int i)
{
	if (i != 2)
		return (err("error: cd: bad arguments\n"));
	if (chdir(argv[1]) == -1)
		return (err("error: cd: cannot change directory to "), err(argv[1]), err('\n'));
	return (0);
}

int	exec(char *argv[], char *envp[])
{

}

int	main(int argc, char *argv[], char *envp[])
{

	return (0);
}
