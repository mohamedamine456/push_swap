#include "stacks.h"

t_stack	sort_three(t_stack stack, char ***operations)
{
	if (!check_sort_as(stack))
	{
		if (stack.items[2] > stack.items[1] && stack.items[2] > stack.items[0])
		{
			*operations = ft_resize_opers(*operations, ft_strdup("ra"));
			stack = r_a_b(stack);
			if (stack.items[2] > stack.items[1])
			{
				*operations = ft_resize_opers(*operations, ft_strdup("sa"));
				stack = s_a_b(stack);
			}
		}
		else if (stack.items[2] > stack.items[1] && stack.items[2] < stack.items[0])
		{
			*operations = ft_resize_opers(*operations, ft_strdup("sa"));
			stack = s_a_b(stack);
		}
		else if (stack.items[2] < stack.items[1] && stack.items[2] > stack.items[0])
		{
			*operations = ft_resize_opers(*operations, ft_strdup("rra"));
			stack = r_r_a_b(stack);
		}
		else
		{
			*operations = ft_resize_opers(*operations, ft_strdup("sa"));
			*operations = ft_resize_opers(*operations, ft_strdup("ra"));
			stack = s_a_b(stack);
			stack = r_a_b(stack);
		}
	}
	return (stack);
}