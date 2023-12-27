/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 18:20:01 by gacalaza          #+#    #+#             */
/*   Updated: 2023/12/27 18:45:58 by gacalaza         ###   ########.fr       */
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

typedef struct s_philo
{
	struct s_rout	*table;
	pthread_t		thread;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
	int				id;
	int				times_to_eat;
}				t_philo;

typedef struct s_rout
{
	t_philo			*philos;
	pthread_mutex_t	*forks;
	int				t_philos;
	int				death_time;
	int				eat_time;
	int				sleep_time;
	int				t_eat;
}			t_rout;

void		*routine(void *arg);
void		pick_up_forks(t_philo *philosopher);
void		put_down_forks(t_philo *philosopher);
long long	ft_get_time(void);
int			ft_set_values(t_rout *table, int argc, char *argv[]);
void		ft_init_philo(t_rout *table);
void		cleanup_table(t_rout *table);
void		ft_clean(t_rout *table);
int			ft_atoi(const char *nptr);
void		ft_putendl_fd(char *s, int fd);
void		print_message(int check, int philo_id);

#endif