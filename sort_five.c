#include "stacks.h"

t_stack	sort_five(t_stack stack_a, char ***opers)
{
	char	**opers1;
	char	**opers2;
	t_stack	tmp;

	opers1= NULL;
	opers2 = NULL;
	tmp = copy_stack(stack_a);
	stack_a = sort_stack_ra(stack_a, &opers1);
	tmp = sort_stack_rra(tmp, &opers2);

    if (ft_size_opers(opers1) <= ft_size_opers(opers2))
	{
		*opers = opers1;
		ft_free_opers(opers2);
	}
	else
	{
		*opers = opers2;
		ft_free_opers(opers1);
	}
	return (stack_a);
}
