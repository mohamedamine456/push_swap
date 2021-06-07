/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 14:06:44 by mlachheb          #+#    #+#             */
/*   Updated: 2021/06/07 18:06:47 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"

void   push_to_b(t_stack *a, t_stack *b, char ***opers, int size)
{
	long tmp;
	int	index;

	while (a->top > size - 1)
	{
		index = minimum_index(a->items, a->top);
		bring_to_top(a, index, opers);
		tmp = peek(*a);
		pop(&(a->top));
		*b = push(tmp, *b);
		*opers = ft_resize_opers(*opers, "pb");
	}
}

void	bring_to_top(t_stack *a, int index, char ***opers)
{
	if (index >= a->top / 2)
	{
		while (index < a->top)
		{
			*a = r_a_b(*a);
			*opers = ft_resize_opers(*opers, "ra");
			index++;
		}
	}
	else
	{
		while (index >= 0)
		{
			*a = r_r_a_b(*a);
			*opers = ft_resize_opers(*opers, "rra");
			index--;
		}
	}
}

int	minimum_index(long *tab, int top)
{
	int i;
	int tmp;

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
	int i;
	int tmp;

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
