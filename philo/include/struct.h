/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcollas <rcollas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 16:33:19 by rcollas           #+#    #+#             */
/*   Updated: 2021/12/29 16:33:19 by rcollas          ###   ########.fr       */
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
	int						philo_died;
	int						max_meal;
	struct timeval			start;
	struct s_philosopher	*philosopher;
	pthread_mutex_t			*forks;
	pthread_mutex_t			mutex_die;
	pthread_mutex_t			mutex_print;
	pthread_mutex_t			mutex_max_eat;
}				t_var;

typedef struct s_philosopher {
	int			id;
	int			right_fork;
	int			left_fork;
	int			state;
	int			max_meal;
	int			meal_count;
	pthread_t	philosopher;
	pthread_t	monitor;
	t_var		*var;
}				t_philosopher;

#endif
