/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   die.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktunchar <ktunchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 01:49:02 by ktunchar          #+#    #+#             */
/*   Updated: 2023/06/08 03:09:36 by ktunchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	time_to_die(t_data *data, t_philo *philo)
{
	if (ms_from_start(data) - philo->last_eat_ms >= data->arg->t_die)
		return (1);
	return (0);
}

int	check_die(t_data  *data)
{
	int	i;

	i = 0;
	while (i < data->arg->n_philo)
	{
		if (time_to_die(data, &(data->philos[i])) || \
			data->philos[i].n_eat >= data->arg->max_eat)
			{
				data->die_flag = 1;
				return (1);
			}
		i++;
		i %= data->arg->n_philo; 
	}
	return (0);
}