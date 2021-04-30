/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 09:25:58 by mlachheb          #+#    #+#             */
/*   Updated: 2021/04/27 09:26:31 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"

long	ft_atoi(const char *str)
{
	int			i;
	int			neg;
	long	res;

	i = 0;
	neg = 1;
	res = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg = -1;
		i++;
	}
	res = number(str + i, neg);
	return (res);
}

long	number(const char *str, int neg)
{
	int		i;
	long	res;

	i = 0;
	res = 0;
	while (str[i] >= 48 && str[i] <= 57)
	{
		res = res * 10 + str[i] - 48;
		if (res > 4294967295)
		{
			if (neg < 0)
				return (0);
			else
				return (-1);
		}
		i++;
	}
	return (res * neg);
}
