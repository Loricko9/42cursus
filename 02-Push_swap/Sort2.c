/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 15:38:40 by lle-saul          #+#    #+#             */
/*   Updated: 2023/11/05 15:38:40 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

void	rab(t_list *stack, int a)
{
	t_list	*next;
	int		first;

	first = stack->nb;
	next = stack->next;
	while (next != NULL)
	{
		stack->nb = next->nb;
		stack = stack->next;
		next = stack->next;
	}
	stack->nb = first;
	if (a == 1)
		ft_printf("ra\n");
	if (a == 0)
		ft_printf("rb\n");
}

void	rr(t_list *stack_a, t_list *stack_b)
{
	rab(stack_a, 2);
	rab(stack_b, 2);
	ft_printf("rr\n");
}

void	rev_i(int *i)
{
	if (*i == 1)
		*i = 0;
	else if (*i == 0)
		*i = 1;
}

void	rrab(t_list *stack, int a)
{
	t_list	*first;
	int 	temp[2];
	int		i;

	first = stack;
	i = 1;
	temp[0] = stack->nb;
	stack = stack->next;
	while (stack != NULL)
	{
		temp[i] = stack->nb;
		rev_i(&i);
		stack->nb = temp[i];
		stack = stack->next;
	}
	rev_i(&i);
	first->nb = temp[i];
	if (a == 1)
		ft_printf("rra\n");
	if (a == 0)
		ft_printf("rrb\n");
}

void	rrr(t_list *stack_a, t_list *stack_b)
{
	rrab(stack_a, 2);
	rrab(stack_b, 2);
	ft_printf("rrr\n");
}
