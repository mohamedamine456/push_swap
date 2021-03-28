/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 18:48:16 by mlachheb          #+#    #+#             */
/*   Updated: 2021/03/28 18:55:22 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "structs.h"
# include <stdio.h>
# include <stdlib.h>

int main(int argc, char **argv)
{
	t_stack		*stack_a;
	int			i;

	i = 1;
	stack_a = (t_stack *)malloc(sizeof(t_stack) * (argc - 1));
	while (argv != NULL && argv[i] != NULL)
	{
		stack_a[i - 1].number = atoi(argv[i]);
		stack_a[i - 1].id_number = i - 1;
		i++;
	} 
	i = 0;
	while (i < argc - 1)
	{
		printf("id_number : %7d, number: %9d\n", stack_a[i].id_number, stack_a[i].number);
		i++;
	}
	return (0);
}
