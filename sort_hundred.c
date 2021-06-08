/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_hundred.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 16:39:51 by mlachheb          #+#    #+#             */
/*   Updated: 2021/06/08 19:45:29 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stacks.h"

t_stack	sort_hundred(t_stack a, char ***opers)
{
	t_stack b;

	if (!check_sort_as(a))
	{
		b = create_stack(a.size);
		a.items = replace_stack(a.items, a.top);
		push_fifty(&a, &b, opers, 0);
		sort_a_b(&a, &b, opers);
		push_fifty(&a, &b, opers, 50);
		printf("\n\n");
		print_stack(a);
		printf("\n\n");
		print_stack(b);
	}
	return (a);
}

void	push_fifty(t_stack *a, t_stack *b, char ***opers, int min)
{
	int		i;
	int		j;
	long	tmp;

	i = 0;
	while (i < 50)
	{
		j = 0;
		while (j <= a->top)
		{
			if (a->items[j] >= min && a->items[j] < min + 50)
			{
				bring_to_top(a, j, opers);
				p_a_b(a, b);
				*opers = ft_resize_opers(*opers, "pb");
				break ;
			}
			j++;
		}
		i++;
	}
}

void	sort_a_b(t_stack *a, t_stack *b, char ***opers)
{
	int	min;
	int	i;

	min = 0;
	while (b->top - 5 >= 0)
	{
		i = 0;
		bring_low_five(a, b, opers, min);
		sort_top_five(a, b, opers);
		while (i < 5)
		{
			*a = r_a_b(*a);
			*opers = ft_resize_opers(*opers, "ra");
			i++;
		}
		min += 5;
	}
	push_to_a(a, b, opers, &i);
	while (i > 0)
	{
		*a = r_a_b(*a);
		*opers = ft_resize_opers(*opers, "ra");
		i--;
	}
}

void	bring_low_five(t_stack *a, t_stack *b, char ***opers, long min)
{
	int		i;
	int		j;
	long	tmp;

	i = 0;
	while (i < 5)
	{
		j = 0;
		while (j <= b->top)
		{
			if (b->items[j] >= min && b->items[j] < min + 5)
			{
				bring_to_top(b, j, opers);
				tmp = peek(*b);
				pop(&(b->top));
				*a = push(tmp, *a);
				*opers = ft_resize_opers(*opers, "pa");
				break ;
			}
			j++;
		}
		i++;
	}
}
