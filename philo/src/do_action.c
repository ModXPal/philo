/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_action.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcollas <rcollas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 16:31:28 by rcollas           #+#    #+#             */
/*   Updated: 2021/12/31 14:02:31 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "do_action.h"

#define STARVING 2

int	put_down_forks(t_var *var, t_philosopher *philosopher)
{
	if (philosopher->id % 2 == 0)
	{
		if (pthread_mutex_unlock(&var->forks[philosopher->left_fork]) != 0)
			error(MUTEX_UNLOCK_ERROR);
		if (pthread_mutex_unlock(&var->forks[philosopher->right_fork]) != 0)
			error(MUTEX_UNLOCK_ERROR);
	}
	else
	{
		if (pthread_mutex_unlock(&var->forks[philosopher->right_fork]) != 0)
			error(MUTEX_UNLOCK_ERROR);
		if (pthread_mutex_unlock(&var->forks[philosopher->left_fork]) != 0)
			error(MUTEX_UNLOCK_ERROR);
	}
	return (SUCCESS);
}

int	eat(t_var *var, t_philosopher *philosopher)
{
	pthread_mutex_lock(&philosopher->var->mutex_die);
	philosopher->state = EAT;
	if (philosopher->max_meal != -1)
		philosopher->meal_count++;
	pthread_mutex_unlock(&philosopher->var->mutex_die);
	print_philo_eating(philosopher);
	ft_sleep(var->time_to_eat, var);
	pthread_mutex_lock(&philosopher->var->mutex_die);
	pthread_mutex_lock(&philosopher->var->mutex_print);
	philosopher->state = FULL;
	pthread_mutex_unlock(&philosopher->var->mutex_print);
	pthread_mutex_unlock(&philosopher->var->mutex_die);
	return (SUCCESS);
}

int	go_sleep(t_var *var, t_philosopher *philosopher)
{
	print_philo_sleeping(philosopher);
	ft_sleep(var->time_to_sleep, var);
	return (SUCCESS);
}

int	is_thinking(t_philosopher *philosopher)
{
	print_philo_thinking(philosopher);
	return (SUCCESS);
}

int	take_forks(t_var *var, t_philosopher *philosopher)
{
	if (philosopher->id % 2 != 0 && philosopher->state == STARVING)
	{
		usleep(10);
		if (pthread_mutex_lock(&var->forks[philosopher->left_fork]) != 0)
			error(MUTEX_LOCK_ERROR);
		if (pthread_mutex_lock(&var->forks[philosopher->right_fork]) != 0)
			error(MUTEX_LOCK_ERROR);
	}
	else if (philosopher->state == STARVING)
	{
		if (pthread_mutex_lock(&var->forks[philosopher->right_fork]) != 0)
			error(MUTEX_LOCK_ERROR);
		if (pthread_mutex_lock(&var->forks[philosopher->left_fork]) != 0)
			error(MUTEX_LOCK_ERROR);
	}
	print_philo_takes_fork(philosopher);
	return (SUCCESS);
}
