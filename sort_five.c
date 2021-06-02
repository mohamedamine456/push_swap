#include "stacks.h"

t_stack	sort_five(t_stack stack_a, char ***opers)
{
	t_stack stack_b;
	char	**opers_a;
	char	**opers_b;

	opers_a = NULL;
	opers_b = NULL;
	if (!check_sort_as(stack_a))
	{
		stack_b = create_stack(stack_a.size);
		push_three_b(&stack_a, &stack_b, opers);
		stack_a = sort_three(stack_a, &opers_a);
		stack_b = sort_three_reversed(stack_b, &opers_b);
		replace_a_b(&opers_b);
		add_opers(opers, opers_a, opers_b);
		sort_five_helper(&stack_a, &stack_b, opers);
	}
	return (stack_a);
}

void	push_three_b(t_stack *stack_a, t_stack *stack_b, char ***opers)
{
	long tmp;

	while (stack_a->top > 2)
	{
		tmp = peek(*stack_a);
		pop(&(stack_a->top));
		*stack_b = push(tmp, *stack_b);
		*opers = ft_resize_opers(*opers, "pb");
	}
}

void	sort_five_helper(t_stack *a, t_stack *b, char ***opers)
{
	while (b->top > -1)
	{
		if (a->items[a->top] > b->items[b->top])
		{
			*opers = ft_resize_opers(*opers, "pa");
			p_a_b(b, a);
		}
		else if (a->first < b->items[b->top])
		{
			*opers = ft_resize_opers(*opers, "pa");
			*opers = ft_resize_opers(*opers, "ra");
			p_a_b(b, a);
			*a = r_a_b(*a);
		}
		else
		{
			if (b->items[b->top] > a->items[a->top] && b->items[b->top] < a->items[a->top - 1])
			{
				*opers = ft_resize_opers(*opers, "pa");
				p_a_b(b, a);
				*opers = ft_resize_opers(*opers, "sa");
				*a = r_a_b(*a);
			}
			else if (b->items[b->top] > a->items[a->top] && b->items[b->top] > a->items[a->top - 1])
			{
				*opers = ft_resize_opers(*opers, "pb");
				p_a_b(a, b);
				*opers = ft_resize_opers(*opers, "sb");
				*b = s_a_b(*b);
				*opers = ft_resize_opers(*opers, "pa");
				p_a_b(b, a);
				*opers = ft_resize_opers(*opers, "sa");
				*a = r_a_b(*a);
				*opers = ft_resize_opers(*opers, "pa");
				p_a_b(b, a);
			}
		}
	}
}
