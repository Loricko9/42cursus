/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 10:39:48 by lle-saul          #+#    #+#             */
/*   Updated: 2023/09/25 10:39:48 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdlib.h>

int	ft_lstsize(t_list *lst)
{
	int		size;
	t_list	*temp;

	size = 1;
	temp = lst;
	while (temp->next != NULL)
	{
		size++;
		temp = temp->next;
	}
	return (size);
}
