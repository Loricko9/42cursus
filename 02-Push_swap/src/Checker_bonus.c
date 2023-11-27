/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 19:04:25 by lle-saul          #+#    #+#             */
/*   Updated: 2023/11/17 15:22:34 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Checker_bonus.h"

void	final_check(t_list *stack_a, t_list *stack_b)
{
	if (stack_b != NULL || check_order(stack_a) == 1)
		ft_printf("KO\n");
	else
		ft_printf("OK\n");
}

void	get_cmd(t_list **stack_a, t_list **stack_b)
{
	char	*line;

	while (1)
	{
		line = get_next_line(0);
		if (line == NULL)
			break ;
		do_cmd(line, stack_a, stack_b);
		free(line);
	}
	final_check(*stack_a, *stack_b);
}

int	main(int ac, char **av)
{
	t_list		*stack_a;
	t_list		*stack_b;

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
		stack_a->rank = 1;
	else
	{
		get_rank(stack_a);
		if (check_double(stack_a) == 1)
			return (ft_printf("Error\n"));
	}
	get_cmd(&stack_a, &stack_b);
	if (stack_a)
		ft_free_lst(stack_a);
	if (stack_b)
		ft_free_lst(stack_b);
}
