/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 14:02:28 by mlachheb          #+#    #+#             */
/*   Updated: 2021/06/12 14:09:17 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stacks.h"

t_stack	sort_five(t_stack a, char ***opers)
{
	t_stack	b;

	if (!check_sort_as(a))
	{
		b = create_stack(a.size);
		push_to_b(&a, &b, opers, 3);
		a = sort_three(a, opers);
		while (b.top >= 0)
		{
			p_a_b(&b, &a);
			*opers = ft_resize_opers(*opers, "pa");
		}
		free(b.items);
	}	
	return (a);
}
