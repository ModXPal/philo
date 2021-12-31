/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcollas <rcollas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 16:32:43 by rcollas           #+#    #+#             */
/*   Updated: 2021/12/29 16:34:11 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

size_t	str_len(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

void	ft_putstr_fd(char *str, int fd)
{
	write (fd, str, str_len(str));
}

_Bool	is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (TRUE);
	return (FALSE);
}

_Bool	is_not_numeric(char *str)
{
	size_t	i;

	i = -1;
	while (is_digit(str[++i]))
	{
		if (str[i + 1] == '\0')
			return (FALSE);
	}
	return (TRUE);
}

void	ft_sleep(int milliseconds, t_var *var)
{
	int		i;
	_Bool	philo_died;

	i = 100;
	pthread_mutex_lock(&var->mutex_die);
	philo_died = var->philo_died;
	pthread_mutex_unlock(&var->mutex_die);
	while (i < milliseconds && philo_died == FALSE)
	{
		pthread_mutex_lock(&var->mutex_die);
		philo_died = var->philo_died;
		pthread_mutex_unlock(&var->mutex_die);
		usleep(100 * 1000);
		i += 100;
	}
	if (philo_died == FALSE)
		usleep((milliseconds - (i - 100)) * 1000);
}
