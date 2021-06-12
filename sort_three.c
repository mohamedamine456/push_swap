/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 14:00:50 by mlachheb          #+#    #+#             */
/*   Updated: 2021/06/12 13:00:13 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stacks.h"

t_stack	sort_three(t_stack a, char ***opers)
{
	if (!check_sort_as(a))
	{
		if (a.size == 2)
		{
			*opers = ft_resize_opers(*opers, "sa");
			a = s_a_b(a);
		}
		else
		{
			if (a.items[a.top] > a.items[a.top - 1]
				&& a.items[a.top] > a.items[a.top - 2])
			{
				*opers = ft_resize_opers(*opers, "ra");
				a = r_a_b(a);
				if (a.items[a.top] > a.items[a.top - 1])
				{
					*opers = ft_resize_opers(*opers, "sa");
					a = s_a_b(a);
				}
			}
			else
				sort_three_helper(&a, opers);
		}
	}
	return (a);
}

void	sort_three_helper(t_stack *a, char ***opers)
{
	if (a->items[a->top] > a->items[a->top - 1]
		&& a->items[a->top] < a->items[a->top - 2])
	{
		*opers = ft_resize_opers(*opers, "sa");
		*a = s_a_b(*a);
	}
	else if (a->items[a->top] < a->items[a->top - 1]
		&& a->items[a->top] > a->items[a->top - 2])
	{
		*opers = ft_resize_opers(*opers, "rra");
		*a = r_r_a_b(*a);
	}
	else
	{
		*opers = ft_resize_opers(*opers, "sa");
		*opers = ft_resize_opers(*opers, "ra");
		*a = s_a_b(*a);
		*a = r_a_b(*a);
	}
}

t_stack	sort_three_reversed(t_stack a, char ***opers)
{
	if (!check_sort_ds(a))
	{
		if (a.size == 2)
		{
			*opers = ft_resize_opers(*opers, "sa");
			a = s_a_b(a);
		}
		else
		{
			if (a.items[a.top] < a.items[a.top - 1]
				&& a.items[a.top] < a.items[a.top - 2])
			{
				*opers = ft_resize_opers(*opers, "ra");
				a = r_a_b(a);
				if (a.items[a.top] < a.items[a.top - 1])
				{
					*opers = ft_resize_opers(*opers, "sa");
					a = s_a_b(a);
				}
			}
			else
				sort_three_reversed_helper(&a, opers);
		}
	}
	return (a);
}

void	sort_three_reversed_helper(t_stack *a, char ***opers)
{
	if (a->items[a->top] < a->items[a->top - 1]
		&& a->items[a->top] > a->items[a->top - 2])
	{
		*opers = ft_resize_opers(*opers, "sa");
		*a = s_a_b(*a);
	}
	else if (a->items[a->top] > a->items[a->top - 1]
		&& a->items[a->top] < a->items[a->top - 2])
	{
		*opers = ft_resize_opers(*opers, "rra");
		*a = r_r_a_b(*a);
	}
	else
	{
		*opers = ft_resize_opers(*opers, "sa");
		*opers = ft_resize_opers(*opers, "ra");
		*a = s_a_b(*a);
		*a = r_a_b(*a);
	}
}
