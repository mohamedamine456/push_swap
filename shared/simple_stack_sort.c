#include "shared.h"
#include "../stacks.h"

void	easy_five_sort(t_stack *a, t_stack *b, char ***opers)
{
	long	tmp;
	long	tmp2;

	while (!is_empty(a->top))
	{
		tmp = peek(*a);
		pop(&(a->top));
		if (is_empty(b->top) || tmp > peek(*b))
			*b = push(tmp, *b);
		else
		{
			while (!is_empty(b->top) && tmp < peek(*b))
			{
				tmp2 = peek(*b);
				pop(&(b->top));
				*a = push(tmp2, *a);
			}
			*b = push(tmp, *b);
		}
	}
	while (!is_empty(b->top))
	{
		tmp = peek(*b);
		pop(&(b->top));
		*a = push(tmp, *a);
	}	
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
