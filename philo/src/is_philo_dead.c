/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_philo_dead.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcollas <rcollas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 16:32:01 by rcollas           #+#    #+#             */
/*   Updated: 2021/12/31 12:14:27 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "is_philo_dead.h"
#include "philosophers.h"

_Bool	is_philo_dead(t_var *var, _Bool *philo_died)
{
	pthread_mutex_lock(&var->mutex_die);
	*philo_died = var->philo_died;
	pthread_mutex_unlock(&var->mutex_die);
	if (*philo_died == TRUE)
		return (TRUE);
	return (FALSE);
}

void	refresh_timestamp(t_philosopher *philosopher, struct timeval *timestamp, int state_to_check)
{
	if (state_to_check == EAT)
	{
		pthread_mutex_lock(&philosopher->var->mutex_die);
		if (philosopher->state == EAT)
		{
			gettimeofday(timestamp, NULL);
			//philosopher->state = full;
		}
		pthread_mutex_unlock(&philosopher->var->mutex_die);
	}
	else if (state_to_check == STARVING)
	{
		pthread_mutex_lock(&philosopher->var->mutex_die);
		if (philosopher->state == FULL)
		{
			gettimeofday(timestamp, NULL);
			//philosopher->state = full;
		}
		pthread_mutex_unlock(&philosopher->var->mutex_die);
	}
}

void	is_philo_alive(t_philosopher *philosopher, t_var *var,
		struct timeval timestamp, struct timeval end)
{
	long int	timestamp_result;
	long int	starving_timestamp_result;
	struct timeval	starving_timestamp;

	refresh_timestamp(philosopher, &starving_timestamp, STARVING);
	pthread_mutex_lock(&var->mutex_die);
	timestamp_result = elapsed_time(timestamp, end);
	starving_timestamp_result = elapsed_time(starving_timestamp, end);
	if (var->philo_died == FALSE
		&& timestamp_result > var->time_to_die + 2)
	{
		philosopher->var->philo_died = TRUE;
		print_philo_died(philosopher);
	}
	else if (starving_timestamp_result > var->time_to_eat + 10)
		philosopher->state = STARVING;
	pthread_mutex_unlock(&philosopher->var->mutex_die);
}

int	handle_philos_death(t_philosopher *philosopher)
{
	struct timeval	timestamp;
	struct timeval	end;
	_Bool			philo_died;
	t_var			*var;

	var = philosopher->var;
	philo_died = FALSE;
	gettimeofday(&timestamp, NULL);
	while (philo_died == FALSE
		&& philosopher->meal_count < philosopher->max_meal)
	{
		gettimeofday(&end, NULL);
		is_philo_dead(var, &philo_died);
		refresh_timestamp(philosopher, &timestamp, EAT);
		is_philo_alive(philosopher, var, timestamp, end);
		usleep(500);
	}
	return (SUCCESS);
}
