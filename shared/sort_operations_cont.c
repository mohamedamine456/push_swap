/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_operations_cont.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 12:51:18 by mlachheb          #+#    #+#             */
/*   Updated: 2021/06/11 12:52:08 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"

t_stack	r_r_a_b(t_stack stack)
{
	long	tmp;
	long	tmp2;
	t_stack	tmp_stack;

	tmp_stack = create_stack(stack.size);
	while (!is_empty(stack.top))
	{
		tmp2 = peek(stack);
		pop(&(stack.top));
		tmp_stack = push(tmp2, tmp_stack);
	}
	tmp = peek(tmp_stack);
	pop(&(tmp_stack.top));
	while (!is_empty(tmp_stack.top))
	{
		tmp2 = peek(tmp_stack);
		pop(&(tmp_stack.top));
		stack = push(tmp2, stack);
	}
	stack = push(tmp, stack);
	free(tmp_stack.items);
	return (stack);
}

void	r_r_r(t_stack *a, t_stack *b)
{
	if (!is_empty(a->top))
		*a = r_r_a_b(*a);
	if (!is_empty(b->top))
		*b = r_r_a_b(*b);
}
