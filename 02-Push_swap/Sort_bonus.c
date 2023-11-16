/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sort_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 13:53:14 by lle-saul          #+#    #+#             */
/*   Updated: 2023/11/16 13:53:14 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Checker_bonus.h"

void	sab_checker(t_list *stack)
{
	t_list	*next;
	int		temp;

	next = stack->next;
	temp = stack->nb;
	stack->nb = next->nb;
	next->nb = temp;
	temp = stack->rank;
	stack->rank = next->rank;
	next->rank = temp;
}

void	ss_checker(t_list *stack_a, t_list *stack_b)
{
	sab_checker(stack_a);
	sab_checker(stack_b);
}

void	pb_checker(t_list **stack_a, t_list **stack_b)
{
	t_list	*next_a;
	t_list	*prec_a;

	next_a = (*stack_a)->next;
	prec_a = (*stack_a)->prec;
	if ((next_a == prec_a) && (next_a != NULL && prec_a != NULL))
	{
		next_a->next = NULL;
		next_a->prec = NULL;
	}
	else if (next_a != NULL && prec_a != NULL)
	{
		next_a->prec = prec_a;
		prec_a->next = next_a;
	}
	if (*stack_b == NULL)
	{
		*stack_b = *stack_a;
		(*stack_b)->next = NULL;
		(*stack_b)->prec = NULL;
	}
	else
		pb2_checker(stack_a, stack_b);
	*stack_a = next_a;
}

void	pa_checker(t_list **stack_a, t_list **stack_b)
{
	t_list	*next_b;
	t_list	*prec_b;

	next_b = (*stack_b)->next;
	prec_b = (*stack_b)->prec;
	if ((next_b == prec_b) && (next_b != NULL && prec_b != NULL))
	{
		next_b->next = NULL;
		next_b->prec = NULL;
	}
	else if (next_b != NULL && prec_b != NULL)
	{
		next_b->prec = prec_b;
		prec_b->next = next_b;
	}
	if (*stack_a == NULL)
	{
		*stack_a = *stack_b;
		(*stack_a)->next = NULL;
		(*stack_a)->prec = NULL;
	}
	else
		pa2_checker(stack_a, stack_b);
	*stack_b = next_b;
}

