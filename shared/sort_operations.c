/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 09:27:22 by mlachheb          #+#    #+#             */
/*   Updated: 2021/05/18 14:35:17 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"

/**
 * Function from the subject
 * s_a_b : swap the last two elements in stack (a or b)
 * s_s : swap the last two elements in stack (a and b)
 * p_a_b : push element to (a or b)
 * r_a_b : shift up elements of stack (a or b) by 1. the first elements become the last one.
 * r_r : shift up elements of stack (a and b) by 1. the first elements become the last one.
 * r_r_a_b : shift down elements of stack (a or b) by 1. the last elements become the first one.
 * r_r_r : shift down elements of stack (a and b) by 1. the last elements become the first one.
 */

t_stack	s_a_b(t_stack stack)
{
	long	temp1;
	long	temp2;

	if (stack.top > 0)
	{
		temp1 = peek(stack);
		pop(&stack.top);
		temp2 = peek(stack);
		pop(&stack.top);
		stack = push(temp1, stack);
		stack = push(temp2, stack);
	}
	return (stack);
}

void    s_s(t_stack *a, t_stack *b)
{
	*a = s_a_b(*a);
	*b = s_a_b(*b);
}

void    p_a_b(t_stack *a, t_stack *b)
{
	long	temp;

	if (!is_empty(a->top))
	{
		temp = peek(*a);
		pop(&(a->top));
		*b = push(temp, *b);
	}
}


t_stack	r_a_b(t_stack stack)
{
	long	tmp;
	long	tmp2;
	t_stack tmp_stack;

	tmp_stack = create_stack(stack.size);
	tmp = peek(stack);
	pop(&(stack.top));
	while (!is_empty(stack.top))
	{
		tmp2 = peek(stack);
		pop(&(stack.top));
		tmp_stack = push(tmp2, tmp_stack);
	}
	stack = push(tmp, stack);
	while (!is_empty(tmp_stack.top))
	{
		tmp2 = peek(tmp_stack);
		pop(&(tmp_stack.top));
		stack = push(tmp2, stack);
	}
	free(tmp_stack.items);
	return (stack);
}

void    r_r(t_stack *a, t_stack *b)
{
	if (!is_empty(a->top))
		*a = r_a_b(*a);
	if (!is_empty(b->top))
		*b = r_a_b(*b);
}

t_stack	r_r_a_b(t_stack stack)
{
	long	tmp;
	long	tmp2;
	t_stack tmp_stack;
	
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

void    r_r_r(t_stack *a, t_stack *b)
{
	if (!is_empty(a->top))
		*a = r_r_a_b(*a);
	if (!is_empty(b->top))
		*b = r_r_a_b(*b);
}
