/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 14:44:30 by lle-saul          #+#    #+#             */
/*   Updated: 2023/10/23 11:29:32 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_free_stock(t_list *stock)
{
	t_list	*temp;

	while (stock != NULL)
	{
		temp = stock->next;
		free(stock->str);
		free(stock);
		stock = temp;
	}
}

t_list	*ft_lstlast(t_list *stock)
{
	if (!stock)
		return (NULL);
	while (stock->next != NULL)
		stock = stock->next;
	return (stock);
}

int	ft_get_size(t_list *stock)
{
	int	i;
	int	count;

	count = 0;
	while (stock != NULL)
	{
		i = 0;
		while (stock->str[i] != '\0')
		{
			if (stock->str[i] == '\n')
				return (count + 1);
			i++;
			count++;
		}
		stock = stock->next;
	}
	return (count);
}

int	ft_find_get_next(t_list *stock)
{
	int	i;

	if (!stock)
		return (0);
	while (stock != NULL)
	{
		i = 0;
		while (stock->str[i] != '\0')
		{
			if (stock->str[i] == '\n')
				return (1);
			i++;
		}
		stock = stock->next;
	}
	return (0);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (i);
	while (str[i] != '\0')
		i++;
	return (i);
}
