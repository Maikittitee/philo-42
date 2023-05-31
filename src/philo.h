/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktunchar <ktunchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 04:32:52 by ktunchar          #+#    #+#             */
/*   Updated: 2023/05/31 23:15:30 by ktunchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "lib/libft/libft.h"
# include "lib/libftprintf/ft_printf.h"
# include <pthread.h>
# include <unistd.h>

typedef struct s_data{
	int	ac;
	int	n_philo;
	int	t_die;
	int	t_eat;
	int	t_sleep;
	int	max_eat;	
}t_data;

// error
int		check_arg(int ac, char **av);

// get_data_from_arg
t_data	*init_data(int ac, char **av);

// debugging
void	print_data(t_data data)


#endif