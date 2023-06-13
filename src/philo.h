/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktunchar <ktunchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 04:32:52 by ktunchar          #+#    #+#             */
/*   Updated: 2023/06/14 00:31:40 by ktunchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "../lib/libft/libft.h"
# include <pthread.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/time.h>
# include <limits.h>

# define T_DIED "\e[0;31m%ldms philo%d Died\e[0m\n"
# define T_LTAKING "%ldms philo%d is taking left fork\n"
# define T_RTAKING "%ldms philo%d is taking right fork\n"
# define T_EATING "%ldms philo%d is Eating\n"
# define T_THINKING "%ldms philo%d is Thinking\n"
# define T_SLEEPING "%ldms philo%d is Sleeping\n"

typedef struct timeval	t_time;

typedef struct s_arg{
	long long	n_philo;
	long long	t_die;
	long long	t_eat;
	long long	t_sleep;
	long long	max_eat;	
}t_arg;

typedef struct s_philo{
	pthread_t	th;
	int			id;
	int			left;
	int			right;
	int			n_eat;
	int			done;
	long		last_eat_ms;
	long		start_ms;	
}	t_philo;

typedef struct s_data{
	int				philo_id;
	long			ms_start;
	t_philo			*philos;
	pthread_mutex_t	*forks;
	t_arg			*arg;
	int				die_flag;	
}	t_data;

// error
int		check_arg(int ac, char **av);

// get_data_from_arg && starting
t_arg	*init_arg(int ac, char **av);
t_data	*ft_start(int ac, char **av);
int		create_philos_and_forks(t_data *data);

// routine
void	*routine(void *arg);

// time
long	ms_from_epoch(void);
long	ms_from_start(t_data *data);
long	ms_time_diff(long past);
int		check_die(t_data *data);
void	free_philo(t_data *data);
void	free_arg(t_data *data);

#endif