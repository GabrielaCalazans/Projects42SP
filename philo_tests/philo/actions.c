/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 19:29:47 by gacalaza          #+#    #+#             */
/*   Updated: 2024/01/20 21:54:03 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/philo.h"

int	ft_spleep(t_philo *philosopher)
{
	if (ft_getstatus(philosopher) == DEAD)
		return (1);
	ft_upstatus(philosopher, SLEEPING);
	print_message(4, philosopher, ft_get_time());
	ft_usleep(ft_getsleep(philosopher->table, SLEEPING));
	return (0);
}

int	ft_eat(t_philo *philosopher)
{
	if (ft_getstatus(philosopher) == DEAD)
		return (1);
	ft_upstatus(philosopher, EATING);
	pick_up_forks(philosopher);
	print_message(1, philosopher, ft_get_time());
	ft_usleep(ft_getsleep(philosopher->table, EATING));
	put_down_forks(philosopher);
	ft_uplastmeal(philosopher);
	return (0);
}

int	ft_think(t_philo *philosopher)
{
	if (ft_getstatus(philosopher) == DEAD)
		return (1);
	ft_upstatus(philosopher, THINKING);
	print_message(0, philosopher, ft_get_time());
	return (0);
}

void	pick_up_forks(t_philo *philo)
{
	if (philo->id % 2 == 1)
	{
		pthread_mutex_lock(philo->l_fork);
		print_message(3, philo, ft_get_time());
		pthread_mutex_lock(philo->r_fork);
		print_message(3, philo, ft_get_time());
	}
	else
	{
		pthread_mutex_lock(philo->r_fork);
		print_message(3, philo, ft_get_time());
		pthread_mutex_lock(philo->l_fork);
		print_message(3, philo, ft_get_time());
	}
}

void	put_down_forks(t_philo *philosopher)
{
	pthread_mutex_unlock(philosopher->l_fork);
	pthread_mutex_unlock(philosopher->r_fork);
}
