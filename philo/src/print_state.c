/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_state.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcollas <rcollas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 16:32:27 by rcollas           #+#    #+#             */
/*   Updated: 2021/12/29 16:34:11 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_state.h"

void	print_philo_eating(t_philosopher *philosopher)
{
	long int	timestamp;

	pthread_mutex_lock(&philosopher->var->mutex_print);
	if (philosopher->var->philo_died == FALSE)
	{
		timestamp = get_timestamp(philosopher->var->start);
		printf("%ld", timestamp - (timestamp % 10));
		printf(" %d is eating\n", philosopher->id + 1);
	}
	pthread_mutex_unlock(&philosopher->var->mutex_print);
}

void	print_philo_sleeping(t_philosopher *philosopher)
{
	long int	timestamp;

	pthread_mutex_lock(&philosopher->var->mutex_print);
	if (philosopher->var->philo_died == FALSE)
	{
		timestamp = get_timestamp(philosopher->var->start);
		printf("%ld", timestamp - (timestamp % 10));
		printf(" %d is sleeping\n", philosopher->id + 1);
	}
	pthread_mutex_unlock(&philosopher->var->mutex_print);
}

void	print_philo_thinking(t_philosopher *philosopher)
{
	long int	timestamp;

	pthread_mutex_lock(&philosopher->var->mutex_print);
	if (philosopher->var->philo_died == FALSE
		&& philosopher->var->philosopher[philosopher->id + 1].state != FULL)
	{
		timestamp = get_timestamp(philosopher->var->start);
		printf("%ld", timestamp - (timestamp % 10));
		printf(" %d is thinking\n", philosopher->id + 1);
	}
	pthread_mutex_unlock(&philosopher->var->mutex_print);
}

void	print_philo_died(t_philosopher *philosopher)
{
	long int	timestamp;

	pthread_mutex_lock(&philosopher->var->mutex_print);
	timestamp = get_timestamp(philosopher->var->start);
	if (philosopher->meal_count < philosopher->max_meal)
	{
		printf("%ld", timestamp - (timestamp % 10));
		printf(" %d died\n", philosopher->id + 1);
	}
	pthread_mutex_unlock(&philosopher->var->mutex_print);
}

void	print_philo_takes_fork(t_philosopher *philosopher)
{
	long int	timestamp;

	pthread_mutex_lock(&philosopher->var->mutex_print);
	if (philosopher->var->philo_died == FALSE)
	{
		timestamp = get_timestamp(philosopher->var->start);
		printf("%ld", timestamp - (timestamp % 10));
		printf(" %d has taken a fork\n", philosopher->id + 1);
	}
	pthread_mutex_unlock(&philosopher->var->mutex_print);
}
