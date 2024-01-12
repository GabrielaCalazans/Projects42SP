/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 18:19:57 by gacalaza          #+#    #+#             */
/*   Updated: 2024/01/12 16:09:23 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/philo.h"

void	print_message(int check, t_philo *philosopher)
{
	// long long	time;
	// long long	now;
	// long long	start;

	// // pthread_mutex_lock(&philosopher->table->print);
	// now = ft_get_time();
	// start = philosopher->table->start_time;
	// time = now - start;
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

int	ft_philo_usage(int check)
{
	if (check == 0)
	{
		printf("To run the program you will need the follow arguments:\n");
		printf("1º number of philosophers\n");
		printf("2º death_time\n");
		printf("3º eat_time\n");
		printf("4º sleep_time\n");
		printf("5º[number_of_times_each_philosopher_must_eat]\n");
		printf("Usage: ./philo <number_of_philosophers> \
				<death_time> <eat_time> <sleep_time> \
					[<number_of_times_each_philosopher_must_eat>]\n");
	}
	else
		printf("The program only accepts arguments in numerical digits.\n");
	return (1);
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
	return (0);
}

int	main(int argc, char *argv[])
{
	t_table	table;

	if (check_args(argc, argv))
		return (1);
	if (ft_set_values(&table, argc, argv))
		return (1);
	if (ft_init_philo(&table))
		return (1);
	cleanup_table(&table);
	free(table.philos);
	free(table.forks);
	return (0);
}
