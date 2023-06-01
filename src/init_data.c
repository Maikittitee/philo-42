/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktunchar <ktunchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 22:45:19 by ktunchar          #+#    #+#             */
/*   Updated: 2023/06/01 16:59:43 by ktunchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_arg	*init_arg(int ac, char **av)
{
	t_arg	*arg_data;
	int		i;

	i = 0;
	arg_data = malloc(sizeof(t_arg));
	if (!arg_data)
	{
		perror("malloc failed.");
		exit(255);
	}
	arg_data->ac = ac;
	arg_data->n_philo = ft_atoi(av[1]);
	arg_data->t_die = ft_atoi(av[2]);
	arg_data->t_eat = ft_atoi(av[3]);
	arg_data->t_sleep = ft_atoi(av[4]);
	if (ac == 6)
		arg_data->max_eat = ft_atoi(av[5]);
	return (arg_data);
}