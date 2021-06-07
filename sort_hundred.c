#include "stacks.h"

t_stack	sort_hundred(t_stack a, char ***opers)
{
	t_stack b;
	char	**opers_a;
	char	**opers_b;

	opers_a = NULL;
	opers_b = NULL;
	if (!check_sort_as(a))
	{
		b = create_stack(a.size);
		a.items = replace_stack(a.items, a.top);
		push_to_b(&a, &b, opers, 50);
		sort_a_b(&a, &b, opers_a, opers_b, opers);
	}
	return (a);
}

//void	sort_a_b(t_stack *a, t_stack *b, char ***opers_a, char ***opers_b, char ***opers)
//{
//	int	i;
//
//	while (b->top >= 0)
//	{
//		i = minimum_index(b->items, b->top);
//	}
//}
