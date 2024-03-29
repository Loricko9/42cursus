/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sort3_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:00:15 by lle-saul          #+#    #+#             */
/*   Updated: 2023/11/16 15:25:16 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Checker_bonus.h"

void	pb2_checker(t_list **stack_a, t_list **stack_b)
{
	t_list	*next_b;
	t_list	*prec_b;

	next_b = (*stack_b)->next;
	prec_b = (*stack_b)->prec;
	if (next_b == NULL && prec_b == NULL)
	{
		(*stack_a)->next = *stack_b;
		(*stack_a)->prec = *stack_b;
		(*stack_b)->prec = *stack_a;
		(*stack_b)->next = *stack_a;
	}
	else
	{
		(*stack_a)->next = *stack_b;
		(*stack_a)->prec = prec_b;
		(*stack_b)->prec = *stack_a;
		prec_b->next = *stack_a;
	}
	*stack_b = *stack_a;
}

void	pa2_checker(t_list **stack_a, t_list **stack_b)
{
	t_list	*next_a;
	t_list	*prec_a;

	next_a = (*stack_a)->next;
	prec_a = (*stack_a)->prec;
	if (next_a == NULL && prec_a == NULL)
	{
		(*stack_b)->next = *stack_a;
		(*stack_b)->prec = *stack_a;
		(*stack_a)->prec = *stack_b;
		(*stack_a)->next = *stack_b;
	}
	else
	{
		(*stack_b)->next = *stack_a;
		(*stack_b)->prec = prec_a;
		(*stack_a)->prec = *stack_b;
		prec_a->next = *stack_b;
	}
	*stack_a = *stack_b;
}
