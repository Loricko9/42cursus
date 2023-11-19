/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 17:29:52 by lle-saul          #+#    #+#             */
/*   Updated: 2023/10/23 14:29:37 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_clear_stock(t_list **stock)
{
	t_list	*clear_node;
	t_list	*last;
	int		i;
	int		j;

	clear_node = malloc(sizeof(t_list));
	if (!clear_node)
		return ;
	clear_node->next = NULL;
	last = ft_lstlast(*stock);
	i = 0;
	while (last->str[i] != '\0' && last->str[i] != '\n')
		i++;
	if (last->str[i] == '\n')
		i++;
	clear_node->str = malloc(sizeof(char) * ((ft_strlen(last->str) - i) + 1));
	if (!clear_node->str)
		return ;
	j = 0;
	while (last->str[i] != '\0')
		clear_node->str[j++] = last->str[i++];
	clear_node->str[j] = '\0';
	ft_free_stock(*stock);
	*stock = clear_node;
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
	new_node->next = NULL;
	last = ft_lstlast(*stock);
	new_node->str = malloc(sizeof(char) * size + 1);
	if (!new_node->str)
		return ;
	i = 0;
	while (buff[i] != '\0')
	{
		new_node->str[i] = buff[i];
		i++;
	}
	new_node->str[i] = '\0';
	if (!*stock)
	{
		*stock = new_node;
		return ;
	}
	last->next = new_node;
}

void	ft_read(t_list **stock, int fd, int *size)
{
	char	*buff;

	while (*size != 0 && ft_find_get_next(*stock) == 0)
	{
		buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buff)
			return ;
		*size = read(fd, buff, BUFFER_SIZE);
		if ((*size == 0 && !*stock) || *size < 0)
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
		return (ft_free_stock(stock), stock = NULL, NULL);
	line = NULL;
	size = 1;
	ft_read(&stock, fd, &size);
	if (!stock || size < 0)
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
