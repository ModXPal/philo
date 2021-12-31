/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcollas <rcollas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 16:32:32 by rcollas           #+#    #+#             */
/*   Updated: 2021/12/29 16:34:11 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	thread_create_philosopher(t_philosopher *philosophers)
{
	int	i;

	i = -1;
	while (++i < philosophers->var->number_of_philosophers)
	{
		if (pthread_create(&(philosophers[i]).philosopher, NULL,
				(void *) sit_at_table, (void *) &philosophers[i]) != 0)
			return (error(PTHREAD_CREATE_ERROR));
	}
	return (SUCCESS);
}

int	thread_create_monitor(t_philosopher *philosophers)
{
	int	i;

	i = -1;
	while (++i < philosophers->var->number_of_philosophers)
	{
		if (pthread_create(&(philosophers[i]).monitor, NULL,
				(void *) handle_philos_death, (void *) &philosophers[i]) != 0)
			return (error(PTHREAD_CREATE_ERROR));
	}
	return (SUCCESS);
}

int	thread_join_philosopher(t_philosopher *philosophers)
{
	int	i;

	i = -1;
	while (++i < philosophers->var->number_of_philosophers)
	{
		if (pthread_join(philosophers[i].philosopher, NULL) != 0)
			return (error(PTHREAD_JOIN_ERROR));
	}
	return (SUCCESS);
}

int	thread_join_monitor(t_philosopher *philosophers)
{
	int	i;

	i = -1;
	while (++i < philosophers->var->number_of_philosophers)
	{
		if (pthread_join(philosophers[i].monitor, NULL) != 0)
			return (error(PTHREAD_JOIN_ERROR));
	}
	return (SUCCESS);
}
