/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   waiter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 17:57:08 by gacalaza          #+#    #+#             */
/*   Updated: 2024/01/19 21:01:35 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/philo.h"

int	did_philo_died(t_philo *philo)
{
	int			meal_time;

	meal_time = ft_getsleep(philo->table, DEAD);
	if (ft_get_time()- ft_getlastmeal(philo) > meal_time
		&& ft_getstatus(philo) != EATING)
	{
		ft_upstatus(philo, DEAD);
		return (DEAD);
	}
	if (philo->table->n_philos < 2
		&& ft_get_time()- ft_getlastmeal(philo) > meal_time)
	{
		ft_upstatus(philo, DEAD);
		return (DEAD);
	}
	return (0);
}

void	spread_gossip(t_table *table)
{
	int		i;
	t_philo	*philo;

	i = 0;
	philo = table->philos;
	while (i < table->n_philos)
	{
		ft_upstatus(&philo[i], DEAD);
		i++;
	}
}

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
		if (did_philo_died(&philos[i]) && ft_should_i(table))
		{
			print_message(5, &philos[i]);
			ft_upshould_i(table, GO);
			spread_gossip(table);
			break ;
		}
		if (i == len - 1)
			i = -1;
		usleep(1000);
	}
	return (NULL);
}
