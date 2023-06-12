/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philos_and_forks.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktunchar <ktunchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 15:34:48 by ktunchar          #+#    #+#             */
/*   Updated: 2023/06/13 04:53:23 by ktunchar         ###   ########.fr       */
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

static void	init_fork(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->arg->n_philo)
	{
		pthread_mutex_init(&data->forks[i], NULL);
		i++;
	}
}	

static void	init_philo(t_data *data)
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

int	create_philos_and_forks(t_data *data)
{
	int	i;

	i = 0;
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
	init_philo(data);
	join_philos(data->arg, data->philos);
	return (1);
}
