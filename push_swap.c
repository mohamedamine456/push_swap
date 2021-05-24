/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 07:53:12 by mlachheb          #+#    #+#             */
/*   Updated: 2021/05/24 19:03:02 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stacks.h"

int main(int argc, char **argv)
{
	t_stack	stack_a;
	char	**opers;

	opers = NULL;
	if (argc < 2)
		fatal();
	else
	{
		if (check_args(argv + 1))
			fatal();
		else
		{
			stack_a = fill_stack(argc, argv);
			if (stack_a.size <= 3)
				stack_a = sort_three(stack_a, &opers);
			else if (stack_a.size <= 6)
				stack_a = sort_five(stack_a, &opers);
			else if (stack_a.size <= 100)
				stack_a = sort_hundred(stack_a, &opers);
			else
				stack_a = sort_more(stack_a, &opers);
			print_operations(opers);
			ft_free_opers(opers);
			free(stack_a.items);
		}
	}
	return (0);
}
