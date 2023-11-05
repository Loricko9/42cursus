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

int	check_av(char **av)
{
	int	i;
	int j;

	j = 1;
	while (av[j] != NULL)
	{
		i = 0;
		while (av[j][i] != '\0')
		{
			if ((av[j][i] == '-' || av[j][i] == '+') && i == 0)
			{
				i++;
				continue;
			}
			if (av[j][i] < 48 || av[j][i] > 57)
				return (1);
			i++;
		}
		j++;
	}
	return (0);
}

int	check_double(t_list *stock)
{
	t_list	*temp;

	while (stock != NULL)
	{
		temp = stock->next;
		while (temp != NULL)
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
