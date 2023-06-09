/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktunchar <ktunchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 23:02:42 by ktunchar          #+#    #+#             */
/*   Updated: 2023/06/09 22:20:05 by ktunchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_arg_data(t_arg *arg_data)
{
	printf("number of philo: %d\n", arg_data->n_philo);
	printf("time to die: %ld\n", arg_data->t_die);
	printf("time to eat: %ld\n", arg_data->t_eat);
	printf("time to sleep:%ld\n", arg_data->t_sleep);
	if (arg_data->ac == 6)
		printf("max number of eating:%d\n", arg_data->max_eat);
}
