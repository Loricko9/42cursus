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

int	get_div(int size)
{
	if (size <= 200)
		return (4);
	else
		return (8);
}

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
		if (sort_prox(new_size, min(*stack_a, &rank)) == 1)
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

int	find_rank(t_list *stack_b, int rank, int tier_min)
{
	int		i;
	t_list	*first;

	i = 0;
	first = stack_b;
	while (1)
	{
		if (stack_b->rank == rank)
			return (i);
		stack_b = stack_b->next;
		i++;
		if (stack_b->rank <= tier_min || sort_prox(ft_lstsize(stack_b), i) == 0)
			break ;
	}
	i = 0;
	stack_b = first;
	while (1)
	{
		if (stack_b->rank == rank)
			return (i);
		stack_b = stack_b->prec;
		i--;
	}
}

void	swap_ph2(t_list **stack_a, t_list **stack_b, int tier)
{
	int	rank;
	int act_tier;

	rank = (*stack_a)->rank - 1;
	act_tier = rank - tier;
	while (rank != 0)
	{
		if (act_tier == rank)
			act_tier = act_tier - tier;
		if (find_rank(*stack_b, rank, act_tier) == 1)
			sab(*stack_b, 0);
		else if (find_rank(*stack_b, rank, act_tier) > 0)
		{
			while ((*stack_b)->rank != rank)
				rab(stack_b, 0);
		}
		else
		{
			while ((*stack_b)->rank != rank)
				rrab(stack_b, 0);
		}
		pa(stack_a, stack_b);
		rank--;
	}
}
