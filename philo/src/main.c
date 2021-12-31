/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcollas <rcollas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 16:32:06 by rcollas           #+#    #+#             */
/*   Updated: 2021/12/29 16:32:07 by rcollas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	sit_at_table(void *functionPhilosopher)
{
	t_philosopher	*philosopher;
	_Bool			philo_died;

	philo_died = FALSE;
	philosopher = functionPhilosopher;
	while (philo_died == FALSE && philosopher->var->number_of_philosophers > 1
		&& philosopher->meal_count < philosopher->max_meal)
	{
		if (is_philo_dead(philosopher->var, &philo_died) == TRUE)
			break ;
		take_forks(philosopher->var, philosopher);
		eat(philosopher->var, philosopher);
		put_down_forks(philosopher->var, philosopher);
		if (is_philo_dead(philosopher->var, &philo_died) == FALSE)
			go_sleep(philosopher->var, philosopher);
		if (is_philo_dead(philosopher->var, &philo_died) == FALSE)
			is_thinking(philosopher);
		if (is_philo_dead(philosopher->var, &philo_died) == TRUE)
			break ;
	}
	return (SUCCESS);
}

int	run_thread(t_philosopher *philosophers, t_var *var)
{
	init_all_mutex(var);
	get_starting_timestamp(var);
	thread_create_philosopher(philosophers);
	thread_create_monitor(philosophers);
	thread_join_philosopher(philosophers);
	thread_join_monitor(philosophers);
	destroy_all_mutex(var);
	return (SUCCESS);
}

int	main(int argc, char **argv)
{
	t_var	var[1];

	if (check_input(argc, argv) == ERROR)
		return (EXIT_FAILURE);
	if (init_table(var, argv) == CALLOC_ERROR)
		return (EXIT_FAILURE);
	run_thread(var->philosopher, var);
	ft_free(var->philosopher);
	ft_free(var->forks);
	return (EXIT_SUCCESS);
}
