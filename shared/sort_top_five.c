/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_top_five.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 20:33:13 by mlachheb          #+#    #+#             */
/*   Updated: 2021/06/08 13:51:31 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"
#include "../stacks.h"

void	sort_top_five(t_stack *a, t_stack *b, char ***opers)
{
	int		i;
	long	tmp;

	i = 0;
	if (!check_top_five_sort(*a))
	{
		//sort top five with easy sort than push them back to a and ra
	}
}

int		check_top_five_sort(t_stack stack)
{
	int		i;	
	long    temp1;
	long    temp2;

	i = 0;
	if (!is_empty(stack.top))
	{
		temp1 = peek(stack);
		pop(&(stack.top));
	}
	while (!is_empty(stack.top) && i < 5)
	{
		temp2 = peek(stack);
		pop(&(stack.top));
		if (temp1 <= temp2)
			return (0);
		temp1 = temp2;
		i++;
	}
	return (1);
}
