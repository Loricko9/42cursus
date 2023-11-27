/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sort2_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 13:57:02 by lle-saul          #+#    #+#             */
/*   Updated: 2023/11/16 15:25:12 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Checker_bonus.h"

void	rab_checker(t_list **stack)
{
	*stack = (*stack)->next;
}

void	rr_checker(t_list **stack_a, t_list **stack_b)
{
	rab_checker(stack_a);
	rab_checker(stack_b);
}

void	rrab_checker(t_list **stack)
{
	*stack = (*stack)->prec;
}

void	rrr_checker(t_list **stack_a, t_list **stack_b)
{
	rrab_checker(stack_a);
	rrab_checker(stack_b);
}
