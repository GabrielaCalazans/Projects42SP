/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 18:20:01 by gacalaza          #+#    #+#             */
/*   Updated: 2023/12/21 19:57:20 by gacalaza         ###   ########.fr       */
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


typedef struct s_philo
{
	int				number;
	pthread_t		thread;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	int				times_to_eat;
}				t_philo;

typedef struct s_rout
{
	t_philo			*philosophers;
	pthread_mutex_t	*forks;
	int				num_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_times_each_philo_must_eat;
}			t_rout;


void		*philosopher_routine(void *arg);
void		pick_up_forks(t_philo *philosopher);
void		put_down_forks(t_philo *philosopher);
long long	get_timestamp_ms(void);
void		ft_set_values(t_rout *table, int argc, char *argv[]);
void		ft_init_philo(t_rout *table);
void		cleanup_table(t_rout *table);
int			ft_atoi(const char *nptr);

#endif