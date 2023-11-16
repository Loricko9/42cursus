/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_cmd_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:06:13 by lle-saul          #+#    #+#             */
/*   Updated: 2023/11/16 14:06:13 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Checker_bonus.h"

int	ft_cmp_cmd(char *cmp, char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (cmp[i] != str[i])
			return (1);
		i++;
	}
	return (0);
}

void	do_cmd(t_lst *cmd, t_list **stack_a, t_list **stack_b)
{
	t_lst	*first;

	first = cmd;
	while (cmd != NULL)
	{
		if (ft_cmp_cmd("sa\n", cmd->str) == 0)
			sab_checker(*stack_a);
		else if (ft_cmp_cmd("sb\n", cmd->str) == 0)
			sab_checker(*stack_b);
		else if (ft_cmp_cmd("ss\n", cmd->str) == 0)
			ss_checker(*stack_a, *stack_b);
		else if (ft_cmp_cmd("ra\n", cmd->str) == 0)
			rab_checker(stack_a);
		else if (ft_cmp_cmd("rb\n", cmd->str) == 0)
			rab_checker(stack_b);
		else if (ft_cmp_cmd("rr\n", cmd->str) == 0)
			rr_checker(stack_a, stack_b);
		else if (ft_cmp_cmd("rra\n", cmd->str) == 0)
			rrab_checker(stack_a);
		else if (ft_cmp_cmd("rrb\n", cmd->str) == 0)
			rrab_checker(stack_b);
		else
			do_cmd2(cmd, first, stack_a, stack_b);
		cmd = cmd->next;
	}
	
}

void	do_cmd2(t_lst *cmd, t_lst *first, t_list **stack_a, t_list **stack_b)
{
	if (ft_cmp_cmd("rrr\n", cmd->str) == 0)
			rrr_checker(stack_a, stack_b);
	else if (ft_cmp_cmd("pa\n", cmd->str) == 0)
			pa_checker(stack_a, stack_b);
	else if (ft_cmp_cmd("pb\n", cmd->str) == 0)
			pb_checker(stack_a, stack_b);
	else
	{
		if (*stack_a)
			ft_free_lst(*stack_a);
		if (*stack_b)
			ft_free_lst(*stack_b);
		ft_free_stock(first);
		exit(ft_printf("Error\n"));
	}
}
