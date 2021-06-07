/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 10:46:18 by mlachheb          #+#    #+#             */
/*   Updated: 2021/06/07 11:42:18 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACKS_H
# define STACKS_H
# include "shared/shared.h"
# include "push_swap.h"

/*
 * prototypes for read_operations.c file
 */

char			**read_operations(void);
int				is_operation(char *str);

/*
 * prototypes for opers_functions.c file
 */

t_stack			sort_stack_ra(t_stack stack_a, char ***operations);
t_stack			sort_stack_rra(t_stack stack_a, char ***operations);
void			sort_helper(t_stack *stack_a, t_stack *stack_b,
		long tmp, char ***operations);
void			push_to_b(t_stack *stack_a, t_stack *stack_b,
		char ***operations);

/*
 * prototypes for check_ps_sort.c file
 */

t_stack			check_sa(t_stack stack, char ***operations);
t_stack			check_ra(t_stack stack, char ***operations);
t_stack			check_rra(t_stack stack, char ***operations);
void			move_b_a(t_stack *stack_a, t_stack *stack_b, char ***operations);

/*
 * prototypes for sort_three.c file
 */

t_stack			sort_three(t_stack stack, char ***operations);
t_stack			sort_three_reversed(t_stack stack, char ***operations);

/*
 * prototypes for sort_five.c file
 */

t_stack			sort_five(t_stack stack_a, char ***operations);
void			push_three_b(t_stack *stack_a, t_stack *stack_b, char ***opers);
void			bring_to_top(t_stack *a, int index, char ***opers);
int				minimum_index(long *tab, int top);

/*
 * prototypes for sort_hundred.c file
 */

t_stack			sort_hundred(t_stack stack_a, char ***opers);

/*
 * prototypes for sort_more.c file
 */

t_stack			sort_more(t_stack stack_a, char ***opers);

#endif
