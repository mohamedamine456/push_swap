#include "stacks.h"

t_stack	sort_five(t_stack stack_a, char ***opers)
{
	t_stack stack_b;
	char	**opers_a;
	char	**opers_b;

	opers_a = NULL;
	opers_b = NULL;
	stack_b = create_stack(stack_a.size);
	push_three_b(&stack_a, &stack_b, opers);
	stack_a = sort_three(stack_a, &opers_a);
	stack_b = sort_three_reversed(stack_b, &opers_b);
	replace_a_b(&opers_b);
	add_opers_five(opers, opers_a, opers_b);
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

void	add_opers_five(char ***opers, char **opers_a, char **opers_b)
{
	int i;

	i = 0;
	if (opers_a != NULL && opers_b != NULL && opers_a[0] != NULL && opers_b[0] != NULL)
	{
		if (!ft_strcmp(opers_a[0], "sa"))
		{
			if (!ft_strcmp(opers_b[0], "sb"))
				*opers = ft_resize_opers(*opers, "ss");
			else if (opers_b[1] != NULL && !ft_strcmp(opers_b[1], "sb"))
			{
				*opers = ft_resize_opers(*opers, opers_b[0]);
				*opers = ft_resize_opers(*opers, "ss");
			}
			else if (opers_a[1] != NULL)
				*opers = ft_resize_opers(*opers, opers_a[1]);
			else if (opers_b[1] != NULL)
				*opers = ft_resize_opers(*opers, opers_b[1]);
		}
		else if (opers_a[0] != NULL && opers_a[1] != NULL && !ft_strcmp(opers_a[1], "sa"))
		{
			*opers = ft_resize_opers(*opers, opers_a[0]);
			if (!ft_strcmp(opers_b[0], "sb"))
				*opers = ft_resize_opers(*opers, "ss");
			else if (opers_b[1] != NULL && !ft_strcmp(opers_b[1], "sb"))
			{
				*opers = ft_resize_opers(*opers, opers_b[0]);
				*opers = ft_resize_opers(*opers, "ss");
			}
		}
	}
	else
	{
		while (opers_a != NULL && opers_a[i] != NULL)
		{
			*opers = ft_resize_opers(*opers, opers_a[i]);
			i++;
		}
		i = 0;
		while (opers_b != NULL && opers_b[i] != NULL)
		{
			*opers = ft_resize_opers(*opers, opers_b[i]);
			i++;
		}
	}
}
