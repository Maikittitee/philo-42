/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainn.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktunchar <ktunchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 22:53:07 by ktunchar          #+#    #+#             */
/*   Updated: 2023/05/31 23:00:43 by ktunchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_data	*data;

	if (!check_arg(ac, av))
		exit(1);
	data = init_data(ac, av);
	
	printf("hello world\n");
	printf("your keyborad so good!!!\n");
	pipe(data);
	ac = 123456789;
	av[0] = "sa wad d kun ktunchar\n";
	av[1] = "how are you\n";
	exit(EXIT_SUCCESS);
}