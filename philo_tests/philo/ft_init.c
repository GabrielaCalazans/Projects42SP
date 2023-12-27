/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 15:15:13 by gacalaza          #+#    #+#             */
/*   Updated: 2023/12/27 18:09:01 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/philo.h"

	// Initialize philosophers and forks
int	ft_set_values(t_rout *table, int argc, char *argv[])
{
	table->t_philos = ft_atoi(argv[1]);
	table->death_time = ft_atoi(argv[2]);
	table->eat_time = ft_atoi(argv[3]);
	table->sleep_time = ft_atoi(argv[4]);
	if (argc == 6)
		table->t_eat = ft_atoi(argv[5]);
	else
		table->t_eat = -1;
	if (table->t_philos <= 0 || table->t_philos > 200 || table->death_time < 0
		|| table->eat_time < 0 || table->sleep_time < 0 || table->t_eat == 0)
		return (1);
	table->philos = (t_philo *)malloc(table->t_philos * sizeof(t_philo));
	table->forks = (pthread_mutex_t *)malloc(table->t_philos * sizeof(pthread_mutex_t));
	if (!table->philos || !table->forks)
	{
		printf("MALLOC ERROR set");
		return (1);
	}
	printf("PHILOS: %i DIE: %i EAT: %i SLEEP: %i N EATS: %i\n", table->t_philos, table->death_time, table->eat_time, table->sleep_time, table->t_eat);
	return (0);
}

void	ft_init_philo(t_rout *table)
{
	int	i;

	i = 0;
	while (i < table->t_philos)
		pthread_mutex_init(&table->forks[i++], NULL);
	i = 0;
	while (i < table->t_philos)
	{
		pthread_mutex_init(&table->forks[i], NULL);
		i++;
	}
	i = 0;
	while (i < table->t_philos)
	{
		printf("loop %i\n", i);
		table->philos[i].id = i + 1;
		table->philos[i].l_fork = &table->forks[i];
		table->philos[i].r_fork = &table->forks[(i + 1) % table->t_philos];
		table->philos[i].times_to_eat = table->t_eat;
		if (pthread_create(&table->philos[i].thread, NULL,
				routine, &table->philos[i]))
			exit(1);
		i++;
	}
}
