/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_rotine.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 16:43:42 by gacalaza          #+#    #+#             */
/*   Updated: 2024/01/20 22:10:10 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/philo.h"

void	ft_eat_one(t_philo *philo)
{
	if (ft_getstatus(philo) == DEAD)
		return ;
	ft_upstatus(philo, EATING);
	pthread_mutex_lock(philo->l_fork);
	print_message(3, philo, ft_get_time());
	ft_usleep(ft_getsleep(philo->table, DEAD));
	pthread_mutex_unlock(philo->l_fork);
}

	// ft_usleep(philo->table->eat_time - 10);
void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		usleep(1000);
	if (philo->table->n_philos == 1)
		ft_eat_one(philo);
	while (ft_getstatus(philo) != DEAD && philo->table->n_philos > 1)
	{
		if (ft_eat(philo))
			break ;
		if (ft_getstatus(philo) == DEAD)
			break ;
		if (ft_spleep(philo))
			break ;
		if (ft_getstatus(philo) == DEAD)
			break ;
		if (ft_think(philo))
			break ;
		if (philo->times_to_eat > 0)
		{
			philo->times_to_eat--;
			if (philo->times_to_eat == 0)
				break ;
		}
	}
	return (NULL);
}
