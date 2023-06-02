/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktunchar <ktunchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 23:02:42 by ktunchar          #+#    #+#             */
/*   Updated: 2023/06/02 14:05:24 by ktunchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_arg_data(t_arg *arg_data)
{
	printf("number of philo: %d\n", arg_data->n_philo);
	printf("time to die: %d\n", arg_data->t_die);
	printf("time to eat: %d\n", arg_data->t_eat);
	printf("time to sleep:%d\n", arg_data->t_sleep);
	if (arg_data->ac == 6)
		printf("max number of eating:%d\n", arg_data->max_eat);
}
