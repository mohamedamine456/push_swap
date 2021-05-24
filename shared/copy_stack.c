/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 15:30:12 by mlachheb          #+#    #+#             */
/*   Updated: 2021/05/24 15:32:52 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"

t_stack	copy_stack(t_stack a)
{
	t_stack temp;
	int		i;

	i = 0;
	temp = create_stack(a.size);
	while (i < a.size)
	{
		temp.items[i] = a.items[i];
		i++;
	}
	temp.top = a.top;
	temp.first = a.first;
	return (temp);
}
