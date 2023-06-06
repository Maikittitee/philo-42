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
	if (data->die_flag || pthread_mutex_lock(&data->forks[philo->right]) != 0)
	{
		return (0);
	}
	//print take left hand fork
	printf(T_LTAKING, ms_from_start(data), philo->id);
	philo->n_fork += 1; // need to init n_fork = 0;
	if (data->die_flag || pthread_mutex_lock(&data->forks[philo->left]) != 0)
		return (0);	
	//print take right hand fork
	printf(T_RTAKING, ms_from_start(data), philo->id);
	philo->n_fork += 1;
	return (1);
		
}
void	ft_eat(t_data *data, t_philo *philo)
{
	long init_time;

	philo->status = EATING;
	init_time = ms_from_epoch();
	printf(T_EATING, ms_from_start(data), philo->id);
	while (philo->n_fork == 2 && !data->die_flag && ms_from_epoch() - init_time < data->arg->t_eat)
		usleep(50);
	
}

void ft_sleep(t_data *data, t_philo *philo)
{
	long init_time;

	philo->status = SLEEPING;
	if (data->die_flag)
		return ;
	init_time = ms_from_epoch();
	printf(T_SLEEPING, ms_from_start(data), philo->id);
	while (!data->die_flag && ms_from_epoch() - init_time < data->arg->t_sleep)
		usleep(50);
}

void ft_think(t_data *data, t_philo *philo)
{
	long init_time;

	philo->status = SLEEPING;
	if (data->die_flag)
		return ;
	init_time = ms_from_epoch();
	printf(T_THINKING, ms_from_start(data), philo->id);
	while (!data->die_flag && ms_from_epoch() - init_time < data->arg->t_sleep)
		usleep(50);
}



void	ft_die(t_data *data, t_philo *philo)
{
	// time to die , max eat
	if (data->die_flag)
		return ;
	if (ms_from_start(data) > data->arg->t_die || philo->n_eat == data->arg->max_eat)
	{
		printf(T_DIED, ms_from_start(data), philo->id);
		data->die_flag = 1;
	}
}

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
	while (!data->die_flag)
	{
		take_fork(data, &(data->philos[i]));
		// check if 2 fork in the hands -> eat
		// if (data->philos[i].n_fork == 2)
		ft_eat(data, &(data->philos[i]));
		put_fork_down(data, &(data->philos[i]));
		ft_sleep(data, &(data->philos[i]));
		ft_think(data, &(data->philos[i]));
		ft_die(data, &(data->philos[i]));
	}
	return (0);
}