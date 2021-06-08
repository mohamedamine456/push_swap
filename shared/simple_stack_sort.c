#include "shared.h"
#include "../stacks.h"

void	easy_five_sort(t_stack *a, t_stack *b, char ***opers)
{
	int		pb;
	int		pa;

	pb = 0;
	pa = 5;
	while (pa > 0 && !is_empty(a->top))
	{
		if (pb == 0 || peek(*a) > peek(*b))
		{
			p_a_b(a, b);
			pa--;
			pb++;
		}
		else
		{
			while (pb > 0 && pa < 5 && peek(*a) < peek(*b))
			{
				p_a_b(b, a);
				*a = s_a_b(*a);
				pb--;
				pa++;
			}
			p_a_b(a, b);
			pb++;
			pa--;
		}
	}
	while (pb > 0)
	{
		p_a_b(b, a);
		pb--;
		pa++;
	}
	printf("pb: %d, i: %d\n", pb, pa);
}

int main(int argc, char **argv)
{
	t_stack stack_a;
	t_stack stack_b;
	char    **opers;

	opers = NULL;
	if (argc < 2)
		fatal();
	else
	{
		if (check_args(argv + 1))
			fatal();
		else
		{
			stack_a = fill_stack(argc, argv);
			stack_b = create_stack(stack_a.size);
			easy_five_sort(&stack_a, &stack_b, &opers);
			print_stack(stack_a);
			print_stack(stack_b);
			ft_free_opers(opers);
			free(stack_a.items);
		}
	}
	return (0);
}
