/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcollas <rcollas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 16:32:06 by rcollas           #+#    #+#             */
/*   Updated: 2022/01/13 14:03:31 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	sit_at_table(void *functionPhilosopher)
{
	t_philosopher	*philosopher;
	t_var			*var;

	philosopher = functionPhilosopher;
	var = philosopher->var;
	while (is_philo_dead(var) == FALSE && var->number_of_philosophers > 0
		&& philosopher->meal_count < philosopher->max_meal)
	{
		if (is_philo_dead(var) == TRUE)
			break ;
		take_forks(var, philosopher);
		if (var->number_of_philosophers != 1)
			eat(var, philosopher);
		put_down_forks(var, philosopher);
		if (var->number_of_philosophers == 1)
			return (FAIL);
		if (is_philo_dead(var) == FALSE)
			go_sleep(var, philosopher);
		if (is_philo_dead(var) == FALSE)
			is_thinking(philosopher, var);
		if (is_philo_dead(var) == TRUE)
			break ;
	}
	return (SUCCESS);
}

int	run_thread(t_philosopher *philosophers, t_var *var)
{
	init_all_mutex(var);
	var->start = get_time();
	thread_create_philosopher(philosophers);
	handle_philos_death(philosophers, var);
	thread_join_philosopher(philosophers);
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
