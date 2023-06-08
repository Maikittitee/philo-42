/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philos_and_forks.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktunchar <ktunchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 15:34:48 by ktunchar          #+#    #+#             */
/*   Updated: 2023/06/08 22:20:51 by ktunchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	join_philos(t_arg *arg, t_philo *philos)
{
	int	i;

	i = 0;
	while (i < arg->n_philo)
	{
		pthread_join(((philos[i].th)), NULL);
		i++;
	}
}

static void	init_fork(t_arg *arg, t_data *data)
{
	int	i;

	i = 0;
	while (i < arg->n_philo)
	{
		pthread_mutex_init(&data->forks[i], NULL);
		i++;
	}
}	

void	create_philos_and_forks(t_arg *arg, t_data *data)
{
	int	i;

	i = 0;
	data->philos = malloc(sizeof(t_philo) * arg->n_philo);
	data->forks = malloc(sizeof(pthread_mutex_t) * arg->n_philo);
	if (!data->philos)
	{
		//free ((arg))
		perror("malloc failed.");
		exit(1);
	}
	init_fork(arg, data);
	while (i < arg->n_philo)
	{
		data->philo_id = i;
		pthread_create(&(data->philos[i].th), NULL, &routine, data);
		pthread_detach(data->philos[i].th);
		data->philos[i].start_ms = ms_from_epoch();
		data->philos[i].n_eat = 0;
		data->philos[i].n_fork = 0;
		usleep(50);
		i += 2;
		if (i >= arg->n_philo && i % 2 == 0)
			i = 1;
	}
	join_philos(arg, data->philos);
}
