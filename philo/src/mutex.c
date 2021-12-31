/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcollas <rcollas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 16:32:13 by rcollas           #+#    #+#             */
/*   Updated: 2021/12/29 16:34:11 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	mutex_init(pthread_mutex_t *mutex, int size)
{
	int	i;

	i = -1;
	while (++i < size)
	{
		if (pthread_mutex_init(&mutex[i], NULL) != 0)
			error(MUTEX_INIT_ERROR);
	}
	return (SUCCESS);
}

int	mutex_destroy(pthread_mutex_t *mutex, int size)
{
	int	i;

	i = -1;
	while (++i < size)
	{
		if (pthread_mutex_destroy(&mutex[i]) != 0)
			error(MUTEX_DESTROY_ERROR);
	}
	return (SUCCESS);
}

int	init_all_mutex(t_var *var)
{
	mutex_init(var->forks, var->number_of_philosophers);
	mutex_init(&var->mutex_die, 1);
	mutex_init(&var->mutex_print, 1);
	mutex_init(&var->mutex_max_eat, 1);
	return (SUCCESS);
}

int	destroy_all_mutex(t_var *var)
{
	mutex_destroy(var->forks, var->number_of_philosophers);
	mutex_destroy(&var->mutex_die, 1);
	mutex_destroy(&var->mutex_print, 1);
	mutex_destroy(&var->mutex_max_eat, 1);
	return (SUCCESS);
}
