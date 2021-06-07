/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 16:48:36 by mlachheb          #+#    #+#             */
/*   Updated: 2021/06/07 19:32:22 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"

long	*replace_stack(long *tab, int top)
{
	int		i;
	long	min;
	int		imin;
	long	*new_tab;

	i = 0;
	new_tab = (long *)malloc(sizeof(long) * top + 1);
	min = INT_MIN;
	while(i <= top)
	{
		imin = index_item(tab, top, min);
		min = tab[imin];
		tab[imin] = INT_MAX;
		new_tab[imin] = i;
		i++;
	}
	free(tab);
	return (new_tab);
}

int	index_item(long *tab, int top, long min)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = i;
	while (i <= top)
	{
		if (tab[i] < tab[tmp] && tab[i] > min)
			tmp = i;
		i++;
	}
	return (tmp);
}
