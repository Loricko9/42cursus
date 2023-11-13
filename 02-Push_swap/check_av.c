/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_av.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 17:57:36 by lle-saul          #+#    #+#             */
/*   Updated: 2023/11/05 17:57:36 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

int	check_line(char *str)
{
	int	i;
	int	trig;

	i = 0;
	trig = 0;
	while (str[i] != '\0')
	{
		if (str[i] != '+' && str[i] != '-' && str[i] != 32 && (str[i] < '0'
				|| str[i] > '9') && (str[i] < '\t' || str[i] > '\r'))
			return (1);
		else if (trig == 0 && (str[i] == '+' || str[i] == '-'))
			trig = 1;
		else if (trig == 0 && (str[i] >= '0' && str[i] <= '9'))
			trig = 1;
		else if (trig == 1 && ((str[i] >= '\t' && str[i] <= '\r')
				|| str[i] == 32))
			trig = 0;
		else if (trig == 1 && (str[i] < '0' || str[i] > '9'))
			return (1);
		i++;
	}
	return (0);
}

int	check_av(char **av)
{
	int	j;

	j = 1;
	while (av[j] != NULL)
	{
		if (check_line(av[j]) == 1)
			return (1);
		j++;
	}
	return (0);
}

int	check_double(t_list *stock)
{
	t_list	*temp;
	t_list	*last;
	t_list	*first;

	last = stock->prec;
	first = stock;
	while (stock != last)
	{
		temp = stock->next;
		while (temp != first)
		{
			if (stock->nb == temp->nb)
			{
				ft_free_lst(stock);
				return (1);
			}
			temp = temp->next;
		}
		stock = stock->next;
	}
	return (0);
}

int	check_order(t_list *stack_a)
{
	t_list	*next;
	t_list	*first;

	next = stack_a->next;
	first = stack_a;
	while (next != first)
	{
		if (stack_a->rank > next->rank)
			return (1);
		stack_a = stack_a->next;
		next = next->next;
	}
	return (0);
}
