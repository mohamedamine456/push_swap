#include "stacks.h"

t_stack	sort_more(t_stack stack_a, char ***opers)
{
	t_stack stack_b;

	stack_b = create_stack(stack_a.size);
	*opers = ft_resize_opers(*opers, "ra");
	return (stack_a);
}
