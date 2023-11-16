/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:16:57 by lle-saul          #+#    #+#             */
/*   Updated: 2023/11/16 14:16:57 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Checker_bonus.h"

void	final_check(t_list *stack_a, t_list *stack_b)
{
	if (check_order(stack_a) == 1 || stack_b != NULL)
		ft_printf("KO\n");
	else
		ft_printf("OK\n");
}

void	fill_list(int fd, t_lst **list)
{
	char	*line;

	while (1)
	{
		line = get_next_line(fd);
		if (line)
			ft_lstadd_back_chercker(list, ft_lstnew_chercker(line));
		else 
			break ;
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
	t_list		*stack_a;
	t_list		*stack_b;
	t_lst		*cmd;

	stack_b = NULL;
	stack_a = NULL;
	cmd = NULL;
	if (ac < 2)
		return (1);
	if (check_av(av) == 1)
		return (ft_printf("Error\n"));
	get_lst(av, &stack_a);
	if (!stack_a)
		return (ft_printf("Error\n"));
	get_rank(stack_a);
	ft_error(stack_a);
	fill_list(0, &cmd);
	do_cmd(cmd, &stack_a, &stack_b);
	final_check(stack_a, stack_b);
	if (stack_a)
		ft_free_lst(stack_a);
	if (stack_b)
		ft_free_lst(stack_b);
	ft_free_stock(cmd);
}
