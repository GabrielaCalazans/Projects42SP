/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 18:19:57 by gacalaza          #+#    #+#             */
/*   Updated: 2023/12/27 21:25:31 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/philo.h"

void	ft_philo_usage(int check)
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
}

int	check_args(int argc, char *argv[])
{
	int	i;
	int	j;

	if (argc != 6 && argc != 5)
	{
		ft_philo_usage(0);
		return (1);
	}
	i = 1;
	while (argv[i] != NULL)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (!ft_isdigit(argv[i][j]))
			{
				printf("%c", argv[i][j]);
				ft_philo_usage(2);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	t_rout	table;
	int		i;

	if (check_args(argc, argv))
		return (1);
	if (ft_set_values(&table, argc, argv))
	{
		ft_clean(&table);
		return (1);
	}
	if (ft_init_philo(&table))
		return (1);
	i = 0;
	// Wait for all philosopher threads to finish
	while (i++ < table.t_philos)
	{
		if (pthread_join(table.philos[i].thread, NULL))
			return (1);
	}
	cleanup_table(&table);
	free(table.philos);
	free(table.forks);
	return (0);
}
