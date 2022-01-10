/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_philo_dead.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcollas <rcollas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 16:32:01 by rcollas           #+#    #+#             */
/*   Updated: 2022/01/10 12:29:05 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "is_philo_dead.h"
#include "philosophers.h"

int	get_philo_state(t_var *var, t_philosopher *philosopher, int *philo_state)
{
	pthread_mutex_lock(&var->mutex_state);
	*philo_state = philosopher->state;
	pthread_mutex_unlock(&var->mutex_state);
	return (*philo_state);
}

_Bool	is_philo_dead(t_var *var)
{
	_Bool	died;

	pthread_mutex_lock(&var->mutex_die);
	died = var->philo_died;
	pthread_mutex_unlock(&var->mutex_die);
	if (died == TRUE)
		return (TRUE);
	return (FALSE);
}

void	is_philo_alive(t_philosopher *philosopher, t_var *var,
		long timestamp, long end)
{
	long int		timestamp_result;

	timestamp_result = elapsed_time(timestamp, end);
	pthread_mutex_lock(&var->mutex_die);
	if (var->philo_died == FALSE
		&& timestamp_result > var->time_to_die)
	{
		var->philo_died = TRUE;
		print_philo_died(philosopher, var);
	}
	pthread_mutex_unlock(&var->mutex_die);
}

_Bool	max_meal_reach(t_philosopher *philosopher, t_var *var)
{
	_Bool	max_reach;

	max_reach = FALSE;
	pthread_mutex_lock(&var->mutex_die);
	if (philosopher->meal_count >= philosopher->max_meal)
		max_reach = TRUE;
	pthread_mutex_unlock(&var->mutex_die);
	return (max_reach);
}

int	handle_philos_death(t_philosopher *philosopher, t_var *var)
{
	long	end;
	int		i;

	i = -1;
	while (++i < var->number_of_philosophers)
	{
		pthread_mutex_lock(&var->mutex_die);
		philosopher[i].last_meal = get_time();
		pthread_mutex_unlock(&var->mutex_die);
	}
	i = 0;
	while (var->philo_died == FALSE
		&& max_meal_reach(&philosopher[i], var) == FALSE)
	{
		end = get_time();
		is_philo_dead(var);
		is_philo_alive(&philosopher[i], var, philosopher[i].last_meal, end);
		i++;
		if (i == var->number_of_philosophers)
			i = 0;
		usleep(100);
	}
	return (SUCCESS);
}
