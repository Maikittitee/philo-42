/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktunchar <ktunchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 22:45:19 by ktunchar          #+#    #+#             */
/*   Updated: 2023/06/11 02:22:40 by ktunchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long ft_atol(const char *str)
{
	long long		result;
	int				i;

	i = 0;
	result = 0;
	while (str[i])
	{
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	return (result);
}

int		is_limit(t_arg *arg)
{
	if (arg->n_philo > 200 || arg->n_philo < 1)
		return (1);
	if (arg->t_die > INT_MAX || arg->t_die < 1)
		return (1);
	if (arg->t_eat > INT_MAX || arg->t_eat < 1)
		return (1);
	if (arg->t_sleep > INT_MAX || arg->t_sleep < 1)
		return (1);	
	if (arg->max_eat > INT_MAX || (arg->max_eat != -1 && arg->max_eat < 1))
		return (1);
	return(0);	
	
}

t_arg	*init_arg(int ac, char **av)
{
	t_arg	*arg_data;

	arg_data = malloc(sizeof(t_arg));
	if (!arg_data)
		return (NULL);
	arg_data->n_philo = ft_atol(av[1]);
	arg_data->t_die = ft_atol(av[2]);
	arg_data->t_eat = ft_atol(av[3]);
	arg_data->t_sleep = ft_atol(av[4]);
	if (ac == 6)
		arg_data->max_eat = ft_atoi(av[5]);
	else
		arg_data->max_eat = -1;
	if (is_limit(arg_data))
	{
		free(arg_data);
		return (NULL);
	}
	return (arg_data);
}

