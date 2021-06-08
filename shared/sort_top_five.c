/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_top_five.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 20:33:13 by mlachheb          #+#    #+#             */
/*   Updated: 2021/06/08 21:13:18 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"
#include "../stacks.h"

void	sort_top_five(t_stack *a, t_stack *b, char ***opers)
{
	int i;
	int j;

	i = 2;
	p_a_b(a, b);
	p_a_b(a, b);
	if (b->items[b->top] < b->items[b->top - 1])
	{
		*opers = ft_resize_opers(*opers, "sb");
		*b = s_a_b(*b);
	}
	sort_top_three(a, b, opers);
	while (i > 0)
	{
		if (peek(*a) > peek(*b))
		{
			*opers = ft_resize_opers(*opers, "pa");
			p_a_b(b, a);
		}
		else
		{
			j = 0;
			while (a->top >= 0 && peek(*a) < peek(*b))
			{
				*opers = ft_resize_opers(*opers, "pb");
				p_a_b(a, b);
				*opers = ft_resize_opers(*opers, "sb");
				*b = s_a_b(*b);
				j++;
			}
			*opers = ft_resize_opers(*opers, "pa");
			p_a_b(b, a);
			while (j > 0)
			{
				*opers = ft_resize_opers(*opers, "pa");
				p_a_b(b, a);
				j--;
			}
		}	
		i--;
	}
}

void	sort_top_three(t_stack *a, t_stack *b, char ***opers)
{
	if (!check_top_sort(*a, 3))
	{
		if (a->size == 2)
		{
			*opers = ft_resize_opers(*opers, ft_strdup("sa"));
			*a = s_a_b(*a);
		}
		else
		{
			if (a->items[a->top] > a->items[a->top - 1] && a->items[a->top] > a->items[a->top - 2])
			{
				*opers = ft_resize_opers(*opers, "sa");
				*a = s_a_b(*a);
				*opers = ft_resize_opers(*opers, "pb");
				p_a_b(a, b);
				*opers = ft_resize_opers(*opers, "sa");
				*a = s_a_b(*a);
				*opers = ft_resize_opers(*opers, "pa");
				p_a_b(b, a);
				if (a->items[a->top] > a->items[a->top - 1])
				{
					*opers = ft_resize_opers(*opers, "sa");
					*a = s_a_b(*a);
				}
			}
			else if (a->items[a->top] > a->items[a->top - 1] && a->items[a->top] < a->items[a->top - 2])
			{
				*opers = ft_resize_opers(*opers, "sa");
				*a = s_a_b(*a);
			}
			else if (a->items[a->top] < a->items[a->top - 1] && a->items[a->top] > a->items[a->top - 2])
			{
				*opers = ft_resize_opers(*opers, "pb");
				p_a_b(a, b);
				*opers = ft_resize_opers(*opers, "sa");
				*a = s_a_b(*a);
				*opers = ft_resize_opers(*opers, "pa");
				p_a_b(b, a);
				*opers = ft_resize_opers(*opers, "sa");
				*a = s_a_b(*a);
			}
			else
			{
				*opers = ft_resize_opers(*opers, "pb");
				p_a_b(a, b);
				*opers = ft_resize_opers(*opers, "sa");
				*a = s_a_b(*a);
				*opers = ft_resize_opers(*opers, "pa");
				p_a_b(b, a);
			}
		}
	}
}

int		check_top_sort(t_stack stack, int size)
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
	while (!is_empty(stack.top) && i < size)
	{
		temp2 = peek(stack);
		pop(&(stack.top));
		if (temp2 <= temp1)
			return (0);
		temp1 = temp2;
		i++;
	}
	return (1);
}

//int main(int argc, char **argv)
//{
//	t_stack stack_a;
//	t_stack stack_b;
//	char    **opers;
//
//	opers = NULL;
//	if (argc < 2)
//		fatal();
//	else
//	{
//		if (check_args(argv + 1))
//			fatal();
//		else
//		{
//			stack_a = fill_stack(argc, argv);
//			stack_b = create_stack(stack_a.size);
//			sort_top_five(&stack_a, &stack_b, &opers);
//			print_stack(stack_a);
//			printf("\n");
//			print_operations(opers);
//			ft_free_opers(opers);
//			free(stack_a.items);
//		}
//	}
//	return (0);
//}
