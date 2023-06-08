/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktunchar <ktunchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 17:53:19 by ktunchar          #+#    #+#             */
/*   Updated: 2023/06/08 17:52:28 by ktunchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	ms_from_epoch(void)
{
	t_time t;
	
	gettimeofday(&t, NULL);
	return (t.tv_sec * 1000 + t.tv_usec / 1000);
	
}

long	ms_time_diff(long past)
{
	t_time t;
	
	gettimeofday(&t, NULL);
	return ((t.tv_sec * 1000 + t.tv_usec / 1000 ) - past);
	
}

long	ms_from_start(t_data *data)
{
	// t_time t;
	
	// gettimeofday(&t, NULL);
	// return ((t.tv_sec * 1000 + t.tv_usec / 1000 ) - data->ms_start);
	return (ms_time_diff(data->ms_start));
	
}
