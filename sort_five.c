#include "stacks.h"

t_stack	sort_five(t_stack stack_a, char ***opers)
{
	t_stack stack_b;
	char	**opers_a;
	char	**opers_b;

	opers_a = NULL;
	opers_b = NULL;
	stack_b = create_stack(stack_a.size);
	push_three_b(&stack_a, &stack_b);
	stack_a = sort_three(stack_a, &opers_a);
	//stack_b = sort_three_reversed(stack_b, &opers_b);
	replace_a_b(&opers_b);
	*opers = opers_a;
	return (stack_a);
}

void	push_three_b(t_stack *stack_a, t_stack *stack_b)
{
	long tmp;

	while (stack_a->top > 2)
	{
		tmp = peek(*stack_a);
		pop(&(stack_a->top));
		*stack_b = push(tmp, *stack_b);
	}
}
