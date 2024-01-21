/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:08:38 by gacalaza          #+#    #+#             */
/*   Updated: 2024/01/20 19:27:41 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/philo.h"

long long	ft_get_time(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL))
		return (0);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

long long	ft_time(t_table *table, long long now)
{
	long long	start;

	start = table->start_time;
	return (now - start);
}

void	ft_usleep(int time)
{
	long long	start;

	start = ft_get_time();
	while ((ft_get_time() - start) < time)
		usleep(time);
}

long long	ft_getsleep(t_table *table, int type)
{
	long long	time;

	pthread_mutex_lock(&table->mut_time);
	if (type == DEAD)
		time = table->death_time;
	if (type == EATING)
		time = table->eat_time;
	if (type == SLEEPING)
		time = table->sleep_time;
	pthread_mutex_unlock(&table->mut_time);
	return (time);
}

void	ft_upstatus(t_philo *philosopher, int status)
{
	pthread_mutex_lock(&philosopher->table->mut_status);
	philosopher->status = status;
	pthread_mutex_unlock(&philosopher->table->mut_status);
}
