#include "stacks.h"

char	**read_operations()
{
	char	**opers;
	char	*buff;

	opers = NULL;
	while (get_next_line(0, &buff) > 0)
	{
		if (is_operation(buff))
			opers = ft_resize_opers(opers, buff);
		else
		{
			free(buff);
			ft_free_opers(opers);
			fatal();
		}
	}
	if (is_operation(buff))
		opers = ft_resize_opers(opers, buff);
	else if (ft_strcmp(buff, ""))
	{
		free(buff);
		ft_free_opers(opers);
		fatal();
	}
	return (opers);
}

int		is_operation(char *str)
{
	int		i;
	char	**opers;

	i = 0;
	opers = ft_split(OPERS, ' ');
	if (str == NULL || opers == NULL)
		return (0);
	while (i < 11)
	{
		if (!ft_strcmp(str, opers[i]))
		{
			ft_free_opers(opers);
			return (1);
		}
		i++;
	}
	return (0);
}
