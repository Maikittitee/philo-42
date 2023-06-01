/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktunchar <ktunchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 15:34:48 by ktunchar          #+#    #+#             */
/*   Updated: 2023/06/01 17:25:59 by ktunchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine()
{
	printf("hello\n");
	return (0);
}

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

t_philo	*create_philos(t_arg *arg)
{
	int	i;
	t_philo *philos;

	i = 0;
	philos = malloc(sizeof(t_philo));
	if (!philos)
	{
		//free ((arg))
		perror("malloc failed.");
		exit(1);
	}
	while (i++ < arg->n_philo)
		pthread_create(&(philos[i].th), NULL, &routine, NULL);
	join_philos(arg, philos);
	return (philos);
}
