#include "stacks.h"

t_stack	sort_three(t_stack a, char ***operations)
{
	if (!check_sort_as(a))
	{
		if (a.size == 2)
		{
			*operations = ft_resize_opers(*operations, ft_strdup("sa"));
			a = s_a_b(a);
		}
		else
		{
			if (a.items[a.top] > a.items[a.top - 1] && a.items[a.top] > a.items[a.top - 2])
			{
				*operations = ft_resize_opers(*operations, "ra");
				a = r_a_b(a);
				if (a.items[a.top] > a.items[a.top - 1])
				{
					*operations = ft_resize_opers(*operations, "sa");
					a = s_a_b(a);
				}
			}
			else if (a.items[a.top] > a.items[a.top - 1] && a.items[a.top] < a.items[a.top - 2])
			{
				*operations = ft_resize_opers(*operations, "sa");
				a = s_a_b(a);
			}
			else if (a.items[a.top] < a.items[a.top - 1] && a.items[a.top] > a.items[a.top - 2])
			{
				*operations = ft_resize_opers(*operations, "rra");
				a = r_r_a_b(a);
			}
			else
			{
				*operations = ft_resize_opers(*operations, "sa");
				*operations = ft_resize_opers(*operations, "ra");
				a = s_a_b(a);
				a = r_a_b(a);
			}
		}
	}
	return (a);
}

t_stack	sort_three_reversed(t_stack a, char ***operations)
{
	if (!check_sort_ds(a))
	{
		if (a.size == 2)
		{
			*operations = ft_resize_opers(*operations, ft_strdup("sa"));
			a = s_a_b(a);
		}
		else
		{
			if (a.items[a.top] < a.items[a.top - 1] && a.items[a.top] < a.items[a.top - 2])
			{
				*operations = ft_resize_opers(*operations, "ra");
				a = r_a_b(a);
				if (a.items[a.top] < a.items[a.top - 1])
				{
					*operations = ft_resize_opers(*operations, "sa");
					a = s_a_b(a);
				}
			}
			else if (a.items[a.top] < a.items[a.top - 1] && a.items[a.top] > a.items[a.top - 2])
			{
				*operations = ft_resize_opers(*operations, "sa");
				a = s_a_b(a);
			}
			else if (a.items[a.top] > a.items[a.top - 1] && a.items[a.top] < a.items[a.top - 2])
			{
				*operations = ft_resize_opers(*operations, "rra");
				a = r_r_a_b(a);
			}
			else
			{
				*operations = ft_resize_opers(*operations, "sa");
				*operations = ft_resize_opers(*operations, "ra");
				a = s_a_b(a);
				a = r_a_b(a);
			}
		}
	}
	return (a);
}
