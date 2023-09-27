/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 11:31:21 by lle-saul          #+#    #+#             */
/*   Updated: 2023/09/26 11:31:21 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*list;
	t_list	*temp;
	t_list	*first;
	int		size;

	if (!lst || !f || !del)
		return (NULL);
	size = ft_lstsize(lst);
	temp = NULL;
	first = NULL;
	while (size > 0)
	{
		list = ft_lstnew(f(lst->content));
		if (!list)
			return (NULL);
		if (first == NULL)
			list = first;
		list->next = temp;
		*temp = *list;
		f(list->content);
		size--;
	}
	list->next = NULL;
	return (first);
}
