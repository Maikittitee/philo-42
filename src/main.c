/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktunchar <ktunchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 04:36:14 by ktunchar          #+#    #+#             */
/*   Updated: 2023/06/06 23:26:21 by ktunchar         ###   ########.fr       */
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
	
	// gettimeofday(&t, NULL);
	// printf("tv sec :%ld\n", t.tv_sec);
	// printf("tv usec:%d\n", t.tv_usec);
	// usleep(1000000);
	// gettimeofday(&t, NULL);
	// printf("tv sec :%ld\n", t.tv_sec);
	// printf("tv usec:%d\n", t.tv_usec);
	
}
