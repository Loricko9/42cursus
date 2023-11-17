/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_cmd_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:06:13 by lle-saul          #+#    #+#             */
/*   Updated: 2023/11/17 14:43:46 by lle-saul         ###   ########.fr       */
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

void	do_cmd(char *str, t_list **stack_a, t_list **stack_b)
{
	if (ft_cmp_cmd("sa\n", str) == 0)
	{
		if (ft_lstsize(*stack_a) >= 2)
			sab_checker(*stack_a);
	}
	else if (ft_cmp_cmd("sb\n", str) == 0)
	{
		if (ft_lstsize(*stack_b) >= 2)
			sab_checker(*stack_b);
	}
	else if (ft_cmp_cmd("ss\n", str) == 0)
	{
		if (ft_lstsize(*stack_b) >= 2 && ft_lstsize(*stack_a) >= 2)
			ss_checker(*stack_a, *stack_b);
	}
	else if (ft_cmp_cmd("ra\n", str) == 0)
	{
		if (ft_lstsize(*stack_a) >= 2)
			rab_checker(stack_a);
	}
	else
		do_cmd2(str, stack_a, stack_b);
}

void	do_cmd2(char *str, t_list **stack_a, t_list **stack_b)
{
	if (ft_cmp_cmd("rb\n", str) == 0)
	{
		if (ft_lstsize(*stack_b) >= 2)
			rab_checker(stack_b);
	}
	else if (ft_cmp_cmd("rr\n", str) == 0)
	{
		if (ft_lstsize(*stack_b) >= 2 && ft_lstsize(*stack_a) >= 2)
			rr_checker(stack_a, stack_b);
	}
	else if (ft_cmp_cmd("rra\n", str) == 0)
	{
		if (ft_lstsize(*stack_a) >= 2)
			rrab_checker(stack_a);
	}
	else if (ft_cmp_cmd("rrb\n", str) == 0)
	{
		if (ft_lstsize(*stack_b) >= 2)
			rrab_checker(stack_b);
	}
	else
		do_cmd3(str, stack_a, stack_b);
}

void	do_cmd3(char *str, t_list **stack_a, t_list **stack_b)
{
	if (ft_cmp_cmd("rrr\n", str) == 0)
	{
		if (ft_lstsize(*stack_b) >= 2 && ft_lstsize(*stack_a) >= 2)
			rrr_checker(stack_a, stack_b);
	}
	else if (ft_cmp_cmd("pa\n", str) == 0)
	{
		if (*stack_b != NULL)
			pa_checker(stack_a, stack_b);
	}
	else if (ft_cmp_cmd("pb\n", str) == 0)
	{
		if (*stack_a != NULL)
			pb_checker(stack_a, stack_b);
	}
	else
	{
		if (*stack_a)
			ft_free_lst(*stack_a);
		if (*stack_b)
			ft_free_lst(*stack_b);
		free(str);
		get_next_line(-1);
		exit(ft_printf("Error\n"));
	}
}
