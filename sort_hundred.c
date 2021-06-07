#include "stacks.h"

t_stack	sort_hundred(t_stack a, char ***opers)
{
	t_stack b;

	if (!check_sort_as(a))
	{
		b = create_stack(a.size);
		a.items = replace_stack(a.items, a.top);
		push_to_b(&a, &b, opers, 50);
		sort_a_b(&a, &b, opers);
	}
	return (a);
}

void	sort_a_b(t_stack *a, t_stack *b, char ***opers)
{
	int	min;
	int	i;

	min = 0;
	while (b->top >= 5)
	{
		i = 0;
		bring_low_five(a, b, opers, min);
		sort_top_five(a, b, opers);
		while (i < 5 && a->items[a->top] > a->items[a->top - 1])
		{
			*opers = ft_resize_opers(*opers, "ra");
			*a = r_a_b(*a);
			i++;
		}
		min += 5;
	}
}

void	bring_low_five(t_stack *a, t_stack *b, char ***opers, long min)
{
	int		i;
	int		j;
	long	tmp;

	i = 0;
	while (i < 5)
	{
		j = 0;
		while (j <= b->top)
		{
			if (b->items[j] >= min && b->items[j] < min + 5)
			{
				bring_to_top(b, j, opers);
				tmp = peek(*b);
				pop(&(b->top));
				*a = push(tmp, *a);
				*opers = ft_resize_opers(*opers, "pa");
				replace_a_b(opers);
				break ;
			}
			j++;
		}
		i++;
	}
}
