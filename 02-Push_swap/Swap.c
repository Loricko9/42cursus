/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 13:04:07 by lle-saul          #+#    #+#             */
/*   Updated: 2023/11/06 13:04:07 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

void	swap(t_list **stack_a, t_list **stack_b, int size)
{
	int		tier;
	int		div;
	
	div = get_div(size);
	tier = (size / div);
	swap_ph1(stack_a, stack_b, size, tier);
	little_swap(stack_a, stack_b, ft_lstsize(*stack_a));
	//printlst(*stack_a, *stack_b);
	swap_ph2(stack_a, stack_b, tier);
}


void	swap_ph1(t_list **stack_a, t_list **stack_b, int size, int tier)
{
	int		j;
	int		div;

	j = 0;
	div = tier;
	while (tier <= (size - div))
	{
		while (j != tier)
		{
			if ((*stack_a)->rank <= tier)
			{
				pb(stack_a, stack_b);
				j++;
			}
			else
				rab(stack_a, 1);
		}
		tier = tier + div;
	}
}

void	sort_2v(t_list *stack)
{
	t_list	*next;

	next = stack->next;
	if (next->rank < stack->rank)
		sab(stack, 1);
}

void	sort_3v(t_list **stack)
{
	t_list	*prec;
	t_list	*next;

	prec = (*stack)->prec;
	next = (*stack)->next;
	if (prec->rank > (*stack)->rank && next->rank < (*stack)->rank
			&& next->rank < prec->rank)
		sab(*stack, 1);
	else if ((*stack)->rank > prec->rank && (*stack)->rank > next->rank
			&& next->rank > prec->rank)
	{
		sab(*stack, 1);
		rrab(stack, 1);
	}
	else if ((*stack)->rank > prec->rank && (*stack)->rank > next->rank
			&& next->rank < prec->rank)
		rab(stack, 1);
	else
		sort_3v2(stack, prec, next);
}

void	sort_3v2(t_list **stack, t_list *prec, t_list *next)
{
	if ((*stack)->rank < next->rank && (*stack)->rank < prec->rank
			&& next->rank > prec->rank)
	{
		sab(*stack, 1);
		rab(stack, 1);
	}
	else if (prec->rank < (*stack)->rank && next->rank > (*stack)->rank
			&& next->rank > prec->rank)
		rrab(stack, 1);
}
