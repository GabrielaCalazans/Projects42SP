/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 18:19:57 by gacalaza          #+#    #+#             */
/*   Updated: 2023/12/21 19:58:06 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/philo.h"

void	ft_philo_usage(void)
{
	printf("To run the program you will need the follow arguments:\n");
	printf("1º number of philosophers\n");
	printf("2º time_to_die\n"); 
	printf("3º time_to_eat\n");
	printf("4º time_to_sleep\n");
	printf("5º[number_of_times_each_philosopher_must_eat]\n");
	printf("Usage: ./philo <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> [<number_of_times_each_philosopher_must_eat>]\n");
}

int	ft_isdigit(int argument)
{
	if (argument >= '0' && argument <= '9')
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *nptr)
{
	size_t	result;
	int		count;
	int		sign;

	count = 0;
	result = 0;
	sign = 1;
	while ((nptr[count] >= 9 && nptr[count] <= 13) || nptr[count] == 32)
	{
		count++;
	}
	if (nptr[count] == '-' || nptr[count] == '+')
	{
		if (nptr[count] == '-')
			sign = -1;
		count++;
	}
	while (nptr[count] != '\0' && ft_isdigit(nptr[count]))
	{
		result = (result * 10) + (nptr[count] - '0');
		count++;
	}
	return (result * sign);
}


void	ft_set_values(t_rout *table, int argc, char *argv[])
{
	table->num_philos = ft_atoi(argv[1]);
	table->time_to_die = ft_atoi(argv[2]);
	table->time_to_eat = ft_atoi(argv[3]);
	table->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
	{
		table->num_times_each_philo_must_eat = ft_atoi(argv[5]);
	}
	else
	{
		table->num_times_each_philo_must_eat = -1;
	}
	// Initialize philosophers and forks
	table->philosophers = (t_philo *)malloc(table->num_philos * sizeof(t_philo));
	table->forks = (pthread_mutex_t *)malloc(table->num_philos * sizeof(pthread_mutex_t));
}

void	ft_init_philo(t_rout *table)
{
	int	i;

	i = 0;
	while (i < table->num_philos)
	{
		pthread_mutex_init(&table->forks[i], NULL);
		i++;
	}
	i = 0;
	while (i++ < table->num_philos)
	{
		pthread_mutex_init(&table->forks[i], NULL);
	}

    while (i++ < table->num_philos)
	{
		table->philosophers[i].number = i + 1;
		table->philosophers[i].left_fork = &table->forks[i];
		table->philosophers[i].right_fork = &table->forks[(i + 1) % table->num_philos];
		table->philosophers[i].times_to_eat = table->num_times_each_philo_must_eat;
		pthread_create(&table->philosophers[i].thread, NULL, philosopher_routine, &table->philosophers[i]);
	}
}

void	cleanup_table(t_rout *table)
{
	int	i;

	i = 0;
	while (i < table->num_philos)
	{
		pthread_mutex_destroy(&table->forks[i]);
		i++;
	}
}

void	*philosopher_routine(void *arg)
{
	t_philo	*philosopher;

	philosopher = (t_philo *)arg;
	while (1)
	{
		// Thinking
		printf("%lld %d is thinking\n", get_timestamp_ms(), philosopher->number);
		usleep(philosopher->times_to_eat * 1000);

		// Eating
		pick_up_forks(philosopher);
		printf("%lld %d has taken a fork\n", get_timestamp_ms(), philosopher->number);
		printf("%lld %d has taken a fork\n", get_timestamp_ms(), philosopher->number);
		printf("%lld %d is eating\n", get_timestamp_ms(), philosopher->number);
		usleep(philosopher->times_to_eat * 1000);
		put_down_forks(philosopher);

		// Sleeping
		printf("%lld %d is sleeping\n", get_timestamp_ms(), philosopher->number);
		usleep(philosopher->times_to_eat * 1000);

		// Check if philosopher needs to eat a specific number of times
		if (philosopher->times_to_eat > 0)
		{
			philosopher->times_to_eat--;
			if (philosopher->times_to_eat == 0) {
				break; // Philosopher has eaten enough times, exit the loop
			}
		}
	}

    return NULL;
}

void	pick_up_forks(t_philo *philosopher)
{
	pthread_mutex_lock(philosopher->left_fork);
	pthread_mutex_lock(philosopher->right_fork);
}

void	put_down_forks(t_philo *philosopher)
{
	pthread_mutex_unlock(philosopher->left_fork);
	pthread_mutex_unlock(philosopher->right_fork);
}

long long	get_timestamp_ms(void)
{
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return (long long)(tv.tv_sec) * 1000 + (long long)(tv.tv_usec) / 1000;
}


int	main(int argc, char *argv[])
{
	t_rout	table;
	int		i;
	
	if (argc != 6)
	{
		ft_philo_usage();
		return (EXIT_FAILURE);
	}
	ft_set_values(&table, argc, argv);
	ft_init_philo(&table);
	i = 0;
	// Wait for all philosopher threads to finish
	while (i++ < table.num_philos)
	{
		pthread_join(table.philosophers[i].thread, NULL);
	}
	// Clean up
	cleanup_table(&table);
	free(table.philosophers);
	free(table.forks);
	return (EXIT_SUCCESS);
}
