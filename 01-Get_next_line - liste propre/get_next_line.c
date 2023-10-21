/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 16:52:45 by lle-saul          #+#    #+#             */
/*   Updated: 2023/10/21 16:52:45 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_clear_stock(t_list **stock)
{
	t_list	*clean_node;
	t_list	*last;
	int		i;
	int		j;

	clean_node = malloc(sizeof(t_list));
	if (!clean_node)
		return ;
	clean_node->next = NULL;
	last = ft_lstlast(*stock);
	i = 0;
	while (last->str[i] != '\n' && last->str[i] != '\0')
		i++;
	if (last->str[i] == '\n')
		i++;
	clean_node->str = malloc(sizeof(char) * ((ft_strlen(last->str) - i) + 1));
	if (!clean_node->str)
		return ;
	j = 0;
	while (last->str[i] != '\0')
		clean_node->str[j++] = last->str[i++];
	clean_node->str[j] = '\0';
	ft_free_stock(*stock);
	*stock = clean_node;
}

char	*ft_line(t_list *stock)
{
	char	*line;
	int		i;
	int		j;

	line = malloc(sizeof(char) * ft_get_size(stock) + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (stock != NULL)
	{
		j = 0;
		while (stock->str[j] != '\0')
		{
			if (stock->str[j] == '\n')
			{
				line[i++] = stock->str[j];
				break ;
			}
			line[i++] = stock->str[j++];
		}
		stock = stock->next;
	}
	line[i] = '\0';
	return (line);
}

void	ft_add(t_list **stock, char *buff, int size)
{
	t_list	*new_node;
	t_list	*last;
	int		i;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return ;
	new_node->str = malloc(sizeof(char) * (size + 1));
	if (!new_node->str)
		return ;
	i = 0;
	while (buff[i] != '\0' && i < size)
	{
		new_node->str[i] = buff[i];
		i++;
	}
	new_node->str[i] = '\0';
	new_node->next = NULL;
	last = ft_lstlast(*stock);
	if (!last)
	{
		*stock = new_node;
		return ;
	}
	last->next = new_node;
}

void	ft_read(int fd, t_list **stock, int *size)
{
	char	*buff;

	while (ft_find(*stock) == 0 && *size > 0)
	{
		buff = malloc(sizeof(char) * BUFFER_SIZE + 1);
		if (!buff)
			return ;
		*size = read(fd, buff, BUFFER_SIZE);
		if ((*stock == NULL && *size == 0) || *size < 0)
		{
			free(buff);
			return ;
		}
		buff[*size] = '\0';
		ft_add(stock, buff, *size);
		free(buff);
	}
}

char	*get_next_line(int fd)
{
	static t_list	*stock;
	char			*line;
	int				size;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	size = 1;
	line = NULL;
	ft_read(fd, &stock, &size);
	if (!stock)
		return (NULL);
	line = ft_line(stock);
	if (!line)
		return (NULL);
	ft_clear_stock(&stock);
	if (line[0] == '\0')
	{
		ft_free_stock(stock);
		stock = NULL;
		free(line);
		return (NULL);
	}
	return (line);
}
