/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 11:17:39 by mlachheb          #+#    #+#             */
/*   Updated: 2021/04/24 14:52:17 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"

t_stack	apply_operations(t_stack stack_a, char **opers)
{
	t_stack	stack_b;
	int		i;

	stack_b = create_stack(stack_a.size);
	i = 0;
	while (opers != NULL && opers[i] != NULL)
	{

		if (!ft_strcmp(opers[i], "sa"))
			stack_a = s_a_b(stack_a);
		else if (!ft_strcmp(opers[i], "sb"))
			stack_b = s_a_b(stack_b);
		else if (!ft_strcmp(opers[i], "ss"))
			s_s(&stack_a, &stack_b);
		else if (!ft_strcmp(opers[i], "pa"))
			p_a_b(&stack_b, &stack_a);
		else if (!ft_strcmp(opers[i], "pb"))
			p_a_b(&stack_a, &stack_b);
		else if (!ft_strcmp(opers[i], "ra"))
			stack_a = r_a_b(stack_a);
		else if (!ft_strcmp(opers[i], "rb"))
			stack_b = r_a_b(stack_b);
		else if (!ft_strcmp(opers[i], "rr"))
			r_r(&stack_a, &stack_b);
		else if (!ft_strcmp(opers[i], "rra"))
			stack_a = r_r_a_b(stack_a);
		else if (!ft_strcmp(opers[i], "rrb"))
			stack_b = r_r_a_b(stack_b);
		else
			r_r_r(&stack_a, &stack_b);
		i++;
	}
	free(stack_b.items);
	return (stack_a);
}


void	check_print_operations(char	**operations1, char	**operations2)
{
	int i;

	i = 0;
	if (ft_size_opers(operations1) <= ft_size_opers(operations2))
	{
		while (operations1 != NULL && operations1[i] != NULL)
		{
			printf("%s\n", operations1[i]);
			i++;
		}
	}
	else
	{
		while (operations2 != NULL && operations2[i] != NULL)
		{
			printf("%s\n", operations2[i]);
			i++;
		}
	}
}