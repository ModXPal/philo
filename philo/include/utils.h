/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcollas <rcollas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 16:33:27 by rcollas           #+#    #+#             */
/*   Updated: 2021/12/29 16:33:27 by rcollas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <unistd.h>
# include <sys/time.h>
# include "struct.h"

# define TRUE 1
# define FALSE 0
# define ERROR 1
# define SUCCESS 0

_Bool	is_digit(char c);
_Bool	is_not_numeric(char *str);
void	ft_putstr_fd(char *str, int fd);
void	ft_sleep(int milliseconds, t_var *var);
int		ft_atoi(const char *nptr);
size_t	str_len(const char *str);
void	*ft_calloc(size_t count, size_t size);

#endif
