/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktunchar <ktunchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 04:36:14 by ktunchar          #+#    #+#             */
/*   Updated: 2023/06/01 17:49:25 by ktunchar         ###   ########.fr       */
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
	t_time t;
	t_arg	*arg;
	t_data	*data;

	if (!check_arg(ac, av))
		exit(1);
	arg = init_arg(ac, av);
	data = ft_start(arg);
	// gettimeofday(&t, NULL);
	// printf("tv sec :%ld\n", t.tv_sec);
	// printf("tv usec:%d\n", t.tv_usec);
	// usleep(1000000);
	// gettimeofday(&t, NULL);
	// printf("tv sec :%ld\n", t.tv_sec);
	// printf("tv usec:%d\n", t.tv_usec);
	
}
