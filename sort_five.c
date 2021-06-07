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
		push_to_b(&a, &b, opers, 3);
		a = sort_three(a, &opers_a);
		b = sort_three_reversed(b, &opers_b);
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
