/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktunchar <ktunchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 04:36:14 by ktunchar          #+#    #+#             */
/*   Updated: 2023/05/31 23:16:25 by ktunchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_data	*data;

	if (!check_arg(ac, av))
		exit(1);
	data = init_data(ac, av);
	print_data(*data);
	

	
}
