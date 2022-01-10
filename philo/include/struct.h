/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcollas <rcollas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 16:33:19 by rcollas           #+#    #+#             */
/*   Updated: 2022/01/09 18:26:59 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include <pthread.h>

typedef struct s_var {
	int						number_of_philosophers;
	int						number_of_forks;
	int						time_to_die;
	int						time_to_eat;
	int						time_to_sleep;
	_Bool					philo_died;
	int						max_meal;
	long					start;
	struct s_philosopher	*philosopher;
	pthread_mutex_t			*forks;
	pthread_mutex_t			mutex_die;
	pthread_mutex_t			mutex_print;
	pthread_mutex_t			mutex_max_eat;
	pthread_mutex_t			mutex_state;
}				t_var;

typedef struct s_philosopher {
	int			id;
	int			state;
	int			left_fork;
	int			right_fork;
	int			max_meal;
	int			meal_count;
	long		last_meal;
	_Bool		has_forks;
	pthread_t	philosopher;
	pthread_t	monitor;
	t_var		*var;
}				t_philosopher;

#endif
