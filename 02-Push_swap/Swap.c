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

void	swap(t_list **stack_a, t_list **stack_b)
{
	while (check_order(*stack_a) != -1 && (*stack_a)->next != NULL)
	{
		if (check_order(*stack_a) == 1)
			sab(*stack_a, 1);
		while (min(*stack_a) >= 1)
		{
			if (near(min(*stack_a), ft_lstsize(*stack_a)) == 1)
				rab(*stack_a, 1);
			else if (near(min(*stack_a), ft_lstsize(*stack_a)) == 0)
				rrab(*stack_a, 1);
		}
		if (check_order(*stack_a) != -1)
			pb(stack_a, stack_b);
	}
	while (*stack_b != NULL)
		pa(stack_a, stack_b);
}

int	near(int min, int size)
{
	if (size % 2 == 0 && size / 2 <= min)
		return (1);
	else if (size % 2 == 1 && size / 2 <= min)
		return (1);
	else if (size % 2 == 0 && size / 2 > min)
		return (0);
	else if (size % 2 == 1 && size / 2 > min)
		return (0);
	return (0);
}

int	min(t_list *stack)
{
	int	first;
	int i;
	int	min;

	first = stack->nb;
	i = 1;
	min = 0; 
	stack = stack->next;
	while (stack != NULL)
	{
		if (first > stack->nb)
			min = i;
		stack = stack->next;
		i++;
	}
	return (min);
}
