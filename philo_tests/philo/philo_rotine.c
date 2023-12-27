/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_rotine.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 16:43:42 by gacalaza          #+#    #+#             */
/*   Updated: 2023/12/27 18:44:50 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/philo.h"

void	pick_up_forks(t_philo *philosopher)
{
	pthread_mutex_lock(philosopher->l_fork);
	print_message(3, philosopher->id);
	pthread_mutex_lock(philosopher->r_fork);
	print_message(3, philosopher->id);
}

void	put_down_forks(t_philo *philosopher)
{
	pthread_mutex_unlock(philosopher->l_fork);
	pthread_mutex_unlock(philosopher->r_fork);
	// Sleeping
	print_message(4, philosopher->id);
	usleep(philosopher->table->sleep_time * 1000);
}

long long	ft_get_time(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL))
		return (0);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

int	ft_usleep(int time)
{
	long long	start;

	start = ft_get_time();
	while ((ft_get_time() - start) < time)
		usleep(time / 10);
	return (0);
}

void	*routine(void *arg)
{
	t_philo	*philosopher;

	philosopher = (t_philo *)arg;
	while (1)
	{
		// Eating
		pick_up_forks(philosopher);
		printf("%lld %d is eating\n", ft_get_time(), philosopher->id);
		usleep(philosopher->table->eat_time * 1000);
		put_down_forks(philosopher);
		// Thinking
		printf("%lld %d is thinking\n", ft_get_time(), philosopher->id);
		usleep(philosopher->times_to_eat * 1000);
		// Check if philosopher needs to eat a specific number of times
		if (philosopher->times_to_eat > 0)
		{
			philosopher->times_to_eat--;
			if (philosopher->times_to_eat == 0)
				break ; // Philosopher has eaten enough times, exit the loop
		}
	}
	return (NULL);
}
