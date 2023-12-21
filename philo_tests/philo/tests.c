/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 15:36:13 by gacalaza          #+#    #+#             */
/*   Updated: 2023/12/21 17:42:26 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/philo.h"
void	*computation();

# define SIZE 10

int v[SIZE];

void	*function(void *arg)
{
	int	*valor;
	int	i;

	valor = (int *)(arg);
	if (*valor == 1)
	{
		printf("Thread 1 executando...\n");
		for (i = 0; i < SIZE / 2; i++)
		{
			v[i] = 3;
		}
	}
	else
	{
		printf("Thread 2 executando...\n");
		for (i = SIZE / 2; i < SIZE; i++)
		{
			v[i] = 5;
		}
	}
	return (NULL);
}

void	*myturn(void *arg)
{
	(void)arg;
	int	i;
	int	len;

	i = 0;
	len = 8;
	while (i < len)
	{
		sleep(1);
		if (i + 1 == len)
			printf("My Turn has reached the final point.\n");
		else
			printf("My Turn! %i\n", i);
		i++;
	}
	return (NULL);
}

void	yourturn()
{
	int	i;
	int	len;

	i = 0;
	len = 4;
	while (i < len)
	{
		sleep(1);
		if (i + 1 == len)
			printf("Your Turn has reached the final point.\n");
		else
			printf("Your Turn!%i\n", i);
		i++;
	}
}

int	main (void)
{
	// pthread_t	t1;
	// pthread_t	t2;
	// int			a1;
	// int			a2;
	// int			i;

	// a1 = 1;
	// a2 = 2;
	// pthread_create(&t1, NULL, function, (void *)(&a1));
	// pthread_create(&t2, NULL, function, (void *)(&a2));
	// pthread_join(t1, NULL);
	// pthread_join(t2, NULL);
	// for (i = 0; i < SIZE; i++)
	// {
	// 	if (i == 0)
	// 		printf("Vector: ");
	// 	printf("%d ", v[i]);
	// }
	// printf("\n");
	// exit (0);

// ********** TEST 2 ************************
	
	// // pthread_t	thread1;
	// // pthread_t	thread2;
	// long		value1;
	// long		value2;

	// value1 = 6;
	// value2 = 16;
	// // pthread_create(&thread1, NULL, computation, (void *)&value1);
	// // pthread_create(&thread2, NULL, computation, (void *)&value2);
	// // pthread_join(thread1, NULL);
	// // pthread_join(thread2, NULL);

	// computation((void *) &value1);
	// computation((void *) &value2);

// ********** TEST 3 ************************

	pthread_t	thread0;
	pthread_create(&thread0, NULL, myturn, NULL);
	yourturn();

	return (0);
}

// void	*computation(void *add)
// {
// 	long	*add_num;
// 	long	sum;
	
// 	sum = 0;
// 	add_num = (long *)(add);
// 	for (long i = 0; i < 100000000; i++)
// 	{
// 		sum += *add_num;
// 	}
// 	// printf("Add: %ld\n", *add_num);
// 	return (NULL);
// }