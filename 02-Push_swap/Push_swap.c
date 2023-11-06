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

int	ft_atoi(const char *nptr)
{
	int	i;
	int	nb;
	int	sign;

	i = 0;
	nb = 0;
	sign = 1;
	while ((nptr[i] >= '\t' && nptr[i] <= '\r') || nptr[i] == 32)
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		nb = nb * 10 + nptr[i] - 48;
		i++;
	}
	return (nb * sign);
}



void	get_lst(char **av, t_list **stack_a)
{
	t_list	*temp;
	int		i;
	int		j;

	j = 1;
	while (av[j] != NULL)
	{
		i = 0;
		while ((av[j][i] >= '\t' && av[j][i] <= '\r') || av[j][i] == 32)
			i++;
		while (av[j][i] != '\0')
		{
			while ((av[j][i] >= '\t' && av[j][i] <= '\r') || av[j][i] == 32)
				i++;
			temp = ft_lstnew(ft_atoi(av[j] + i));
			if (!temp)
			{
				ft_free_lst(*stack_a);
				return ;
			}
			ft_lstadd_back(stack_a, temp);
			while ((av[j][i] >= '0' && av[j][i] <= '9') || av[j][i] == '+' || av[j][i] == '-')
				i++;
			while ((av[j][i] >= '\t' && av[j][i] <= '\r') || av[j][i] == 32)
				i++;
		}
		j++;
	}
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_b = NULL;
	stack_a = NULL;
	if (ac < 2)
		return(ft_printf("Error : missing arg\n"));
	if (check_av(av) == 1)
		return(ft_printf("Error : invalid character\n"));
	get_lst(av, &stack_a);
	if (!stack_a)
		return (ft_printf("Error : MALLOC error\n"));
	if (check_double(stack_a) == 1)
		return (ft_printf("Error : Double nb detected\n"));
	printlst(stack_a, stack_b);
	swap(&stack_a, &stack_b);
	printlst(stack_a, stack_b);
	ft_free_lst(stack_a);
}

void	printlst(t_list *stack_a, t_list *stack_b)
{
	while (stack_a != NULL || stack_b != NULL)
	{
		if (stack_a)
			ft_printf("%d ", stack_a->nb);
		else
			ft_printf("  ");
		if (stack_b)
			ft_printf("%d\n", stack_b->nb);
		else
			ft_printf(" \n");
		if (stack_a != NULL)
			stack_a = stack_a->next;
		if (stack_b != NULL)
			stack_b = stack_b->next;
	}
	ft_printf("_ _\na b\n");
}
