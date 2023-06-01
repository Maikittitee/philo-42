/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktunchar <ktunchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 04:36:14 by ktunchar          #+#    #+#             */
/*   Updated: 2023/06/01 16:59:50 by ktunchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_arg	*arg;
	t_data	*data;

	if (!check_arg(ac, av))
		exit(1);
	arg = init_arg(ac, av);
	data = ft_start(arg);
	// ft_printf("%ld hello2\n",t);
}
