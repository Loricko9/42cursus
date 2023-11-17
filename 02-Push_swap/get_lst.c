/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_lst.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 13:07:03 by lle-saul          #+#    #+#             */
/*   Updated: 2023/11/16 15:24:52 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

long long	ft_atoi(const char *nptr)
{
	int			i;
	long long	nb;
	int			sign;

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

int	create_node(int i, int j, char **av, t_list **stack_a)
{
	t_list		*temp;
	long long	nb;

	nb = ft_atoi(av[j] + i);
	if (nb > 2147483647 || nb < -2147483648)
	{
		ft_free_lst(*stack_a);
		*stack_a = NULL;
		return (1);
	}
	temp = ft_lstnew((int)nb);
	if (!temp)
	{
		ft_free_lst(*stack_a);
		*stack_a = NULL;
		return (1);
	}
	ft_lstadd_back(stack_a, temp);
	return (0);
}

void	get_lst(char **av, t_list **stack_a)
{
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
			if (create_node(i, j, av, stack_a) == 1)
				return ;
			while ((av[j][i] >= '0' && av[j][i] <= '9')
					|| av[j][i] == '+' || av[j][i] == '-')
				i++;
			while ((av[j][i] >= '\t' && av[j][i] <= '\r') || av[j][i] == 32)
				i++;
		}
		j++;
	}
}

void	get_rank(t_list *stack_a)
{
	int		rank;
	int		max;
	t_list	*temp;
	t_list	*first;

	rank = ft_lstsize(stack_a);
	first = stack_a;
	while (rank != 0)
	{
		while (stack_a->rank != -1)
			stack_a = stack_a->next;
		max = stack_a->nb;
		temp = stack_a;
		stack_a = stack_a->next;
		while (stack_a != first)
		{
			get_rank2(&stack_a, &temp, &max);
			stack_a = stack_a->next;
		}
		temp->rank = rank;
		stack_a = first;
		rank--;
	}
}

void	get_rank2(t_list **stack_a, t_list **temp, int *max)
{
	if ((*stack_a)->nb > *max && (*stack_a)->rank == -1)
	{
		*max = (*stack_a)->nb;
		*temp = *stack_a;
	}
}
