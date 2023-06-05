/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philos_and_forks.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktunchar <ktunchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 15:34:48 by ktunchar          #+#    #+#             */
/*   Updated: 2023/06/06 01:02:38 by ktunchar         ###   ########.fr       */
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
	while (i < arg->n_philo)
	{
		data->philo_id = i;
		pthread_create(&(data->philos[i].th), NULL, &routine, data);
		usleep(50);
		i++;
	}
	join_philos(arg, data->philos);
}
