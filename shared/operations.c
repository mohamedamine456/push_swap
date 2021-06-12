/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 09:26:53 by mlachheb          #+#    #+#             */
/*   Updated: 2021/06/11 12:43:38 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"

/**
 * Function test if the stack is empty
 */

int	is_empty(int top)
{
	if (top == -1)
		return (1);
	else
		return (0);
}

/**
 * Function Test if the stack is full
 */

int	is_full(int top, int size)
{
	if (top == size - 1)
		return (1);
	else
		return (0);
}

/**
 * Function returns top element in the stack
 */

long	peek(t_stack stack)
{
	return (stack.items[stack.top]);
}

/**
 * Function To pop an element from the stack
 */

void	pop(int *top)
{
	if (!is_empty(*top))
	{
		*top = *top - 1;
	}
}

/**
 * Function to push an element to stack
 */

t_stack	push(long new, t_stack stack)
{
	if (!is_full(stack.top, stack.size))
	{
		if (is_empty(stack.top))
			stack.first = new;
		stack.top = stack.top + 1;
		stack.items[stack.top] = new;
	}
	return (stack);
}
