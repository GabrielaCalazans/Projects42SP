/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 15:15:13 by gacalaza          #+#    #+#             */
/*   Updated: 2024/01/18 21:45:08 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/philo.h"

int	ft_allocation(t_table *table)
{
	table->philos = (t_philo *)malloc(table->n_philos * sizeof(t_philo));
	if (!table->philos)
		return (ft_error(A_ERR_0, table));
	table->forks = malloc(table->n_philos * sizeof(pthread_mutex_t));
	if (!table->forks)
		return (ft_error(A_ERR_0, table));
	return (S_SUCESS);
}

int	ft_set_values(t_table *table, int argc, char *argv[])
{
	table->n_philos = ft_atoi(argv[1]);
	table->death_time = ft_atoi(argv[2]);
	table->eat_time = ft_atoi(argv[3]);
	table->sleep_time = ft_atoi(argv[4]);
	table->n_eat = -1;
	if (argc == 6)
		table->n_eat = ft_atoi(argv[5]);
	if (table->n_philos <= 0 || table->n_philos > 200 || table->death_time < 60
		|| table->eat_time < 60 || table->sleep_time < 60 || table->n_eat == 0)
		return (ft_error(ERR_IN_2, table));
	ft_allocation(table);
	return (S_SUCESS);
}

int	ft_init_locks(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->n_philos)
	{
		if (pthread_mutex_init(&table->forks[i++], NULL))
			return (ft_error(M_ERR_0, table));
	}
	i = 0;
	while (i < table->n_philos)
	{
		table->philos[i].l_fork = &table->forks[i];
		if (i == 0)
			table->philos[i].r_fork = &table->forks[table->n_philos - 1];
		else
			table->philos[i].r_fork = &table->forks[i - 1];
		i++;
	}
	if (pthread_mutex_init(&table->print, NULL))
		return (ft_error(M_ERR_0, table));
	if (pthread_mutex_init(&table->mut_should_i, NULL))
		return (ft_error(M_ERR_0, table));
	if (pthread_mutex_init(&table->philos->mut_status, NULL))
		return (ft_error(M_ERR_0, table));
	if (pthread_mutex_init(&table->philos->mut_meal, NULL))
		return (ft_error(M_ERR_0, table));
	return (S_SUCESS);
}

int	ft_init_thread(t_table *table)
{
	int	i;

	i = 0;
	table->start_time = ft_get_time();
	while (i < table->n_philos)
	{
		if (pthread_create(&table->philos[i].thread, NULL,
				&routine, &table->philos[i]))
			return (ft_error(TH_ERR, table));
		ft_usleep(1);
		i++;
	}
	i = 0;
	// if (pthread_create(&table->waiter.thread, NULL,
	// 		&tend, &table->waiter))
	// 	return (ft_error(TH_ERR, table));
	while (i < table->n_philos)
	{
		if (pthread_join(table->philos[i].thread, NULL))
			return (ft_error(JOIN_ERR, table));
		i++;
	}
	// if (pthread_join(table->waiter.thread, NULL))
	// 	return (ft_error(JOIN_ERR, table));
	return (S_SUCESS);
}

	// Initialize philosophers
int	ft_init_philo(t_table *table)
{
	int	i;
	int	philos;

	if (ft_init_locks(table))
		return (EERROR);
	philos = table->n_philos;
	i = 0;
	while (i < philos)
	{
		table->philos[i].table = table;
		table->philos[i].id = i + 1;
		table->philos[i].times_to_eat = table->n_eat;
		table->philos[i].last_meal = 0;
		i++;
	}
	table->waiter.table = table;
	return (S_SUCESS);
}
