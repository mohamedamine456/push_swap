#include "stacks.h"

t_stack	sort_five(t_stack a, char ***opers)
{
	char	**opers_a;
	char	**opers_b;
	t_stack b;

	opers_a = NULL;
	opers_b = NULL;
	if (!check_sort_as(a))
	{
		b = create_stack(a.size);
		push_to_b(&a, &b, opers, 3);
		a = sort_three(a, &opers_a);
		add_opers(opers, opers_a, opers_b);
		while (b.top >= 0)
		{
			p_a_b(&b, &a);
			*opers = ft_resize_opers(*opers, "pa");
		}
	}
	ft_free_opers(opers_a);
	ft_free_opers(opers_b);
	free(b.items);
	return (a);
}
