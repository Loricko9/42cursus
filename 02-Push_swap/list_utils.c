/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 19:01:29 by lle-saul          #+#    #+#             */
/*   Updated: 2023/11/04 19:01:29 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*first;

	i = 1;
	if (!lst)
		return (0);
	if (lst->next == NULL)
		return (1);
	first = lst;
	lst = lst->next;
	while (lst != first)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

t_list	*ft_lstnew(int nb)
{
	t_list	*new;

	new = malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->nb = nb;
	new->rank = -1;
	new->mv_a = 0;
	new->mv_b = 0;
	new->next = NULL;
	new->prec = NULL;
	return (new);
}

void	ft_lstadd_back(t_list **lst, t_list	*new)
{
	t_list			*prec;

	if (new)
	{
		if (!*lst)
		{
			*lst = new;
			return ;
		}
		prec = *lst;
		if (prec->next != NULL)
			prec = prec->next;
		while (prec->next != *lst && prec->next != NULL)
			prec = prec->next;
		new->next = *lst;
		new->prec = prec;
		prec->next = new;
		(*lst)->prec = new;
	}
}

t_list	*ft_lstlast(t_list *lst)
{
	if (lst)
	{
		while (lst->next != NULL)
			lst = lst->next;
		return (lst);
	}
	return (0);
}

void	ft_free_lst(t_list *lst)
{
	t_list	*temp;
	int		size;

	size = ft_lstsize(lst);
	while (size > 0)
	{
		temp = lst->next;
		free(lst);
		lst = NULL;
		lst = temp;
		size--;
	}
}
