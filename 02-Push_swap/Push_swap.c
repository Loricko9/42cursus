/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 18:27:00 by lle-saul          #+#    #+#             */
/*   Updated: 2023/11/04 18:27:00 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_b = NULL;
	stack_a = NULL;
	if (ac < 2 || check_av(av) == 1)
		return (ft_printf("Error\n"));
	get_lst(av, &stack_a);
	if (!stack_a)
		return (ft_printf("Error\n"));
	if (stack_a->next == NULL)
	{
		ft_free_lst(stack_a);
		return (1);
	}
	if (check_double(stack_a) == 1)
		return (ft_printf("Error\n"));
	printlst(stack_a, stack_b);
	get_rank(stack_a);
	rab(&stack_a, 0);
	printlst(stack_a, stack_b);
	rab(&stack_a, 0);
	printlst(stack_a, stack_b);
	rrab(&stack_a, 0);
	printlst(stack_a, stack_b);
	rrab(&stack_a, 0);
	printlst(stack_a, stack_b);
	//swap(&stack_a, &stack_b);
	//printlst(stack_a, stack_b);
	ft_free_lst(stack_a);
}

void	printlst(t_list *stack_a, t_list *stack_b)
{
	t_list	*first_a;
	t_list	*first_b;
	
	if (stack_a)
	{
		ft_printf("%d --%d-- ", stack_a->nb, stack_a->rank);
		first_a =stack_a;
		stack_a = stack_a->next;
	}
	else
		ft_printf("  ");
	if (stack_b)
	{
		ft_printf("%d --%d--\n", stack_b->nb, stack_b->rank);
		first_b = stack_b;
		stack_b = stack_b->next;
	}
	else
		ft_printf(" \n");
	while ((stack_a != NULL && stack_a != first_a) || (stack_b != NULL && stack_b != first_b))
	{
		if (stack_a)
			ft_printf("%d --%d-- ", stack_a->nb, stack_a->rank);
		else
			ft_printf("  ");
		if (stack_b)
			ft_printf("%d --%d--\n", stack_b->nb, stack_b->rank);
		else
			ft_printf(" \n");
		if (stack_a != NULL)
			stack_a = stack_a->next;
		if (stack_b != NULL)
			stack_b = stack_b->next;
	}
}
