/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktunchar <ktunchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 16:23:06 by ktunchar          #+#    #+#             */
/*   Updated: 2023/06/13 05:12:10 by ktunchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_data	*ft_start(int ac, char **av)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->arg = init_arg(ac, av);
	if (!data->arg)
	{
		free(data);
		return (NULL);
	}
	data->die_flag = 0;
	data->ms_start = ms_from_epoch();
	if (!create_philos_and_forks(data))
		return (NULL);
	return (data);
}
