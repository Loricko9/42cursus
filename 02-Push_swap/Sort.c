/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 14:33:01 by lle-saul          #+#    #+#             */
/*   Updated: 2023/11/16 15:25:10 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

void	sab(t_list *stack, int a)
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
	if (a == 1)
		ft_printf("sa\n");
	if (a == 0)
		ft_printf("sb\n");
}

void	ss(t_list *stack_a, t_list *stack_b)
{
	sab(stack_a, 2);
	sab(stack_b, 2);
	ft_printf("ss\n");
}

void	pb(t_list **stack_a, t_list **stack_b)
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
		pb2(stack_a, stack_b);
	*stack_a = next_a;
	ft_printf("pb\n");
}

void	pa(t_list **stack_a, t_list **stack_b)
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
		pa2(stack_a, stack_b);
	*stack_b = next_b;
	ft_printf("pa\n");
}
