/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktunchar <ktunchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 04:36:14 by ktunchar          #+#    #+#             */
/*   Updated: 2023/06/09 23:01:21 by ktunchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_data	*data;
	int	die;
	int	i;

	i = 0;
	if (!check_arg(ac, av))
		return(EXIT_FAILURE);
	data = ft_start(ac ,av);
	if (!data)
		return (EXIT_FAILURE);
	while (i < data->arg->n_philo)
		pthread_mutex_destroy(&data->forks[i++]);
	die = check_die(data);
	if (die != -1)
		printf(T_DIED, ms_from_start(data) , die + 1);
	free_philo(data);
	free_arg(data);
}
