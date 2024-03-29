/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 18:27:00 by lle-saul          #+#    #+#             */
/*   Updated: 2023/11/17 15:03:21 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

void	ft_ajust(t_list **stack_a, int size)
{
	int	rank;

	rank = 1;
	if (sort_prox(size, min_rank(*stack_a, &rank)) == 1)
	{
		while ((*stack_a)->rank != rank)
			rab(stack_a, 1);
	}
	else
	{
		while ((*stack_a)->rank != rank)
			rrab(stack_a, 1);
	}
}

void	ft_error(t_list *stack_a)
{
	if (stack_a->next == NULL)
	{
		ft_free_lst(stack_a);
		exit(1);
	}
	if (check_double(stack_a) == 1)
		exit(ft_printf("Error\n"));
	if (check_order(stack_a) == 0)
	{
		ft_free_lst(stack_a);
		exit(1);
	}
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_b = NULL;
	stack_a = NULL;
	if (ac < 2)
		return (1);
	if (check_av(av) == 1)
		return (ft_printf("Error\n"));
	get_lst(av, &stack_a);
	if (!stack_a)
		return (ft_printf("Error\n"));
	if (ft_lstsize(stack_a) == 1)
		return (ft_free_lst(stack_a));
	get_rank(stack_a);
	ft_error(stack_a);
	if (ft_lstsize(stack_a) == 2)
		sort_2v(stack_a);
	else if (ft_lstsize(stack_a) <= 12)
		little_swap(&stack_a, &stack_b, ft_lstsize(stack_a));
	else
		swap(&stack_a, &stack_b, ft_lstsize(stack_a));
	ft_free_lst(stack_a);
}

void	printlst(t_list *stack_a, t_list *stack_b)
{
	t_list	*first_a;
	t_list	*first_b;
	
	ft_printf("-----------------------------------------------\n");
	if (stack_a)
	{
		ft_printf("%d (%d)(%d)  ||", stack_a->rank, stack_a->mv_a, stack_a->mv_b);
		first_a =stack_a;
		stack_a = stack_a->next;
	}
	else
		ft_printf("           ||");
	if (stack_b)
	{
		ft_printf("   %d (%d)(%d)\n", stack_b->rank, stack_b->mv_a, stack_b->mv_b);
		first_b = stack_b;
		stack_b = stack_b->next;
	}
	else
		ft_printf(" \n");
	while ((stack_a != NULL && stack_a != first_a) || (stack_b != NULL && stack_b != first_b))
	{
		if (stack_a && stack_a != first_a)
			ft_printf("%d (%d)(%d)  ||", stack_a->rank, stack_a->mv_a, stack_a->mv_b);
		else
			ft_printf("           ||");
		if (stack_b && stack_b != first_b)
			ft_printf("   %d (%d)(%d)\n", stack_b->rank, stack_b->mv_a, stack_b->mv_b);
		else
			ft_printf(" \n");
		if (stack_a != NULL && stack_a != first_a)
			stack_a = stack_a->next;
		if (stack_b != NULL && stack_b != first_b)
			stack_b = stack_b->next;
	}
}
