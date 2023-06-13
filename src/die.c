/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   die.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktunchar <ktunchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 01:49:02 by ktunchar          #+#    #+#             */
/*   Updated: 2023/06/13 15:57:53 by ktunchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	time_to_die(t_data *data, t_philo *philo)
{
	if (philo->last_eat_ms != 0 && ms_time_diff(philo->last_eat_ms) > (long)data->arg->t_die)
	{
		return (1);
	}
	return (0);
}

int	check_die(t_data *data)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (!data->die_flag && cnt != data->arg->n_philo)
	{
		if (time_to_die(data, &(data->philos[i])))
		{
			data->die_flag = 1;
			return (i);
		}
		if (!data->philos[i].done && data->arg->max_eat != -1 \
			&& data->philos[i].n_eat == data->arg->max_eat)
		{
			data->philos[i].done = 1;
			cnt++;
		}
		if (cnt == data->arg->n_philo)
			return (-1);
		usleep(50);
		i++;
		i %= data->arg->n_philo;
	}
	return (-1);
}
