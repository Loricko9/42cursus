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

void	rab(t_list **stack, int a)
{
	*stack = (*stack)->next;
	if (a == 1)
		ft_printf("ra\n");
	if (a == 0)
		ft_printf("rb\n");
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	rab(stack_a, 2);
	rab(stack_b, 2);
	ft_printf("rr\n");
}

void	rrab(t_list **stack, int a)
{
	*stack = (*stack)->prec;
	if (a == 1)
		ft_printf("rra\n");
	if (a == 0)
		ft_printf("rrb\n");
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	rrab(stack_a, 2);
	rrab(stack_b, 2);
	ft_printf("rrr\n");
}
