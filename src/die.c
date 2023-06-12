/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   die.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktunchar <ktunchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 01:49:02 by ktunchar          #+#    #+#             */
/*   Updated: 2023/06/13 03:39:25 by ktunchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	time_to_die(t_data *data, t_philo *philo)
{
	if (ms_time_diff(philo->last_eat_ms) > (long)data->arg->t_die)
	{
		printf("past:%lu\n",philo->last_eat_ms);
		return (1);
	}
	return (0);
}

int	check_die(t_data *data)
{
	int	i;

	i = 0;
	while (!data->die_flag)
	{
		if (time_to_die(data, &(data->philos[i])))
		{
			data->die_flag = 1;
			return (i);
		}
		if (data->arg->max_eat != -1 && data->philos[i].n_eat >= data->arg->max_eat)
		{
			// data->philos[i].done = 1;
			// cnt++;
			data->die_flag = 1;
			return (-1);
		}
		i += 2;
		if (i >= data->arg->n_philo && i % 2 == 0)
			i = 1;
		else if (i >= data->arg->n_philo && i % 2 != 0) 
			i = 0;
		usleep(10);
	}
	return (-1);
}
