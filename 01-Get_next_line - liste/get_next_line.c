/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 13:47:49 by lle-saul          #+#    #+#             */
/*   Updated: 2023/10/20 13:47:49 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	print(t_list *lst)
{
	while (lst != NULL)
	{
		printf("lst : %s\n", lst->str);
		lst = lst->next;
	}
}

void	ft_cleastr(t_list **lst)
{
	t_list	*next;

	while (*lst != NULL)
	{
		next = (*lst)->next;
		if (ft_strchr((*lst)->str) < 0)
		{
			ft_lstdelone(*lst, free);
		}
		else if ((*lst)->str[ft_strchr((*lst)->str) + 1] == '\0')
		{
			ft_lstdelone(*lst, free);
			return ;
		}
		else if (ft_strchr((*lst)->str) >= 0)
		{		
			(*lst)->str = ft_strcat(*lst);
			return ;
		}
		*lst = next;
	}
}

int	ft_find(t_list *lst)
{
	int i;
	int count;

	if (!lst)
		return (-1);
	count = 1;
	while (lst != NULL)
	{
		i = 0;
		while (lst->str[i] != '\0')
		{
			if (lst->str[i] == '\n')
				return (count);
			i++;
			count++;
		}
		lst = lst->next;
	}
	return (count);
}

t_list	*ft_read(int fd, t_list *lst)
{
	char	*buff;
	int		re;

	buff = malloc(sizeof(char) * BUFFER_SIZE + 1);
	re = BUFFER_SIZE;
	buff[0] = '\0';
	while (re == BUFFER_SIZE && ft_strchr(buff) < 0)
	{
		re = read(fd, buff, BUFFER_SIZE);
		if (re < 0)
			return (NULL);
		buff[re] = '\0';
		ft_lstadd_back(&lst, ft_lstnew(buff, re));
	}
	free(buff);
	return (lst);
}

char	*ft_line(t_list *lst, t_list *first)
{
	char	*line;
	int		i;
	int		count;

	count = 0;
	line = malloc(sizeof(char) * ft_find(first) +1);
	if (!line)
		return(NULL);
	while (lst != NULL && count < ft_find(first))
	{
		i = 0;
		while (lst->str[i] != '\0' && count < ft_find(first))
			line[count++] = lst->str[i++];
		lst = lst->next;
	}
	line[count++] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	static t_list	*lst;
	char			*line;

	if (!fd ||BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	lst = ft_read(fd, lst);
	if (!lst)
		return (NULL);
	line = ft_line(lst, lst);
	if (!line)
		return (NULL);
	ft_cleastr(&lst);
	//renvoie null quand y a plus rien a lire
	if (line[0] == '\0')
	{
		lst = NULL;
		free(line);
		return (NULL);
	}
	return (line);
}
