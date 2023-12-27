/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 18:19:57 by gacalaza          #+#    #+#             */
/*   Updated: 2023/12/27 18:43:18 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/philo.h"

void	ft_philo_usage(void)
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

void	print_message(int check, int philo_id)
{
	if (check == 0)
		printf("%lld %d is thinking\n", ft_get_time(), philo_id);
	if (check == 1)
		printf("%lld %d is eating\n", ft_get_time(), philo_id);
	if (check == 3)
		printf("%lld %d has taken a fork\n", ft_get_time(), philo_id);
	if (check == 4)
		printf("%lld %d is sleeping\n", ft_get_time(), philo_id);
	if (check == 5)
		printf("%lld %d died\n", ft_get_time(), philo_id);
}

int	main(int argc, char *argv[])
{
	t_rout	table;
	int		i;

	if (argc != 6 && argc != 5)
	{
		ft_philo_usage();
		return (EXIT_FAILURE);
	}
	if (ft_set_values(&table, argc, argv))
		ft_clean(&table);
	ft_init_philo(&table);
	i = 0;
	// Wait for all philosopher threads to finish
	while (i++ < table.t_philos)
	{
		if (pthread_join(table.philos[i].thread, NULL))
			return (EXIT_FAILURE);
	}
	cleanup_table(&table);
	free(table.philos);
	free(table.forks);
	return (EXIT_SUCCESS);
}
