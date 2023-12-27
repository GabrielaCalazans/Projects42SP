/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 15:36:13 by gacalaza          #+#    #+#             */
/*   Updated: 2023/12/27 15:52:14 by gacalaza         ###   ########.fr       */
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

int	x = 2;
int	mails = 0;

void	*routine()
{
	// printf(("Test from threads\n"));
	// sleep(3);
	// printf("Ending thread\n");
	for (int i = 0; i < 1000000; i++)
	{
		mails++;
	}

	return (NULL);
}

void	*routine1()
{
	// printf("Process id %d\n", getpid());
	x += 5;
	sleep(2);
	printf("Value of x: %d\n", x);
	return (NULL);
}

void	*routine2()
{
	sleep(2);
	printf("Value of x: %d\n", x);
	return (NULL);
}

long long	ft_get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
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

	// pthread_t	thread0;
	// pthread_create(&thread0, NULL, myturn, NULL);
	// yourturn();

// ************* TEST 4 CODE VALT **********************

	// pthread_t	t1, t2;

	// if (pthread_create(&t1, NULL, &routine, NULL) != 0)
	// 	return (1);
	// if (pthread_create(&t2, NULL, &routine, NULL) != 0)
	// 	return (2);
	// if (pthread_join(t1, NULL) != 0)
	// 	return (3);
	// if (pthread_join(t2, NULL) != 0)
	// 	return (4);

// ************* TEST 4 CODE VALT **********************

	// pthread_t	t1, t2;

	// if (pthread_create(&t1, NULL, &routine, NULL) != 0)
	// 	return (1);
	// if (pthread_create(&t2, NULL, &routine, NULL) != 0)
	// 	return (2);
	// if (pthread_join(t1, NULL) != 0)
	// 	return (3);
	// if (pthread_join(t2, NULL) != 0)
	// 	return (4);
	// printf("NUmber of mails: %d\n", mails);

// ************* TEST 5 gettimeofday **********************
	struct timeval	current_time;
	long 			seconds;
	long 			microseconds;

	gettimeofday(&current_time, NULL);
	seconds = current_time.tv_sec * 1000;
	microseconds = current_time.tv_usec / 1000;
	printf(" seconds: %ld\n microsecond: %ld\n sum: %ld\n", seconds, microseconds, seconds + microseconds);
	printf(" GET: %lld\n", ft_get_time());



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