/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Swap2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 19:32:17 by lle-saul          #+#    #+#             */
/*   Updated: 2023/11/16 15:28:51 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

int	swap_ph1_move(t_list **stack_a, t_list **stack_b, int tier1, int tier2)
{
	if ((*stack_a)->rank <= tier1)
	{
		pb(stack_a, stack_b);
		if ((*stack_a)->rank > tier2 && (*stack_b)->next != NULL)
			rr(stack_a, stack_b);
		else if ((*stack_b)->next != NULL)
			rab(stack_b, 0);
		return (1);
	}
	else if ((*stack_a)->rank <= tier2)
	{
		pb(stack_a, stack_b);
		return (1);
	}
	else
	{
		rab(stack_a, 1);
		return (0);
	}
}

int	min_rank(t_list *stack_a, int *rank)
{
	int		i;
	int		j;
	int		min;
	t_list	*first;

	i = 1;
	j = 2;
	first = stack_a;
	min = stack_a->rank;
	stack_a = stack_a->next;
	while (stack_a != first)
	{
		if (min > stack_a->rank)
		{
			i = j;
			min = stack_a->rank;
		}
		j++;
		stack_a = stack_a->next;
	}
	*rank = min;
	return (i);
}

void	little_swap(t_list **stack_a, t_list **stack_b, int size)
{
	int	new_size;
	int	rank;

	new_size = size;
	while (new_size != 3 && check_order(*stack_a) == 1)
	{
		if (sort_prox(new_size, min_rank(*stack_a, &rank)) == 1)
		{
			while ((*stack_a)->rank != rank)
				rab(stack_a, 1);
		}
		else
		{
			while ((*stack_a)->rank != rank)
				rrab(stack_a, 1);
		}
		pb(stack_a, stack_b);
		new_size = ft_lstsize(*stack_a);
	}
	if (check_order(*stack_a) == 1)
		sort_3v(stack_a);
	while (ft_lstsize(*stack_a) != size)
		pa(stack_a, stack_b);
}

int	get_div(int size)
{
	if (size <= 200)
		return (4);
	else
		return (8);
}

int	sort_prox(int size, int rank)
{
	if (size % 2 == 0)
	{
		if (rank <= (size / 2))
			return (1);
		else
			return (0);
	}
	else
	{
		if (rank <= (size / 2) + 1)
			return (1);
		else
			return (0);
	}
}
