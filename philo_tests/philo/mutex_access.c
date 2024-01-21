/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_access.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 19:27:45 by gacalaza          #+#    #+#             */
/*   Updated: 2024/01/20 19:27:56 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/philo.h"

int	ft_getstatus(t_philo *philosopher)
{
	int	status;

	pthread_mutex_lock(&philosopher->table->mut_status);
	status = philosopher->status;
	pthread_mutex_unlock(&philosopher->table->mut_status);
	return (status);
}

void	ft_uplastmeal(t_philo *philosopher)
{
	pthread_mutex_lock(&philosopher->table->mut_meal);
	philosopher->last_meal = ft_get_time();
	pthread_mutex_unlock(&philosopher->table->mut_meal);
}

long long	ft_getlastmeal(t_philo *philosopher)
{
	long long	last;

	pthread_mutex_lock(&philosopher->table->mut_meal);
	last = philosopher->last_meal;
	pthread_mutex_unlock(&philosopher->table->mut_meal);
	return (last);
}

int	ft_should_i(t_table	*table)
{
	int	should_i;

	pthread_mutex_lock(&table->mut_should_i);
	should_i = table->should_i;
	pthread_mutex_unlock(&table->mut_should_i);
	return (should_i);
}

void	ft_upshould_i(t_table	*table, int stay_or_go)
{
	pthread_mutex_lock(&table->mut_should_i);
	table->should_i = stay_or_go;
	pthread_mutex_unlock(&table->mut_should_i);
}
