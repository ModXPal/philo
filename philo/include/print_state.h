/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_state.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcollas <rcollas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 16:33:15 by rcollas           #+#    #+#             */
/*   Updated: 2021/12/29 16:34:11 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_STATE_H
# define PRINT_STATE_H

# include <pthread.h>
# include <stdio.h>
# include <sys/time.h>
# include "struct.h"
# include "timestamp.h"

# define FULL 0

void	print_philo_eating(t_philosopher *philosopher);
void	print_philo_sleeping(t_philosopher *philosopher);
void	print_philo_thinking(t_philosopher *philosopher);
void	print_philo_died(t_philosopher *philosopher);
void	print_philo_takes_fork(t_philosopher *philosopher);

#endif
