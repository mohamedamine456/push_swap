#include "stacks.h"

t_stack	sort_five(t_stack stack_a, char ***operations)
{
	t_stack	stack_b;
	long	temp;

	stack_b = create_stack(stack_a.size - 3);
	if (!check_sort_as(stack_a))
	{
		while (stack_a.top > 2)
		{
			*operations = ft_resize_opers(*operations, ft_strdup("pb"));
			p_a_b(&stack_a, &stack_b);
		}
		sort_a_b(&stack_a, stack_b);
		while (stack_b.top != -1)
		{
			*operations = ft_resize_opers(*operations, ft_strdup("pa"));
			p_a_b(&stack_b, &stack_a);
		}
	}
	return (stack_a);
}

void	sort_a_b(t_stack *a, t_stack *b, char ***opers)
{
	int op1;
	int op2;

	op1 = 0;
	op2 = 0;
	if (a->items[2] > a->items[1] && a->items[2] > a->items[0] && !check_sort_as(*a))
	{
		op1 = 1;
		*a = r_a_b(a);
		//////////------------check sa----------
	}
	if (b->items[2] < b->items[1] && b->items[2] < b->items[0] && !check_sort_ds(*b))
	{
		op2 = 1;
		*b = r_a_b(*b);
		//////////------------check sb----------
	}
	add_operations(opers, "ra,rb,rr", &op1, &op2);
	if (a->items[2] > a->items[1] && a->items[2] < a->items[0] && !check_sort_as(*a))
	{
		op1 = 1;
		*a = s_a_b(*a);
	}
	if (b->items[2] < b->items[1] && b->items[2] > b->items[0] && !check_sort_ds(*b))
	{
		op2 = 1;
		*b = s_a_b(*b);
	}
	add_operations(opers, "sa,sb,ss", &op1, &op2);
	if (a->items[2] < a->items[1] && a->items[2] > a->items[0] && !check_sort_as(*a))
	{
		op1 = 1;
		*a = r_r_a_b(*a);
	}
	if (b->items[2] > b->items[1] && b->items[2] < b->items[0] && !check_sort_ds(*b))
	{
		op2 = 1;
		*b = r_r_a_b(*b);
	}
	add_operations(opers, "sa,sb,ss", &op1, &op2);
	if (!check_sort_as(*a) && !check_sort_ds(*b))
	{
		*operations = ft_resize_opers(*operations, ft_strdup("ss"));
		*operations = ft_resize_opers(*operations, ft_strdup("rr"));
		s_s(a, b);
		r_r(a, b);
	}
	else if (!check_sort_as(*a) && check_sort_ds(*b))
	{
		*operations = ft_resize_opers(*operations, ft_strdup("sa"));
		*operations = ft_resize_opers(*operations, ft_strdup("ra"));
		*a = s_a_b(*a);
		*a = r_a_b(*a);
	}
	else if (!check_sort_as(*a) && !check_sort_ds(*b))
	{
		*operations = ft_resize_opers(*operations, ft_strdup("sb"));
		*operations = ft_resize_opers(*operations, ft_strdup("rb"));
		*b = s_a_b(*b);
		*b = r_a_b(*b);
	}
}

void	add_operations(char ***opers, char *oper, int *op1, int *op2)
{
	char	**tab;

	tab = ft_split(oper, ',');
	if (*op1 == 1 && op2 == 1)
		*opers = ft_resize_opers(*opers, ft_strdup(tab[2]));
	else if (*op1 == 1 && op2 != 1)
		*opers = ft_resize_opers(*opers, ft_strdup(tab[0]));
	else if (*op1 != 1 && op2 == 1)
		*opers = ft_resize_opers(*opers, ft_strdup(tab[1]));
	*op1 = 0;
	*op2 = 0;
	ft_free_opers(tab);
}
