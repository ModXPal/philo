/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_action.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcollas <rcollas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 16:32:51 by rcollas           #+#    #+#             */
/*   Updated: 2021/12/31 11:43:08 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DO_ACTION_H
# define DO_ACTION_H

# include <pthread.h>
# include <sys/time.h>
# include "struct.h"
# include "error.h"
# include "utils.h"
# include "print_state.h"

# define EAT 3

int	put_down_forks(t_var *var, t_philosopher *philosopher);
int	eat(t_var *var, t_philosopher *philosopher);
int	go_sleep(t_var *var, t_philosopher *philosopher);
int	is_thinking(t_philosopher *philosopher);
int	take_forks(t_var *var, t_philosopher *philosopher);

#endif
