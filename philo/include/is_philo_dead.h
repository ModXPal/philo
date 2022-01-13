/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_philo_dead.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcollas <rcollas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 16:33:05 by rcollas           #+#    #+#             */
/*   Updated: 2022/01/12 16:32:11 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IS_PHILO_DEAD_H
# define IS_PHILO_DEAD_H

# include <sys/time.h>
# include "struct.h"
# include "timestamp.h"
# include "print_state.h"

# define TRUE 1
# define FALSE 0
# define EAT 3
# define FULL 0
# define SUCCESS 0
# define FAIL 1

_Bool	is_philo_dead(t_var *var);
void	refresh_timestamp(t_philosopher *philosopher, int state_to_check);
void	is_philo_alive(t_philosopher *philosopher, t_var *var,
			long timestamp, long end);
int		handle_philos_death(t_philosopher *philosopher, t_var *var);
int		get_philo_state(t_var *var, t_philosopher *philosopher);
_Bool	is_philo_starving(t_var *var, t_philosopher *philosopher);

#endif
