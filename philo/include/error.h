/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcollas <rcollas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 16:32:56 by rcollas           #+#    #+#             */
/*   Updated: 2021/12/29 16:34:11 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# define TRUE 1
# define FALSE 0
# define ERROR 1
# define SUCCESS 0

# define PTHREAD_CREATE_ERROR -1
# define PTHREAD_JOIN_ERROR -2
# define MUTEX_INIT_ERROR -3
# define MUTEX_DESTROY_ERROR -4
# define MUTEX_LOCK_ERROR -5
# define MUTEX_UNLOCK_ERROR -6
# define CALLOC_ERROR -7
# define GETTIMEOFDAY_ERROR -8

int	error(int errnum);
int	mutex_init_error(void);
int	mutex_destroy_error(void);
int	mutex_lock_error(void);
int	mutex_unlock_error(void);

#endif
