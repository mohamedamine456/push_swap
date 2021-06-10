/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 14:06:44 by mlachheb          #+#    #+#             */
/*   Updated: 2021/06/10 11:45:50 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"
#include "../stacks.h"

void   push_to_b(t_stack *a, t_stack *b, char ***opers, int size)
{
	int	index;
	int i;

	i = 0;
	while (i < size && a->top > size - 1)
	{
		index = minimum_index(a->items, a->top);
		bring_to_top_a(a, index, opers);
		p_a_b(a, b);
		*opers = ft_resize_opers(*opers, "pb");
		i++;
	}
}

void   push_to_a(t_stack *a, t_stack *b, char ***opers)
{
	int	index;
	
	while (b->top >= 0)
	{
		index = minimum_index(b->items, b->top);
		bring_to_top_b(b, index, opers);
		p_a_b(b, a);
		*opers = ft_resize_opers(*opers, "pa");
		if (a->top > 0)
		{
			*a = r_a_b(*a);
			*opers = ft_resize_opers(*opers, "ra");
		}
	}
}

void	bring_to_top_a(t_stack *a, int index, char ***opers)
{
	long	tmp;

	tmp = a->items[index];
	if (index >= a->top / 2)
	{
		while (tmp != peek(*a))
		{
			*a = r_a_b(*a);
			*opers = ft_resize_opers(*opers, "ra");
			index++;
		}
	}
	else
	{
		while (tmp != peek(*a))
		{
			*a = r_r_a_b(*a);
			*opers = ft_resize_opers(*opers, "rra");
			index--;
		}
	}
}

void	bring_to_top_b(t_stack *a, int index, char ***opers)
{
	long	tmp;

	tmp = a->items[index];
	if (index >= a->top / 2)
	{
		while (tmp != peek(*a))
		{
			*a = r_a_b(*a);
			*opers = ft_resize_opers(*opers, "rb");
			index++;
		}
	}
	else
	{
		while (tmp != peek(*a))
		{
			*a = r_r_a_b(*a);
			*opers = ft_resize_opers(*opers, "rrb");
			index--;
		}
	}
}
