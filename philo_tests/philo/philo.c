/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 18:19:57 by gacalaza          #+#    #+#             */
/*   Updated: 2024/01/16 18:06:18 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/philo.h"

void	print_message(int check, t_philo *philosopher)
{
	long long	time;

	pthread_mutex_lock(&philosopher->table->print);
	time = ft_time(philosopher->table);
	if (check == 0)
		printf("%lld %d is thinking\n", time, philosopher->id);
	if (check == 1)
		printf("%lld %d is eating\n", time, philosopher->id);
	if (check == 3)
		printf("%lld %d has taken a fork\n", time, philosopher->id);
	if (check == 4)
		printf("%lld %d is sleeping\n", time, philosopher->id);
	if (check == 5)
		printf("%lld %d died\n", time, philosopher->id);
	pthread_mutex_unlock(&philosopher->table->print);
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
		printf("5º[number_of_times_each_philosopher_musn_eat]\n");
		printf("Usage: ./philo <number_of_philosophers> \
				<death_time> <eat_time> <sleep_time> \
					[<number_of_times_each_philosopher_musn_eat>]\n");
	}
	else
		printf("The program only accepts arguments in numerical digits.\n");
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
	t_table	*table;

	table = malloc(sizeof(t_table));
	if (check_args(argc, argv))
		return (EERROR);
	if (ft_set_values(table, argc, argv))
		return (EERROR);
	if (ft_init_philo(table))
		return (EERROR);
	if (ft_init_thread(table))
		return (EERROR);
	ft_clean(table);
	return (S_SUCESS);
}
