/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Swap2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 19:32:17 by lle-saul          #+#    #+#             */
/*   Updated: 2023/11/09 19:32:17 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

int	min(t_list *stack_a, int *rank)
{
	int		i;
	int		j;
	int		min;
	t_list	*first;

	i = 1;
	j = 1;
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
		stack_a  = stack_a->next;
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
		if (min(*stack_a, &rank) <= new_size)
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
	printlst(*stack_a, *stack_b);
	if (check_order(*stack_a) == 1)
		sort_3v(stack_a);
	while (ft_lstsize(*stack_a) != size)
		pa(stack_a, stack_b);
}
