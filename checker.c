/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 11:45:41 by mlachheb          #+#    #+#             */
/*   Updated: 2021/06/09 12:03:50 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "stacks.h"

int		main(int argc, char **argv)
{
	int		retv;
	t_stack	stack_a;
	char	**operations;

	if (argc < 2)
		fatal();
	else
	{
		if (check_args(&(argv[1])))
			fatal();
		else
		{
			stack_a = fill_stack(argc, argv);
			operations = read_operations();
			stack_a = apply_operations(stack_a, operations);
			retv = check_sort_as(stack_a);
			ft_free_opers(operations);
			free(stack_a.items);
			ok_ko(retv);
		}
	}
}
