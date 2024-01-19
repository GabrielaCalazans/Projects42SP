/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_rotine.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 16:43:42 by gacalaza          #+#    #+#             */
/*   Updated: 2024/01/18 21:32:47 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/philo.h"

int	ft_spleep(t_philo *philosopher)
{
	if (ft_getstatus(philosopher) == DEAD)
		return (1);
	ft_upstatus(philosopher, SLEEPING);
	print_message(4, philosopher);
	ft_usleep(philosopher->table->sleep_time);
	return (0);
}

int	ft_eat(t_philo *philosopher)
{
	if (ft_getstatus(philosopher) == DEAD)
		return (1);
	ft_upstatus(philosopher, EATING);
	pick_up_forks(philosopher);
	ft_upmeal(philosopher);
	print_message(1, philosopher);
	ft_usleep(philosopher->table->eat_time);
	put_down_forks(philosopher);
	return (0);
}

int	ft_think(t_philo *philosopher)
{
	if (ft_getstatus(philosopher) == DEAD)
		return (1);
	ft_upstatus(philosopher, THINKING);
	print_message(0, philosopher);
	return (0);
}

void	pick_up_forks(t_philo *philosopher)
{
	pthread_mutex_lock(philosopher->l_fork);
	print_message(3, philosopher);
	pthread_mutex_lock(philosopher->r_fork);
	print_message(3, philosopher);
}

void	put_down_forks(t_philo *philosopher)
{
	pthread_mutex_unlock(philosopher->l_fork);
	pthread_mutex_unlock(philosopher->r_fork);
}

void	*routine(void *arg)
{
	t_philo	*philosopher;

	philosopher = (t_philo *)arg;
	if (philosopher->id % 2 == 0)
		ft_usleep(philosopher->table->eat_time / 10);
	while (ft_getstatus(philosopher) != DEAD)
	{
		if (ft_eat(philosopher))
			break ;
		if (ft_getstatus(philosopher) == DEAD)
			break ;
		if (ft_spleep(philosopher))
			break ;
		if (ft_think(philosopher))
			break ;
		if (philosopher->times_to_eat > 0)
		{
			philosopher->times_to_eat--;
			if (philosopher->times_to_eat == 0)
				break ;
		}
	}
	return (NULL);
}
