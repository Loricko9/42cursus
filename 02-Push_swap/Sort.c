/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 14:33:01 by lle-saul          #+#    #+#             */
/*   Updated: 2023/11/05 14:33:01 by lle-saul         ###   ########.fr       */
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
	t_list	*next;
	
	next = (*stack_a)->next;
	if (*stack_b != NULL)
	{
		(*stack_a)->next = *stack_b;
		*stack_b = *stack_a;
	}
	else
	{
		*stack_b = *stack_a;
		(*stack_b)->next = NULL;
	}
	*stack_a = next;
	ft_printf("pb\n");
}

void	pa(t_list **stack_a, t_list **stack_b)
{
	t_list	*next;

	next = (*stack_b)->next;
	if (*stack_a != NULL)
	{
		(*stack_b)->next = *stack_a;
		*stack_a = *stack_b;
	}
	else
	{
		*stack_a = *stack_b;
		(*stack_b)->next = NULL;
	}
	*stack_b = next;
	ft_printf("pa\n");
}
