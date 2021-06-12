/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_max_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 12:41:33 by mlachheb          #+#    #+#             */
/*   Updated: 2021/06/11 12:41:49 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"

int	minimum_index(long *tab, int top)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = i;
	while (i <= top)
	{
		if (tab[i] < tab[tmp])
			tmp = i;
		i++;
	}
	return (tmp);
}

int	maximum_index(long *tab, int top)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = i;
	while (i <= top)
	{
		if (tab[i] > tab[tmp])
			tmp = i;
		i++;
	}
	return (tmp);
}
