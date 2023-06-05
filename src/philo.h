/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktunchar <ktunchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 04:32:52 by ktunchar          #+#    #+#             */
/*   Updated: 2023/06/06 00:57:33 by ktunchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "../lib/libft/libft.h"
# include "../lib/libftprintf/ft_printf.h"
# include <pthread.h>
# include <unistd.h>
#include <sys/time.h>

typedef	struct timeval t_time;

typedef struct s_arg{
	int	ac;
	int	n_philo;
	int	t_die;
	int	t_eat;
	int	t_sleep;
	int	max_eat;	
}t_arg;

typedef struct s_philo{
	pthread_t th;
	int	id;
	int	status;
	int	left;
	int	right;
	int	n_fork;
	
}t_philo;

typedef struct s_data{
	int				philo_id;
	long			ms_start;
	t_philo 		*philos;
	pthread_mutex_t *forks;
	t_arg			*arg;
	
}t_data;

#define DIED 0
#define EATING 1
#define THINKING 2
#define SLEEPING 3
#define	T_DIED "%ld philo%d Died\n"
#define	T_LTAKING "%ld philo%d is taking left fork\n"
#define	T_RTAKING "%ld philo%d is taking right fork\n"
#define	T_EATING "%ld philo%d is Eating\n"
#define	T_THINKING "%ld philo%d is Thinking\n"
#define	T_SLEEPING "%ld philo%d is Sleeping\n"
// error
int		check_arg(int ac, char **av);

// get_data_from_arg && starting
t_arg	*init_arg(int ac, char **av);
t_data *ft_start(t_arg *arg);
void	create_philos_and_forks(t_arg *arg, t_data *data);

// debugging
void	print_arg_data(t_arg *arg);

// routine
void    *routine();

// time
long	ms_from_epoch(void);
long	ms_from_start(t_data *data);

#endif