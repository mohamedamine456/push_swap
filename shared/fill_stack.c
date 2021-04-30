/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 09:28:40 by mlachheb          #+#    #+#             */
/*   Updated: 2021/04/27 09:28:41 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"

t_stack	fill_stack(int argc, char **argv)
{
	t_stack	stack;
	int			i;
	long	number;

	stack = create_stack(argc - 1);
	i = ft_size_opers(argv) - 1;
	while (argv != NULL && argv[i] != NULL && i > 0)
	{
		number = ft_atoi(argv[i]);
		if (in_stack(number, stack.items, stack.top)
			|| number > INT32_MAX || number < INT32_MIN
			|| ft_strlen(argv[i]) > 10)
		{
			free(stack.items);
			fatal();
		}
		stack = push(number, stack);
		i--;
	}
	return (stack);
}

int		in_stack(long number, long *table, int size)
{
	int i;

	i = 0;
	while (i <= size)
	{
		if (number == table[i])
			return (1);
		i++;
	}
	return (0);
}
