/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktunchar <ktunchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 03:38:47 by ktunchar          #+#    #+#             */
/*   Updated: 2023/06/09 03:45:59 by ktunchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_philo(t_data *data)
{
	if (data->arg)
		free(data->arg);
	if (data->philos)
		free(data->philos);
	if (data->forks)
		free(data->forks);
	free(data);
	
}