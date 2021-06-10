#include "shared.h"

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

int	maximum_index(long *tab, int top)
{
	int i;
	int tmp;

	i = 0;
	tmp = i;
	while (i <= top)
	{
		if (tab[i] > tab[tmp])
			tmp = i;
		i++;
	}
	return (tmp);
}

int	minimum_stack(long *tab, int top, int min, int max)
{
	int i;
	int tmp;

	i = 0;
	tmp = i;
	while (i <= top)
	{
		if (tab[i] < tab[tmp] && tab[i] >= min && tab[i] < max)
			tmp = i;
		i++;
	}
	return (tmp);
}
