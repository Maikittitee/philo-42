/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktunchar <ktunchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 04:36:14 by ktunchar          #+#    #+#             */
/*   Updated: 2023/06/09 00:47:09 by ktunchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


// long	now(void)
// {
// 	timeval	time;

// 	gettimeofday(&time, NULL);
// 	return (time.tv_sec * 1000 + time.tv_usec / 1000);
// }

int	main(int ac, char **av)
{
	t_arg	*arg;
	t_data	*data;
	int	i;
	int	die;

	if (!check_arg(ac, av))
		exit(1);
	arg = init_arg(ac, av);
	data = ft_start(arg);
	i = 0;
	while (i < data->arg->n_philo)
	{
		pthread_mutex_destroy(&data->forks[i]);
		i++;
	}
	die = check_die(data);
	printf(T_DIED, ms_from_start(data) , die + 1);
		
}
