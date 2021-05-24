/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 10:46:18 by mlachheb          #+#    #+#             */
/*   Updated: 2021/05/24 17:31:51 by mlachheb         ###   ########.fr       */
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

t_stack			sort_five(t_stack stack_a, char ***operations);
void			sort_a_b(t_stack *a, t_stack *b, char ***opers);
void			add_operations(char ***opers, char *oper, int *op1, int *op2);


t_stack			sort_hundred(t_stack stack_a, char ***opers);


t_stack			sort_more(t_stack stack_a, char ***opers);

#endif
