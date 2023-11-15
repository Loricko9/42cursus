/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Swap3_cost.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 17:59:14 by lle-saul          #+#    #+#             */
/*   Updated: 2023/11/15 17:59:14 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

int	cost_mv_b(t_list *stack_b, int size, int niv, int rank)
{
	int	mv;

	mv = 0;
	if (sort_prox(size, niv) == 1)
	{
		while (stack_b->rank != rank)
		{
			mv++;
			stack_b = stack_b->next;
		}
	}
	else
	{
		while (stack_b->rank != rank)
		{
			mv--;
			stack_b = stack_b->prec;
		}
	}
	return (mv);
}

int	cost_mv_a(t_list *stack_a, int size, int rank)
{
	int		mv;
	t_list	*prec;
	t_list	*first;

	mv = 0;
	prec = stack_a->prec;
	first = stack_a;
	//ft_printf("prec : %d\nact : %d\nrank : %d\n", prec->rank, stack_a->rank, rank);
	if (cost_mv_a_extremum(stack_a, &mv, rank, size) == 1)
		return (mv);
	while (1)
	{
		if (prec->rank < rank && stack_a->rank > rank)
			break ;
		mv++;
		stack_a = stack_a->next;
		prec = prec->next;
	}
	if (sort_prox(size, mv + 1) == 1)
		return (mv);
	else
		return (cost_mv_a2(first, stack_a->rank));
}

int	cost_mv_a2(t_list *temp, int rank)
{
	int mv;

	mv = 0;
	while (rank != temp->rank)
	{
		temp = temp->prec;
		mv--;
	}
	return (mv);
}

void	get_cost(t_list **stack_a, t_list **stack_b)
{
	int		rank;
	t_list	*temp;

	temp = *stack_b;
	rank = 1;
	while (rank <= ft_lstsize(*stack_b))
	{
		temp->mv_b = cost_mv_b(*stack_b, ft_lstsize(*stack_b), rank, temp->rank);
		temp->mv_a = cost_mv_a(*stack_a, ft_lstsize(*stack_a), temp->rank);
		rank++;
		temp = temp->next;
	}
}

void	get_lowest_cost3(int *mv_a, int *mv_b, int *total)
{
	while (*mv_a > 0)
	{
		--*mv_a;
		++*total;
	}
	while (*mv_b > 0)
	{
		--*mv_b;
		++*total;
	}
}
