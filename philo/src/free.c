/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcollas <rcollas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 16:31:39 by rcollas           #+#    #+#             */
/*   Updated: 2021/12/29 16:34:11 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free.h"

void	ft_free(void *to_free)
{
	if (to_free)
	{
		free (to_free);
		to_free = NULL;
	}
}

void	free_int_tab(int **tab, int size)
{
	int	i;

	i = -1;
	while (++i < size)
	{
		free (tab[i]);
	}
}
