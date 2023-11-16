/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Swap3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 17:01:23 by lle-saul          #+#    #+#             */
/*   Updated: 2023/11/15 14:52:26 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

void	swap_ph2(t_list **stack_a, t_list **stack_b)
{
	int	mv_a;
	int	mv_b;
	
	mv_a = 0;
	mv_b = 0;
	while (*stack_b != NULL)
	{
		get_cost(stack_a, stack_b);
		get_lowest_cost(*stack_b, &mv_a, &mv_b, ft_lstsize(*stack_b));
		//printlst(*stack_a, *stack_b);
		do_swap(stack_a, stack_b, mv_a, mv_b);
	}
}

void	get_lowest_cost2(int mv_a, int mv_b, int *total)
{
	while (mv_a < 0 && mv_b < 0)
	{
		mv_a++;
		mv_b++;
		++*total;
	}
	while (mv_a > 0 && mv_b > 0)
	{
		mv_a--;
		mv_b--;
		++*total;
	}
	while (mv_a < 0)
	{
		mv_a++;
		++*total;
	}
	while (mv_b < 0)
	{
		mv_b++;
		++*total;
	}
	get_lowest_cost3(&mv_a, &mv_b, total);
}

void	get_lowest_cost(t_list *stack_b, int *mv_a, int *mv_b, int size)
{
	int	max;
	int	total;
	int	temp_mv_a;
	int	temp_mv_b;

	max = 2000000;
	while (size > 0)
	{
		total = 0;
		temp_mv_a = stack_b->mv_a;
		temp_mv_b = stack_b->mv_b;	
		get_lowest_cost2(temp_mv_a, temp_mv_b, &total);
		if (total <= max)
		{
			*mv_a = stack_b->mv_a;
			*mv_b = stack_b->mv_b;
			max = total;
		}
		size--;
		stack_b = stack_b->next;
		//ft_printf("max : %d\ntotal : %d\n", max, total);
	}
}

void	do_swap(t_list **stack_a, t_list **stack_b, int mv_a, int mv_b)
{
	while (mv_a < 0 && mv_b < 0)
	{
		rrr(stack_a, stack_b);
		mv_a++;
		mv_b++;
	}
	while (mv_a > 0 && mv_b > 0)
	{
		rr(stack_a, stack_b);
		mv_a--;
		mv_b--;
	}
	while (mv_a < 0)
	{
		rrab(stack_a, 1);
		mv_a++;
	}
	while (mv_b < 0)
	{
		rrab(stack_b, 0);
		mv_b++;
	}
	do_swap2(stack_a, stack_b, &mv_a, &mv_b);
	pa(stack_a, stack_b);
}

void	do_swap2(t_list **stack_a, t_list **stack_b, int *mv_a, int *mv_b)
{
	while (*mv_a > 0)
	{
		rab(stack_a, 1);
		--*mv_a;
	}
	while (*mv_b > 0)
	{
		rab(stack_b, 0);
		--*mv_b;
	}
}
