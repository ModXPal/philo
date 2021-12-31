/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcollas <rcollas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 16:31:56 by rcollas           #+#    #+#             */
/*   Updated: 2021/12/29 16:31:57 by rcollas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	init_philosophers(t_var *var)
{
	t_philosopher	*philosopher;
	int				i;

	i = -1;
	philosopher = (t_philosopher *)ft_calloc(sizeof(t_philosopher),
			var->number_of_philosophers);
	if (!philosopher)
		return (error(CALLOC_ERROR));
	while (++i < var->number_of_philosophers)
	{
		philosopher[i].var = var;
		philosopher[i].id = i;
		philosopher[i].right_fork = i;
		philosopher[i].left_fork = (i + 1) % var->number_of_philosophers;
		philosopher[i].state = STARVING;
		philosopher[i].max_meal = var->max_meal;
		if (var->max_meal != -1)
			philosopher[i].meal_count = 0;
		else
			philosopher[i].meal_count = -2;
	}
	var->philosopher = philosopher;
	return (SUCCESS);
}

int	init_table(t_var *var, char **argv)
{
	var->number_of_philosophers = ft_atoi(argv[1]);
	var->philo_died = FALSE;
	var->number_of_forks = var->number_of_philosophers;
	var->time_to_die = ft_atoi(argv[2]);
	var->time_to_eat = ft_atoi(argv[3]);
	var->time_to_sleep = ft_atoi(argv[4]);
	var->max_meal = -1;
	if (argv[5])
		var->max_meal = ft_atoi(argv[5]);
	var->forks = (pthread_mutex_t *)ft_calloc(sizeof(pthread_mutex_t),
			var->number_of_forks);
	if (!var->forks)
		return (error(CALLOC_ERROR));
	if (init_philosophers(var) == CALLOC_ERROR)
		return (CALLOC_ERROR);
	return (SUCCESS);
}
