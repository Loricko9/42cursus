/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Swap3_cost_extrem.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 21:34:20 by lle-saul          #+#    #+#             */
/*   Updated: 2023/11/15 21:34:20 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

int	max(t_list *stack)
{
	int		max;
	t_list	*first;

	first = stack;
	max = stack->rank;
	stack = stack->next;
	while (stack != first)
	{
		if (stack->rank > max)
			max = stack->rank;
		stack = stack->next;
	}
	return (max);
}

int	min(t_list *stack)
{
	int		min;
	t_list	*first;

	first = stack;
	min = stack->rank;
	stack = stack->next;
	while (stack != first)
	{
		if (stack->rank < min)
			min = stack->rank;
		stack = stack->next;
	}
	return (min);
}

int	cost_mv_a_extremum(t_list *stack_a, int *mv, int rank, int size)
{
	int	i;

	i = 0;
	if (min(stack_a) > rank)
	{
		*mv = min_rank(stack_a, &i) - 1;
		if (sort_prox(size, (*mv) + 1) == 0)
		{
			*mv = cost_mv_a2(stack_a, min(stack_a));
		}
		return (1);
	}
	if (max(stack_a) < rank)
	{
		*mv = min_rank(stack_a, &i);
		if (sort_prox(size, (*mv) + 1) == 0)
		{
			*mv = cost_mv_a2(stack_a, min(stack_a));
		}
		return (1);
	}
	else
		return (0);
}
