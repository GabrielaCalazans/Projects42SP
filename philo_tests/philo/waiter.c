/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   waiter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 17:57:08 by gacalaza          #+#    #+#             */
/*   Updated: 2024/01/18 23:56:58 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/philo.h"

// void	did_philo_died(t_philo *philosopher)
// {
	
// }

// void	spread_gossip(t_table *table)
// {

// }

void	*thanatos(void *arg)
{
	t_philo	*philos;
	t_table	*table;
	int		i;
	int		len;

	table = (t_table *)arg;
	philos = table->philos;
	len = table->n_philos;
	i = -1;
	while (++i < len && ft_should_i(table))
	{
		if (philo_died(&philos[i]) && ft_should_i(table))
		{
			print_message(5, &philos[i]);
			ft_set_should_i(table, GO);
			spread_gossip(table);
			break ;
		}
		if (i == len - 1)
			i = -1;
	}
	if (ft_getstatus(philos) == DEAD)
		spread_gossip(table);
	return (NULL);
}
