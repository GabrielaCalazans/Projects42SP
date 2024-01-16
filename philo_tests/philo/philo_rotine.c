/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_rotine.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 16:43:42 by gacalaza          #+#    #+#             */
/*   Updated: 2024/01/15 21:44:53 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/philo.h"

void	ft_spleep(t_philo *philosopher)
{
	print_message(4, philosopher);
	usleep(philosopher->table->sleep_time * 1000);
}

void	ft_eat(t_philo *philosopher)
{
	pick_up_forks(philosopher);
	print_message(1, philosopher);
	usleep(philosopher->table->eat_time * 1000);
	put_down_forks(philosopher);
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
	while (1)
	{
		ft_eat(philosopher);
		ft_spleep(philosopher);
		print_message(0, philosopher);
		if (philosopher->times_to_eat > 0)
		{
			philosopher->times_to_eat--;
			if (philosopher->times_to_eat == 0)
				break ;
		}
	}
	return (NULL);
}
