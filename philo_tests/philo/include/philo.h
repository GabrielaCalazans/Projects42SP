/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 18:20:01 by gacalaza          #+#    #+#             */
/*   Updated: 2024/01/22 13:29:03 by gacalaza         ###   ########.fr       */
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
# define DEAD		5
# define DEFAULT	7
# define S_SUCESS	0
# define EERROR		1
# define STAY		1
# define GO			0

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
	struct s_table	*table;
	int				status;
	pthread_t		thread;
	long long		last_meal;
	int				id;
	int				times_to_eat;
}				t_philo;

typedef struct s_table
{
	t_philo			*philos;
	pthread_t		waiter;
	int				n_philos;
	int				death_time;
	int				eat_time;
	int				sleep_time;
	int				should_i;
	long long		start_time;
	int				n_eat;
	pthread_mutex_t	mut_status;
	pthread_mutex_t	mut_meal;
	pthread_mutex_t	mut_tteat;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print;
	pthread_mutex_t	mut_time;
	pthread_mutex_t	mut_should_i;
}				t_table;

void		*routine(void *arg);
void		*thanatos(void *arg);
void		pick_up_forks(t_philo *philosopher);
void		put_down_forks(t_philo *philosopher);
void		ft_upstatus(t_philo *philosopher, int status);
int			ft_getstatus(t_philo *philosopher);
long long	ft_get_time(void);
int			ft_gettteat(t_philo *philo);
long long	ft_time(t_table *table, long long now);
void		ft_usleep(int time);
int			ft_spleep(t_philo *philosopher);
long long	ft_getsleep(t_table *table, int type);
void		ft_uplastmeal(t_philo *philosopher);
int			ft_set_values(t_table *table, int argc, char *argv[]);
int			ft_init_philo(t_table *table);
int			ft_init_thread(t_table *table);
void		cleanup_table(t_table *table);
void		ft_clean(t_table *table);
int			ft_atoi(const char *nptr);
int			ft_isdigit(int argument);
void		ft_putendl_fd(char *s, int fd);
void		print_message(int check, t_philo *philosopher, long long time);
int			ft_error(char *error, t_table *table);
int			ft_eat(t_philo *philosopher);
int			ft_think(t_philo *philosopher);

void		ft_upshould_i(t_table	*table, int stay_or_go);
int			ft_should_i(t_table	*table);
long long	ft_getlastmeal(t_philo *philosopher);

#endif