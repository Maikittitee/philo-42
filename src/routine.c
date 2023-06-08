/* ************************************************************************* */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktunchar <ktunchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 22:50:26 by ktunchar          #+#    #+#             */
/*   Updated: 2023/06/06 13:06:58 by ktunchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	put_fork_down(t_data *data, t_philo *philo)
{
	if (data->die_flag || pthread_mutex_unlock(&(data->forks[philo->right])) != 0)
		return (0);
	philo->n_fork -= 1; // need to init n_fork = 0;
	if (data->die_flag || pthread_mutex_unlock(&(data->forks[philo->left])) != 0)
		return (0);	
	philo->n_fork -= 1;
	return (1);
}

int	take_fork(t_data *data, t_philo *philo)
{
	if (data->die_flag || pthread_mutex_lock(&data->forks[philo->right]) != 0)
		return (0);
	//print take left hand fork
	printf(T_RTAKING, ms_from_start(data), philo->id);
	philo->n_fork += 1; // need to init n_fork = 0;
	if (data->die_flag || pthread_mutex_lock(&data->forks[philo->left]) != 0)
		return (0);	
	//print take right hand fork
	printf(T_LTAKING, ms_from_start(data), philo->id);
	philo->n_fork += 1;
	return (1);
		
}

int	ft_eat(t_data *data, t_philo *philo)
{
	long init_time;

	init_time = ms_from_epoch();
	printf(T_EATING, ms_from_start(data), philo->id);
	while (!data->die_flag && ms_time_diff(init_time) < data->arg->t_eat)
		usleep(50);
	return (data->die_flag);
}

int ft_sleep(t_data *data, t_philo *philo)
{
	long init_time;

	init_time = ms_from_epoch();
	printf(T_SLEEPING, ms_time_diff(data->ms_start) , philo->id);
	while (!data->die_flag && ms_time_diff(init_time) < data->arg->t_sleep)
		usleep(50);
	return (data->die_flag);
}

void	*routine(void *arg)
{
	t_data	*data;
	int		i;
	
	data = (t_data  *)arg;
	i = data->philo_id;
	data->philos[i].id = i + 1;
	data->philos[i].left = i;
	data->philos[i].right = (i + 1) % data->arg->n_philo;
	data->philos[i].last_eat_ms = data->philos[i].start_ms; 
	while (!data->die_flag)
	{
		take_fork(data, &(data->philos[i]));
		data->philos[i].last_eat_ms = ms_from_epoch();
		if (ft_eat(data, &(data->philos[i])))
			return (0);
		data->philos[i].n_eat ++;	
		put_fork_down(data, &(data->philos[i]));
		if (ft_sleep(data, &(data->philos[i])))
			return (0);
		printf(T_THINKING, ms_from_start(data), data->philos[i].id);
	}
	return (0);
}
