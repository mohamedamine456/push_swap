#include "stacks.h"

t_stack	sort_more(t_stack a, char ***opers)
{
	t_stack b;

	if(!check_sort_as(a))
	{
		b = create_stack(a.size);
		a.items = replace_stack(a.items, a.top);
		push_ten_chunks(&a, &b, opers);
		push_to_a(&a, &b, opers);
	}
	(void)opers;
	return (a);
}

void	push_ten_chunks(t_stack *a, t_stack *b, char ***opers)
{
	int	i;
	int	j;
	int	min;

	i = 0;
	min = 0;
	while (i < a->size)
	{
		j = 0;
		while (j <= a->top)
		{
			if (a->items[j] >= min && a->items[j] < min + 50)
			{
				bring_to_top_a(a, j, opers);
				p_a_b(a, b);
				*opers = ft_resize_opers(*opers, "pb");
				break ;
			}
			j++;
		}
		if ((b->top + 1) % 50 == 0)
			min += 50;
		i++;
	}
}