/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_top_five.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 20:33:13 by mlachheb          #+#    #+#             */
/*   Updated: 2021/06/07 21:44:54 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"
#include "../stacks.h"

void	sort_top_five(t_stack *a, t_stack *b, char ***opers)
{
	char	**opers_a;
	char	**opers_b;
	int		i;
	long	tmp;

	i = 0;
	opers_a = NULL;
	opers_b = NULL;
	if (!check_top_five_sort(a->items, a->top))
	{
		push_to_b(a, b, opers, 3);
		*a = sort_three(*a, &opers_a);
		*b = sort_three_reversed(*b, &opers_b);
		replace_a_b(&opers_b);
		add_opers(opers, opers_a, opers_b);
		while (i < 2 && b->top >= 0)
		{
			tmp = peek(*b);
			pop(&(b->top));
			*a = push(tmp, *a);
			*opers = ft_resize_opers(*opers, "pa");
		}
	}
}

int		check_top_five_sort(long *tab, int top)
{
	int		i;
	int		size;
	long	tmp;

	i = top;
	if (top > 5)
		size = top - 5;
	else
		size = 0;
	tmp = tab[top];
	while (i > size)
	{
		if (tmp < tab[i])
			return (0);
		i--;
	}
	return (1);
}
