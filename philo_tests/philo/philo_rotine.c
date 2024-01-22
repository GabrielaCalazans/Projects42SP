/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_rotine.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 16:43:42 by gacalaza          #+#    #+#             */
/*   Updated: 2024/01/22 14:43:12 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/philo.h"

void	ft_uptteat(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->mut_tteat);
	philo->times_to_eat--;
	pthread_mutex_unlock(&philo->table->mut_tteat);
}

int	ft_gettteat(t_philo *philo)
{
	int	eat_times;

	pthread_mutex_lock(&philo->table->mut_tteat);
	eat_times = philo->times_to_eat;
	pthread_mutex_unlock(&philo->table->mut_tteat);
	return (eat_times);
}

static void	ft_eat_one(t_philo *philo)
{
	if (ft_getstatus(philo) == DEAD)
		return ;
	ft_upstatus(philo, EATING);
	pthread_mutex_lock(philo->l_fork);
	print_message(3, philo, ft_get_time());
	ft_usleep(ft_getsleep(philo->table, DEAD));
	pthread_mutex_unlock(philo->l_fork);
}

static int	process_rotine(t_philo *philo)
{
	if (ft_eat(philo))
		return (1);
	if (ft_getstatus(philo) == DEAD)
		return (1);
	if (ft_spleep(philo))
		return (1);
	if (ft_getstatus(philo) == DEAD)
		return (1);
	if (ft_think(philo))
		return (1);
	return (0);
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
		if (process_rotine(philo))
			break ;
		if (ft_gettteat(philo) > 0)
		{
			ft_uptteat(philo);
			if (ft_gettteat(philo) == 0)
				break ;
		}
	}
	return (NULL);
}
