/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcollas <rcollas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 16:31:19 by rcollas           #+#    #+#             */
/*   Updated: 2021/12/29 16:34:11 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	check_args_numbers(int argc)
{
	if (argc < 5 || argc > 6)
	{
		ft_putstr_fd("Please check the number of arguments.\n", STDERR_FILENO);
		return (ERROR);
	}
	return (0);
}

int	check_args_type(char **argv)
{
	size_t	i;

	i = 1;
	while (argv[i])
	{
		if (is_not_numeric(argv[i]) || ft_atoi(argv[i]) == -1)
		{
			ft_putstr_fd("Please check that ", STDERR_FILENO);
			ft_putstr_fd("all parameters are positive ints.\n", STDERR_FILENO);
			return (ERROR);
		}
		i++;
	}
	return (0);
}

int	check_philos_number(char **argv)
{
	if (ft_atoi(argv[1]) == 0)
	{
		ft_putstr_fd("There should be at least\n", STDERR_FILENO);
		ft_putstr_fd(" one philosopher.\n", STDERR_FILENO);
		return (ERROR);
	}
	return (0);
}

int	check_input(int argc, char **argv)
{
	if (check_args_numbers(argc) == ERROR)
		return (ERROR);
	if (check_args_type(argv) == ERROR)
		return (ERROR);
	if (check_philos_number(argv) == ERROR)
		return (ERROR);
	return (0);
}
