/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ps_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 12:12:51 by mlachheb          #+#    #+#             */
/*   Updated: 2021/04/28 12:39:06 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stacks.h"

t_stack	check_sa(t_stack stack, char ***operations)
{
	long	tmp;
	long	tmp2;

	tmp = peek(stack);
	pop(&(stack.top));
	tmp2 = peek(stack);
	pop(&(stack.top));
	if (tmp > tmp2)
	{
		*operations = ft_resize_opers(*operations, ft_strdup("sa"));
		stack = push(tmp, stack);
		stack = push(tmp2, stack);
		return (stack);
	}
	stack = push(tmp2, stack);
	stack = push(tmp, stack);
	return (stack);
}

t_stack	check_ra(t_stack stack, char ***operations)
{
	long	tmp;

	tmp = peek(stack);
	if (tmp > stack.first)
	{
		*operations = ft_resize_opers(*operations, ft_strdup("ra"));
		stack = r_a_b(stack);
	}
	return (stack);
}

t_stack	check_rra(t_stack stack, char ***operations)
{
	long	tmp;

	tmp = peek(stack);
	if (tmp > stack.first)
	{
		*operations = ft_resize_opers(*operations, ft_strdup("rra"));
		stack = r_r_a_b(stack);
	}
	return (stack);
}

void	move_b_a(t_stack *stack_a, t_stack *stack_b, char ***operations)
{
	long	tmp;

	while (!is_empty(stack_b->top))
	{
		*operations = ft_resize_opers(*operations, ft_strdup("pa"));
		tmp = peek(*stack_b);
		pop(&(stack_b->top));
		*stack_a = push(tmp, *stack_a);
	}
}
