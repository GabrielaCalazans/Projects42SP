/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 15:15:13 by gacalaza          #+#    #+#             */
/*   Updated: 2023/12/27 21:26:23 by gacalaza         ###   ########.fr       */
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
		ft_putendl_fd("ERROR MALLOC set", 2);
		return (1);
	}
	return (0);
}

void	init_locks(t_rout *table)
{
	int	i;

	i = 0;
	while (i < table->t_philos)
		pthread_mutex_init(&table->forks[i++], NULL);
	i = 0;
	while (i++ < table->t_philos)
	{
		pthread_mutex_init(&table->forks[i], NULL);
		i++;
	}
	pthread_mutex_init(&table->print, NULL);
}

int	ft_init_philo(t_rout *table)
{
	int	i;

	i = 0;
	init_locks(table);
	while (i < table->t_philos)
	{
		printf("loop %i\n", i);
		table->philos[i].id = i + 1;
		table->philos[i].l_fork = &table->forks[i];
		table->philos[i].r_fork = &table->forks[(i + 1) % table->t_philos];
		table->philos[i].times_to_eat = table->t_eat;
		if (pthread_create(&table->philos[i].thread, NULL,
				routine, &table->philos[i]))
			return (1);
		i++;
	}
	return (0);
}

void	print_message(int check, t_philo *philosopher)
{
	// pthread_mutex_lock(&philosopher->table->print);
	if (check == 0)
		printf("%lld %d is thinking\n", ft_get_time(), philosopher->id);
	if (check == 1)
		printf("%lld %d is eating\n", ft_get_time(), philosopher->id);
	if (check == 3)
		printf("%lld %d has taken a fork\n", ft_get_time(), philosopher->id);
	if (check == 4)
		printf("%lld %d is sleeping\n", ft_get_time(), philosopher->id);
	if (check == 5)
		printf("%lld %d died\n", ft_get_time(), philosopher->id);
	// pthread_mutex_unlock(&philosopher->table->print);
}
