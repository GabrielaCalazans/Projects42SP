/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 18:20:01 by gacalaza          #+#    #+#             */
/*   Updated: 2024/01/17 18:53:29 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

# define FORK		3
# define THINKING	0
# define SLEEPING	4
# define EATING		1
# define DIED		5
# define S_SUCESS	0
# define EERROR		1

//	alloc_err
# define A_ERR_0	"ERROR WHILE ALLOCATING PHILOS, FORKS and THREADS"
# define A_ERR_1	"ERROR WHILE ALLOCATING THREADS"
# define A_ERR_2	"ERROR WHILE ALLOCATING FORKS"
# define M_ERR_0	"ERROR WHILE INITIALIZING MUTEX"
//	input_err
# define ERR_IN_1	"INVALID INPUT CHARACTER"
# define ERR_IN_2	"Invalid input value"
//	pthread_err
# define TH_ERR		"ERROR WHILE CREATING THREADS"
# define JOIN_ERR	"ERROR WHILE JOINING THREADS"
# define INIT_ERR_1	"ERROR WHILE INIT FORKS"
//	time_err
# define TIME_FUNC	"gettimeofday() FAILURE\n"

typedef struct s_philo
{
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	mut_status;
	pthread_mutex_t	mut_meal;
	struct s_table	*table;
	pthread_t		thread;
	long long		last_meal;
	int				id;
	int				times_to_eat;
}				t_philo;

typedef struct s_table
{
	t_philo			*philos;
	t_philo			waiter;
	int				n_philos;
	int				death_time;
	int				eat_time;
	int				sleep_time;
	int				status;
	long long		start_time;
	int				n_eat;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print;
}				t_table;

void		*routine(void *arg);
void		*tend(void *arg);
void		pick_up_forks(t_philo *philosopher);
void		put_down_forks(t_philo *philosopher);
void		ft_upstatus(t_philo *philosopher, int status);
long long	ft_get_time(void);
long long	ft_time(t_table *table);
void		ft_usleep(int time);
void		ft_spleep(t_philo *philosopher);
int			ft_set_values(t_table *table, int argc, char *argv[]);
int			ft_init_philo(t_table *table);
int			ft_init_thread(t_table *table);
void		cleanup_table(t_table *table);
void		ft_clean(t_table *table);
int			ft_atoi(const char *nptr);
int			ft_isdigit(int argument);
void		ft_putendl_fd(char *s, int fd);
void		print_message(int check, t_philo *philosopher);
int			ft_error(char *error, t_table *table);

#endif