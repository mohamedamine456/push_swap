/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opers_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 11:02:15 by mlachheb          #+#    #+#             */
/*   Updated: 2021/06/02 12:10:10 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"

int	ft_size_opers(char **tab)
{
	int		i;

	i = 0;
	if (tab != NULL)
	{
		while (tab[i] != NULL)
			i++;
	}
	return (i);
}

void	add_opers(char ***opers, char **opers_a, char **opers_b)
{
	int i;

	i = 0;
	while (opers_a != NULL && opers_a[i] != NULL)
	{
		*opers = ft_resize_opers(*opers, opers_a[i]);
		i++;
	}
	i = 0;
	while (opers_b != NULL && opers_b[i] != NULL)
	{
		*opers = ft_resize_opers(*opers, opers_b[i]);
		i++;
	}
}

char	**ft_resize_opers(char **old, char *chaine)
{
	char **new;
	int i;
	int len;

	i = 0;
	if (old == NULL)
		len = 0;
	else
		len = ft_size_opers(old);
	new = (char **)malloc(sizeof(char *) * (len + 2));
	while (i < len)
	{
		new[i] = ft_strdup(old[i]);
		i++;
	}
	new[i] = ft_strdup(chaine);
	new[i + 1] = NULL;
	ft_free_opers(old);
	return (new);
}

void	ft_free_opers(char **opers)
{
    int     i;

    i = 0;
    if (opers != NULL)
    {
        while (opers[i] != NULL)
        {
            free(opers[i]);
            i++;
        }
        free(opers);
        opers = NULL;
    }
}

void	print_operations(char **opers)
{
	int	i;

	i = 0;
	while (opers != NULL && opers[i] != NULL)
	{
		printf("%s\n", opers[i]);
		i++;
	}
}
