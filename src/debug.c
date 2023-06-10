/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktunchar <ktunchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 23:02:42 by ktunchar          #+#    #+#             */
/*   Updated: 2023/06/11 02:23:45 by ktunchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_arg_data(t_arg *arg_data)
{
	printf("number of philo: %lld\n", arg_data->n_philo);
	printf("time to die: %lld\n", arg_data->t_die);
	printf("time to eat: %lld\n", arg_data->t_eat);
	printf("time to sleep:%lld\n", arg_data->t_sleep);
	printf("max number of eating:%lld\n", arg_data->max_eat);
}
