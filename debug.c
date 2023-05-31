/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktunchar <ktunchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 23:02:42 by ktunchar          #+#    #+#             */
/*   Updated: 2023/05/31 23:16:04 by ktunchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_data(t_data data)
{
	ft_printf("the number of philo: %d\n", data.n_philo);
	ft_printf("time to die: %d\n", data.t_die);
	ft_printf("time to eat: %d\n", data.t_eat);
	ft_printf("time to sleep:%d\n", data.t_sleep);
	if (data.ac == 6)
		ft_printf("max number of eating:%d\n", data.max_eat);
		
}
