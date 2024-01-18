/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:08:38 by gacalaza          #+#    #+#             */
/*   Updated: 2024/01/17 19:16:06 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/philo.h"

int	ft_error(char *error, t_table *table)
{
	printf("%s", error);
	ft_clean(table);
	return (1);
}

long long	ft_get_time(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL))
		return (0);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

long long	ft_time(t_table *table)
{
	long long	now;
	long long	start;

	now = ft_get_time();
	start = table->start_time;
	return (now - start);
}

void	ft_usleep(int time)
{
	long long	start;

	start = ft_get_time();
	while ((ft_get_time() - start) < time)
		usleep(time / 10);
}

void	ft_upstatus(t_philo *philosopher, int status)
{
	pthread_mutex_lock(&philosopher->mut_status);
	philosopher->table->status = status;
	pthread_mutex_unlock(&philosopher->mut_status);
}

void	ft_upmeal(t_philo *philosopher)
{
	pthread_mutex_lock(&philosopher->mut_meal);
	philosopher->last_meal = ft_get_time();
	pthread_mutex_unlock(&philosopher->mut_meal);
}

int	ft_getstatus(t_philo *philosopher)
{
	int	status;

	pthread_mutex_lock(&philosopher->mut_status);
	status = philosopher->table->status;
	pthread_mutex_unlock(&philosopher->mut_status);
	return (status);
}