/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 14:06:44 by mlachheb          #+#    #+#             */
/*   Updated: 2021/06/08 19:45:31 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"

void   push_to_b(t_stack *a, t_stack *b, char ***opers, int size)
{
	long tmp;
	int	index;
	int i;

	while (i < size - 1 && a->top > size - 1)
	{
		index = minimum_index(a->items, a->top);
		bring_to_top(a, index, opers);
		p_a_b(a, b);
		*opers = ft_resize_opers(*opers, "pb");
		i++;
	}
}

void   push_to_a(t_stack *a, t_stack *b, char ***opers, int *nb)
{
	long tmp;
	int	index;
	
	*nb = 0;
	while (b->top >= 0)
	{
		index = maximum_index(b->items, b->top);
		bring_to_top(b, index, opers);
		p_a_b(b, a);
		*opers = ft_resize_opers(*opers, "pa");
		*nb += 1;
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
