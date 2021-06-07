#include "stacks.h"

t_stack	sort_five(t_stack a, char ***opers)
{
	long	tmp;
	char	**opers_a;
	char	**opers_b;
	t_stack b;

	opers_a = NULL;
	opers_b = NULL;
	if (!check_sort_as(a))
	{
		b = create_stack(a.size / 2);
		push_three_b(&a, &b, opers);
		a = sort_three(a, &opers_a);
		b = sort_three(b, &opers_b);
		replace_a_b(&opers_b);
		add_opers(opers, opers_a, opers_b);
		while (b.top >= 0)
		{
			tmp = peek(b);
			pop(&(b.top));
			a = push(tmp, a);
			*opers = ft_resize_opers(*opers, "pa");
		}
	}
	return (a);
}

void   push_three_b(t_stack *a, t_stack *b, char ***opers)
{
	long tmp;
	int	index;

	while (a->top > 2)
	{
		index = minimum_index(a->items, a->top);
		bring_to_top(a, index, opers);
		tmp = peek(*a);
		pop(&(a->top));
		*b = push(tmp, *b);
		*opers = ft_resize_opers(*opers, "pb");
	}
}

void	bring_to_top(t_stack *a, int index, char ***opers)
{
	if (index >= a->top / 2)
	{
		while (index < a->top)
		{
			*a = r_a_b(*a);
			*opers = ft_resize_opers(*opers, "ra");
			index++;
		}
	}
	else
	{
		while (index >= 0)
		{
			*a = r_r_a_b(*a);
			*opers = ft_resize_opers(*opers, "rra");
			index--;
		}
	}
}

int	minimum_index(long *tab, int top)
{
	int i;
	int tmp;

	i = 0;
	tmp = i;
	while (i <= top)
	{
		if (tab[i] < tab[tmp])
			tmp = i;
		i++;
	}
	return (tmp);
}
