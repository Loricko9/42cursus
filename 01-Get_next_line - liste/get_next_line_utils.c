/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 13:48:23 by lle-saul          #+#    #+#             */
/*   Updated: 2023/10/20 13:48:23 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (new)
	{
		if (!*lst)
		{
			*lst = new;
			return ;
		}
		last = *lst;
		while (last->next != NULL)
			last = last->next;
		last->next = new;
	}
}

t_list	*ft_lstnew(char *str, int re)
{
	t_list	*list;
	int 	i;

	list = malloc(sizeof(*list));
	if (!list)
		return (NULL);
	list->str = malloc(sizeof(char) * re + 1);
	if (!list->str)
		return (NULL);
	i = 0;
	while (str[i] != '\0')
	{
		list->str[i] = str[i];
		i++;
	}
	list->str[i] = '\0';
	list->next = NULL;
	return (list);
}

int	ft_strchr(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '\0')
		return (-1);
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_strcat(t_list *lst)
{
	char	*new;
	int		len;
	int		i;

	len = 0;	
	while (lst->str[len] != '\0')
		len++;
	new = malloc(sizeof(char) * (len - ft_strchr(lst->str)));
	len = ft_strchr(lst->str) + 1;
	i = 0;
	while (lst->str[len] != '\0')
		new[i++] = lst->str[len++];
	new[i++] = '\0';
	free(lst->str);
	return (new);
}

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (lst)
	{
		if (del)
			del(lst->str);
		free(lst);
	}
}

