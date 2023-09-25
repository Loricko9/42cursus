/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 10:55:51 by lle-saul          #+#    #+#             */
/*   Updated: 2023/09/25 10:55:51 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*temp;

	temp = lst;
	while (temp->next != NULL)
		temp = temp->next;
	return (temp);
}
