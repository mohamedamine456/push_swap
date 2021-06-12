/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 10:46:18 by mlachheb          #+#    #+#             */
/*   Updated: 2021/06/11 14:05:13 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACKS_H
# define STACKS_H
# include "shared/shared.h"

/*
 * prototypes for read_operations.c file
 */

char			**read_operations(void);
int				is_operation(char *str);

/*
 * prototypes for check_ps_sort.c file
 */

t_stack			check_sa(t_stack stack, char ***operations);
t_stack			check_ra(t_stack stack, char ***operations);
t_stack			check_rra(t_stack stack, char ***operations);
void			move_b_a(t_stack *stack_a,
					t_stack *stack_b, char ***operations);

/*
 * prototypes for sort_three.c file
 */

t_stack			sort_three(t_stack stack, char ***operations);
void			sort_three_helper(t_stack *a, char ***opers);
t_stack			sort_three_reversed(t_stack stack, char ***operations);
void			sort_three_reversed_helper(t_stack *a, char ***opers);

/*
 * prototypes for sort_five.c file
 */

t_stack			sort_five(t_stack stack_a, char ***operations);
void			push_three_b(t_stack *stack_a, t_stack *stack_b, char ***opers);

/*
 * prototypes for sort_hundred.c file
 */

t_stack			sort_hundred(t_stack stack_a, char ***opers);
void			push_five_chunks(t_stack *a, t_stack *b, char ***opers);

/*
 * prototypes for sort_more.c file
 */

t_stack			sort_more(t_stack stack_a, char ***opers);
void			push_ten_chunks(t_stack *a, t_stack *b, char ***opers);
void			push_rest_chunks(t_stack *a, t_stack *b, char ***opers);

#endif
