/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcollas <rcollas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 16:33:10 by rcollas           #+#    #+#             */
/*   Updated: 2021/12/29 16:33:11 by rcollas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include "free.h"
# include "is_philo_dead.h"
# include "do_action.h"

# define TRUE 1
# define FALSE 0
# define SUCCESS 0
# define FAIL 1
# define ERROR 1
# define AVAILABLE 1
# define EAT 3
# define SLEEPING 2
# define STARVING 1
# define FULL 0

int		init_table(t_var *var, char **argv);
int		check_args_numbers(int argc);
int		check_args_type(char **argv);
int		check_input(int argc, char **argv);
int		thread_create_philosopher(t_philosopher *philosophers);
int		thread_create_monitor(t_philosopher *philosophers);
int		thread_join_philosopher(t_philosopher *philosophers);
int		thread_join_monitor(t_philosopher *philosophers);
int		mutex_init(pthread_mutex_t *mutex, int size);
int		mutex_destroy(pthread_mutex_t *mutex, int size);
int		init_all_mutex(t_var *var);
int		sit_at_table(void *functionVar);
int		destroy_all_mutex(t_var *var);

#endif
