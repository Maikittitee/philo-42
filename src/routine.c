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
void	ft_eat(t_data *data)
{
	long init_time;

	init_time = ms_from_epoch();
	while (ms_from_epoch() - init_time < data->arg->t_eat && data->philos[data->philo_id].status != DIED)
		usleep(50);
	
}

void ft_sleep_and_think(t_data *data)
{

}

void	ft_die(t_data *data)
{

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
	printf("hello from philo index %d,i have %d %d\n", i, data->philos[i].left, data->philos[i].right);
	take_fork(data, &(data->philos[i]));
	// check if 2 fork in the hands -> eat
	if (data->philos[i].n_fork == 2)
		ft_eat(data);
	// fork in only 1 hand -> unlock -> die 
	// unlock
	// if (max_eat = philo->n_eat): return (0);
	// sleep -> usleep
	// think -> usleep
	
	return (0);
}