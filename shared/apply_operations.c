/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 11:17:39 by mlachheb          #+#    #+#             */
/*   Updated: 2021/06/11 12:29:25 by mlachheb         ###   ########.fr       */
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
		call_opers(&stack_a, &stack_b, opers[i]);
		i++;
	}
	free(stack_b.items);
	return (stack_a);
}

void	call_opers(t_stack *a, t_stack *b, char *opers)
{
	if (!ft_strcmp(opers, "sa"))
		*a = s_a_b(*a);
	else if (!ft_strcmp(opers, "sb"))
		*b = s_a_b(*b);
	else if (!ft_strcmp(opers, "ss"))
		s_s(a, b);
	else if (!ft_strcmp(opers, "pa"))
		p_a_b(b, a);
	else if (!ft_strcmp(opers, "pb"))
		p_a_b(a, b);
	else if (!ft_strcmp(opers, "ra"))
		*a = r_a_b(*a);
	else if (!ft_strcmp(opers, "rb"))
		*b = r_a_b(*b);
	else if (!ft_strcmp(opers, "rr"))
		r_r(a, b);
	else if (!ft_strcmp(opers, "rra"))
		*a = r_r_a_b(*a);
	else if (!ft_strcmp(opers, "rrb"))
		*b = r_r_a_b(*b);
	else
		r_r_r(a, b);
}

void	check_print_operations(char	**operations1, char	**operations2)
{
	int	i;

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
