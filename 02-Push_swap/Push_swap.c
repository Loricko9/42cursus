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
	if (ac < 2 || check_av(av) == 1)
		return(ft_printf("Error\n"));
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
		ft_printf("%d %d", stack_a->nb, stack_a->rank);
		first_a =stack_a;
		stack_a = stack_a->next;
	}
	else
		ft_printf("  ");
	if (stack_b)
	{
		ft_printf("%d %d\n", stack_b->nb, stack_b->rank);
		first_b = stack_b;
		stack_b = stack_b->next;
	}
	else
		ft_printf(" \n");
	while ((stack_a != NULL && stack_a != first_a) || (stack_b != NULL && stack_b != first_b))
	{
		if (stack_a)
			ft_printf("%d %d", stack_a->nb, stack_a->rank);
		else
			ft_printf("  ");
		if (stack_b)
			ft_printf("%d %d\n", stack_b->nb, stack_b->rank);
		else
			ft_printf(" \n");
		if (stack_a != NULL)
			stack_a = stack_a->next;
		if (stack_b != NULL)
			stack_b = stack_b->next;
	}
	ft_printf("_ _\na b\n");
}
