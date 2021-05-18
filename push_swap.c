/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 07:53:12 by mlachheb          #+#    #+#             */
/*   Updated: 2021/05/18 15:01:09 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stacks.h"

int main(int argc, char **argv)
{
	t_stack	stack_a;
	char	**operations;

	operations = NULL;
	if (argc < 2)
		fatal();
	else
	{
		if (check_args(argv + 1))
			fatal();
		else
		{
			stack_a = fill_stack(argc, argv);

			stack_a = sort_five(stack_a, &operations);
			print_operations(operations);
			ft_free_opers(operations);
			free(stack_a.items);
		}
	}
	return (0);
}

