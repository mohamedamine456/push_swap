#include "stacks.h"

void	print_stack(t_stack a)
{
	int i;

	i = a.top;
	while (i >= 0)
	{
		printf("%3ld", a.items[i]);
		i--;
	}
}