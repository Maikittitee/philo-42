/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktunchar <ktunchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 04:47:44 by ktunchar          #+#    #+#             */
/*   Updated: 2023/05/29 04:53:13 by ktunchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


static int	is_str_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	check_arg(int ac, char **av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (!is_str_digit(av[i]))
			return (0);
		i++;
	}
	return (1);
}