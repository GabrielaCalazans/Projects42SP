/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 18:19:57 by gacalaza          #+#    #+#             */
/*   Updated: 2024/01/22 13:14:12 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/philo.h"

int	ft_error(char *error, t_table *table)
{
	printf("%s", error);
	ft_clean(table);
	return (1);
}

void	print_message(int check, t_philo *philo, long long time)
{
	long long	time_ms;

	if (ft_getstatus(philo) == DEAD && check != DEAD)
		return ;
	pthread_mutex_lock(&philo->table->print);
	time_ms = ft_time(philo->table, time);
	if (check == 0)
		printf("%lld %d is thinking\n", time_ms, philo->id);
	if (check == 1)
		printf("%lld %d is eating\n", time_ms, philo->id);
	if (check == 3)
		printf("%lld %d has taken a fork\n", time_ms, philo->id);
	if (check == 4)
		printf("%lld %d is sleeping\n", time_ms, philo->id);
	if (check == 5)
		printf("%lld %d died\n", time_ms, philo->id);
	pthread_mutex_unlock(&philo->table->print);
}

int	ft_philo_usage(int check)
{
	if (check == 0)
	{
		printf("To run the program you will need the follow arguments:\n");
		printf("1º number of philosophers\n");
		printf("2º death_time\n");
		printf("3º eat_time\n");
		printf("4º sleep_time\n");
		printf("5º OPTIONAL: number_of_times_each_philosopher_must_eat\n");
		printf("Example:\n");
		printf("./philo 4 800 200 200 5\n\n");
		printf("number of philosopherss: 1-200\n");
		printf("death_time: 60+\n");
		printf("eat_time: 60+\n");
		printf("sleep_time: 60+\n");
		printf("number_of_times_each_philosopher_must_eat: ");
		printf("> 0\n");
	}
	else
		printf("This program only accepts numbers above zero.\n");
	return (EERROR);
}

int	check_args(int argc, char *argv[])
{
	int	i;
	int	j;

	if (argc != 6 && argc != 5)
		return (ft_philo_usage(0));
	i = 1;
	while (argv[i] != NULL)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (!ft_isdigit(argv[i][j]))
				return (ft_philo_usage(2));
			j++;
		}
		i++;
	}
	return (S_SUCESS);
}

int	main(int argc, char *argv[])
{
	t_table	table;

	if (check_args(argc, argv))
		return (EERROR);
	if (ft_set_values(&table, argc, argv))
		return (EERROR);
	if (ft_init_philo(&table))
		return (EERROR);
	if (ft_init_thread(&table))
		return (EERROR);
	ft_clean(&table);
	return (S_SUCESS);
}
