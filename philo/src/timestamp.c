/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timestamp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcollas <rcollas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 16:32:38 by rcollas           #+#    #+#             */
/*   Updated: 2021/12/29 16:34:11 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "timestamp.h"

long	get_timestamp(struct timeval start)
{
	struct timeval	timestamp;
	long			interval;

	if (gettimeofday(&timestamp, NULL) == -1)
		error(GETTIMEOFDAY_ERROR);
	interval = (timestamp.tv_sec * 1000 - start.tv_sec * 1000)
		+ (timestamp.tv_usec / 1000 - start.tv_usec / 1000);
	return (interval);
}

void	get_starting_timestamp(t_var *var)
{
	if (gettimeofday(&var->start, NULL) == -1)
		error(GETTIMEOFDAY_ERROR);
}

long	elapsed_time(struct timeval start, struct timeval end)
{
	long	interval;

	interval = 0;
	interval += (end.tv_sec * 1000 - start.tv_sec * 1000);
	interval += (end.tv_usec / 1000 - start.tv_usec / 1000);
	return (interval);
}
