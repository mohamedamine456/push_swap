/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 14:06:44 by mlachheb          #+#    #+#             */
/*   Updated: 2021/06/10 18:48:26 by mlachheb         ###   ########.fr       */
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
		index = maximum_index(b->items, b->top);
		bring_to_top_b(b, index, opers);
		p_a_b(b, a);
		*opers = ft_resize_opers(*opers, "pa");	
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
