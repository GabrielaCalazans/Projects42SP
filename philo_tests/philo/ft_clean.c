/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 14:59:51 by gacalaza          #+#    #+#             */
/*   Updated: 2024/01/15 18:57:42 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/philo.h"

void	cleanup_table(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->n_philos)
	{
		pthread_mutex_destroy(&table->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&table->print);
	pthread_mutex_destroy(&table->lock);
	pthread_mutex_destroy(&table->philos->lock);
}

void	ft_clean(t_table *table)
{
	if (table->forks)
		cleanup_table(table);
	if (table->philos)
		free(table->philos);
	if (table->forks)
		free(table->forks);
	if (table->threads)
		free(table->threads);
}
