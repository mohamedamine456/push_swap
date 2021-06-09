/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_hundred.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 16:39:51 by mlachheb          #+#    #+#             */
/*   Updated: 2021/06/09 11:42:35 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stacks.h"

t_stack	sort_hundred(t_stack a, char ***opers)
{
	t_stack b;
	int		min;

	min = 0;
	if (!check_sort_as(a))
	{
		b = create_stack(a.size);
		a.items = replace_stack(a.items, a.top);
		push_five_chunks(&a, &b, opers);
		push_to_a(&a, &b, opers);
	}
	free(b.items);
	return (a);
}

void	push_five_chunks(t_stack *a, t_stack *b, char ***opers)
{
	int	i;
	int	j;
	int	min;

	i = 0;
	min = 0;
	while (i < 100)
	{
		j = 0;
		while (j <= a->top)
		{
			if (a->items[j] >= min && a->items[j] < min + 20)
			{
				bring_to_top_a(a, j, opers);
				p_a_b(a, b);
				*opers = ft_resize_opers(*opers, "pb");
				break ;
			}
			j++;
		}
		if ((b->top + 1) % 20 == 0)
			min += 20;
		i++;
	}
}
