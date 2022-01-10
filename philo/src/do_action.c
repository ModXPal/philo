/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_action.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcollas <rcollas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 16:31:28 by rcollas           #+#    #+#             */
/*   Updated: 2022/01/10 11:47:54 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "do_action.h"

#define STARVING 1

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
	pthread_mutex_lock(&philosopher->var->mutex_state);
	philosopher->state = EAT;
	pthread_mutex_unlock(&philosopher->var->mutex_state);
	pthread_mutex_lock(&philosopher->var->mutex_die);
	if (philosopher->max_meal != -1)
		philosopher->meal_count++;
	pthread_mutex_unlock(&philosopher->var->mutex_die);
	print_philo_eating(philosopher, var);
	pthread_mutex_lock(&var->mutex_die);
	philosopher->last_meal = get_time();
	pthread_mutex_unlock(&var->mutex_die);
	ft_sleep(var->time_to_eat, var);
	pthread_mutex_lock(&var->mutex_state);
	philosopher->state = FULL;
	pthread_mutex_unlock(&var->mutex_state);
	return (SUCCESS);
}

int	go_sleep(t_var *var, t_philosopher *philosopher)
{
	print_philo_sleeping(philosopher, var);
	ft_sleep(var->time_to_sleep, var);
	return (SUCCESS);
}

int	is_thinking(t_philosopher *philosopher, t_var *var)
{
	print_philo_thinking(philosopher, var);
	return (SUCCESS);
}

int	take_forks(t_var *var, t_philosopher *philosopher)
{
	if (philosopher->id % 2 != 0)
	{
		usleep(1000);
		if (pthread_mutex_lock(&var->forks[philosopher->left_fork]) != 0)
			error(MUTEX_LOCK_ERROR);
		if (pthread_mutex_lock(&var->forks[philosopher->right_fork]) != 0)
			error(MUTEX_LOCK_ERROR);
	}
	else
	{
		if (pthread_mutex_lock(&var->forks[philosopher->right_fork]) != 0)
			error(MUTEX_LOCK_ERROR);
		if (pthread_mutex_lock(&var->forks[philosopher->left_fork]) != 0)
			error(MUTEX_LOCK_ERROR);
	}
	print_philo_takes_fork(philosopher, var);
	return (SUCCESS);
}
