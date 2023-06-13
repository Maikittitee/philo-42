/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philos_and_forks.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktunchar <ktunchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 15:34:48 by ktunchar          #+#    #+#             */
/*   Updated: 2023/06/14 00:30:47 by ktunchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	start_fork(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->arg->n_philo)
	{
		pthread_mutex_init(&data->forks[i], NULL);
		i++;
	}
}	

static void	start_philo(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->arg->n_philo)
	{
		data->philo_id = i;
		data->philos[i].start_ms = ms_from_epoch();
		pthread_create(&(data->philos[i].th), NULL, &routine, data);
		pthread_detach(data->philos[i].th);
		usleep(50);
		i += 2;
		if (i >= data->arg->n_philo && i % 2 == 0)
			i = 1;
	}
}

static void	init_fork(t_data *data)
{
	int	i;

	i = 0;
	while (i < (int)data->arg->n_philo)
	{
		data->philos[i].id = i + 1;
		data->philos[i].left = i;
		data->philos[i].right = (i + 1) % data->arg->n_philo;
		data->philos[i].n_eat = 0;
		data->philos[i].done = 0;
		i ++;
	}
}

int	create_philos_and_forks(t_data *data)
{
	data->philos = malloc(sizeof(t_philo) * data->arg->n_philo);
	if (!data->philos)
	{
		free_arg(data);
		perror("malloc philo failed.");
		return (0);
	}
	data->forks = malloc(sizeof(pthread_mutex_t) * data->arg->n_philo);
	if (!data->forks)
	{
		free(data->philos);
		free_arg(data);
		perror("malloc forks failed.");
		return (0);
	}
	init_fork(data);
	start_fork(data);
	start_philo(data);
	return (1);
}
