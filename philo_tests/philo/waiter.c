/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   waiter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 17:57:08 by gacalaza          #+#    #+#             */
/*   Updated: 2024/01/17 20:57:40 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/philo.h"

void	did_philo_died(t_philo *philosopher)
{
	
}

void	spread_gossip(t_table *table)
{

}

void	*thanatos(void *arg)
{
	t_philo	*waiter;

	waiter = (t_philo *)arg;
	while (ft_getstatus(waiter) != DIED)
	{

	}
	if (ft_getstatus(waiter) == DIED)
		spread_gossip(waiter->table);
	return (NULL);
}
