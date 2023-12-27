/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 14:59:51 by gacalaza          #+#    #+#             */
/*   Updated: 2023/12/27 17:51:11 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/philo.h"

void	cleanup_table(t_rout *table)
{
	int	i;

	i = 0;
	while (i < table->t_philos)
	{
		pthread_mutex_destroy(&table->forks[i]);
		i++;
	}
}

void	ft_clean(t_rout *table)
{
	if (table->forks)
		cleanup_table(table);
	if (table->philos)
		free(table->philos);
	if (table->forks)
		free(table->forks);
}
