/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_state.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcollas <rcollas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 16:32:27 by rcollas           #+#    #+#             */
/*   Updated: 2022/01/09 18:30:02 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_state.h"

void	print_philo_eating(t_philosopher *philosopher, t_var *var)
{
	long int	timestamp;

	if (is_philo_dead(var) == FALSE)
	{
		pthread_mutex_lock(&var->mutex_print);
		timestamp = get_timestamp(var->start);
		printf("%ld", timestamp - (timestamp % 10));
		printf(" %d is eating\n", philosopher->id + 1);
		pthread_mutex_unlock(&var->mutex_print);
	}
}

void	print_philo_sleeping(t_philosopher *philosopher, t_var *var)
{
	long int	timestamp;

	if (is_philo_dead(var) == FALSE)
	{
		pthread_mutex_lock(&var->mutex_print);
		timestamp = get_timestamp(var->start);
		printf("%ld", timestamp - (timestamp % 10));
		printf(" %d is sleeping\n", philosopher->id + 1);
		pthread_mutex_unlock(&var->mutex_print);
	}
}

void	print_philo_thinking(t_philosopher *philosopher, t_var *var)
{
	long int	timestamp;
	int			philo_state;

	get_philo_state(var, &var->philosopher[philosopher->id + 1], &philo_state);
	if (is_philo_dead(var) == FALSE && philo_state != FULL)
	{
		pthread_mutex_lock(&var->mutex_print);
		timestamp = get_timestamp(var->start);
		printf("%ld", timestamp - (timestamp % 10));
		printf(" %d is thinking\n", philosopher->id + 1);
		pthread_mutex_unlock(&var->mutex_print);
	}
}

void	print_philo_died(t_philosopher *philosopher, t_var *var)
{
	long int	timestamp;

	pthread_mutex_lock(&var->mutex_print);
	timestamp = get_timestamp(var->start);
	if (philosopher->meal_count < philosopher->max_meal)
	{
		printf("%ld", timestamp - (timestamp % 10));
		printf(" %d died\n", philosopher->id + 1);
	}
	pthread_mutex_unlock(&var->mutex_print);
}

void	print_philo_takes_fork(t_philosopher *philosopher, t_var *var)
{
	long int	timestamp;

	if (is_philo_dead(var) == FALSE)
	{
		pthread_mutex_lock(&var->mutex_print);
		timestamp = get_timestamp(var->start);
		printf("%ld", timestamp - (timestamp % 10));
		printf(" %d has taken a fork\n", philosopher->id + 1);
		pthread_mutex_unlock(&var->mutex_print);
	}
}
