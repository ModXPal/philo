/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timestamp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcollas <rcollas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 16:32:38 by rcollas           #+#    #+#             */
/*   Updated: 2022/01/09 17:57:49 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "timestamp.h"

long	get_timestamp(long start)
{
	long			timestamp;
	long			interval;

	timestamp = get_time();
	interval = timestamp - start;
	return (interval);
}

long	get_time(void)
{
	struct timeval	timestamp;
	long			time;

	if (gettimeofday(&timestamp, NULL) == -1)
		error(GETTIMEOFDAY_ERROR);
	time = timestamp.tv_sec * 1000 + timestamp.tv_usec / 1000;
	return (time);
}

long	elapsed_time(long start, long end)
{
	long	interval;

	interval = end - start;
	return (interval);
}
