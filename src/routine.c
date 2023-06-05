/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktunchar <ktunchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 22:50:26 by ktunchar          #+#    #+#             */
/*   Updated: 2023/06/06 01:03:34 by ktunchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	take_fork(t_data *data, t_philo *philo)
{
	if (philo->status == DIED || pthread_mutex_lock(&(data->forks[philo->right])) != 0)
		return (0);
	//print take left hand fork
	printf(T_LTAKING, ms_from_start(data), philo->id);
	philo->n_fork += 1; // need to init n_fork = 0;
	if (philo->status == DIED || pthread_mutex_lock(&(data->forks[philo->left])) != 0)
		return (0);	
	//print take right hand fork
	printf(T_RTAKING, ms_from_start(data), philo->id);
	philo->n_fork += 1;
	return (1);
		
}



void	*routine(void *arg)
{
	// take_fork()
	t_data	*data;
	int		i;
	
	data = (t_data  *)arg;
	i = data->philo_id;
	data->philos[i].id = i + 1;
	data->philos[i].left = i;
	data->philos[i].right = (i + 1) % data->arg->n_philo;
	// printf("hello from philo index %d,i have %d %d\n", i, data->philos[i].left, data->philos[i].right);
	// check if 2 fork in the hands -> eat
	// if (philo->n_fork == 2)
	// 	ft_eat();
	// fork in only 1 hand -> unlock -> die 
	// unlock
	// if (max_eat = philo->n_eat): return (0);
	// sleep -> usleep
	// think -> usleep
	
	return (0);
}