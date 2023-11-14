/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Swap3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 17:01:23 by lle-saul          #+#    #+#             */
/*   Updated: 2023/11/14 17:01:23 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

int	max(t_list *stack_a, int *rank)
{
	int		i;
	int		j;
	int		max;
	t_list	*first;

	i = 1;
	j = 1;
	first = stack_a;
	max = stack_a->rank;
	stack_a = stack_a->next;
	while (stack_a != first)
	{
		if (max < stack_a->rank)
		{
			i = j;
			max = stack_a->rank;
		}
		j++;
		stack_a  = stack_a->next;
	}
	*rank = max;
	return (i);
}

void	swap_ph3(t_list **stack_a, t_list **stack_b, int size)
{
	int	new_size;
	int	rank;

	new_size = ft_lstsize(*stack_b);
	while (new_size != size)
	{ 
		if (max(*stack_b, &rank) <= (new_size / 2))
		{
			while ((*stack_b)->rank != rank)
				rab(stack_a, 1);
		}
		else
		{
			while ((*stack_b)->rank != rank)
				rrab(stack_b, 1);
		}
		pa(stack_a, stack_b);
		new_size = ft_lstsize(*stack_a);
	}
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
