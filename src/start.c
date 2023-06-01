/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktunchar <ktunchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 16:23:06 by ktunchar          #+#    #+#             */
/*   Updated: 2023/06/01 17:53:09 by ktunchar         ###   ########.fr       */
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
	data->ms_start = ms_from_epoch();
	data->philos = create_philos(arg);
	
	
	return (data);
}