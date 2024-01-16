/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 15:15:13 by gacalaza          #+#    #+#             */
/*   Updated: 2024/01/15 17:46:34 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/philo.h"

	// Initialize philosophers and forks
int	ft_set_values(t_table *table, int argc, char *argv[])
{
	table->n_philos = ft_atoi(argv[1]);
	table->death_time = ft_atoi(argv[2]);
	table->eat_time = ft_atoi(argv[3]);
	table->sleep_time = ft_atoi(argv[4]);
	if (argc == 6)
		table->t_eat = ft_atoi(argv[5]);
	else
		table->t_eat = -1;
	if (table->n_philos <= 0 || table->n_philos > 200 || table->death_time < 0
		|| table->eat_time < 0 || table->sleep_time < 0 || table->t_eat == 0)
		return (ft_error(ERR_IN_2, table));
	table->philos = (t_philo *)malloc(table->n_philos * sizeof(t_philo));
	table->threads = (pthread_t *)malloc(table->n_philos * sizeof(pthread_t));
	table->forks = malloc(table->n_philos * sizeof(pthread_mutex_t));
	if (!table->philos || !table->forks || !table->threads)
		return (ft_error(A_ERR_0, table));
	table->start_time = ft_get_time();
	return (0);
}

int	init_locks(t_table *table)
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
	if (pthread_mutex_init(&table->lock, NULL))
		return (ft_error(M_ERR_0, table));
	if (pthread_mutex_init(&table->philos->lock, NULL))
		return (ft_error(M_ERR_0, table));
	return (0);
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
	while (i < table->n_philos)
	{
		if (pthread_join(table->philos[i].thread, NULL))
			return (ft_error(JOIN_ERR, table));
		i++;
	}
	return (0);
}

int	ft_init_philo(t_table *table)
{
	int	i;
	int	philos;

	if (init_locks(table))
		return (1);
	philos = table->n_philos;
	i = 0;
	while (i < philos)
	{
		table->philos[i].table = table;
		table->philos[i].id = i + 1;
		table->philos[i].times_to_eat = table->t_eat;
		i++;
	}
	return (0);
}
