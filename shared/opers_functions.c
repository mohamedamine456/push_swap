/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opers_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 11:02:15 by mlachheb          #+#    #+#             */
/*   Updated: 2021/04/27 09:27:14 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"

int		ft_size_opers(char **tab)
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

char		**ft_resize_opers(char **old, char *chaine)
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
	free(chaine);
	return (new);
}

void        ft_free_opers(char **opers)
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
		printf("%9s", opers[i]);
		i++;
	}
	printf("\n");
}
