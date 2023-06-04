/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktunchar <ktunchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 22:50:26 by ktunchar          #+#    #+#             */
/*   Updated: 2023/06/04 23:04:37 by ktunchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	take_fork(t_data *data, t_philo *philo)
{
	if (philo->status == DIED || pthread_mutex_lock(&(data->forks[philo->right])) != 0)
		return (0);
	//print take right hand fork
	if (philo->status == DIED || pthread_mutex_lock(&(data->forks[philo->left])) != 0)
		return (0);	
	//print take right hand fork
	return (1);
		
}


void	*routine()
{
	// take_fork()
	// check if 2 fork in the hands -> eat
	// fork in only 1 hand -> unlock -> die 
	// unlock
	// if (max_eat = philo->n_eat): return (0);
	// sleep -> usleep
	// think -> usleep
	
	
	return (0);
}