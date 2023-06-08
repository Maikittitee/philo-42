/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktunchar <ktunchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 16:23:06 by ktunchar          #+#    #+#             */
/*   Updated: 2023/06/09 00:47:15 by ktunchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_data *ft_start(t_arg *arg)
{
	t_data *data;

	data = malloc(sizeof(t_data));
	if (!data)
	{
		//free ((arg))
		perror("malloc failed.");
		exit(1);
	}
	data->arg = arg;
	data->die_flag = 0;
	data->ms_start = ms_from_epoch();
	create_philos_and_forks(arg, data);
	
	
	return (data);
}