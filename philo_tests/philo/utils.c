/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:08:38 by gacalaza          #+#    #+#             */
/*   Updated: 2024/01/15 17:47:26 by gacalaza         ###   ########.fr       */
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

void	ft_spleep(t_philo *philosopher)
{
	print_message(4, philosopher);
	usleep(philosopher->table->sleep_time * 1000);
}
