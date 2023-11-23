/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 10:58:41 by lle-saul          #+#    #+#             */
/*   Updated: 2023/11/03 15:09:54 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	my_ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != 13 && str[i] != '\n')
		i++;
	return (i);
}

char	**fill_map(char **map, t_list *list)
{
	int	i;
	int	j;

	j = 0;
	while (list != NULL)
	{
		i = 0;
		map[j] = malloc(sizeof(char) * my_ft_strlen(list->str) + 1);
		if (!map[j])
			return (NULL);
		while (list->str[i] != '\0' && list->str[i] != 13
			&& list->str[i] != '\n')
		{
			map[j][i] = list->str[i];
			i++;
		}
		map[j][i] = '\0';
		list = list->next;
		j++;
	}
	map[j] = NULL;
	return (map);
}

void	fill_list(int fd, t_list **list)
{
	char	*line;

	while (1)
	{
		line = get_next_line(fd);
		if (line)
			ft_lstadd_back(list, ft_lstnew(line));
		else
			break ;
	}
}

char	**get_map(int fd)
{
	char	**map;
	t_list	*list;

	if (fd < 0)
		return (NULL);
	list = NULL;
	fill_list(fd, &list);
	map = malloc(sizeof(char *) * (ft_lstsize(list) + 1));
	if (!map)
		return (NULL);
	map = fill_map(map, list);
	if (!map)
		return (NULL);
	ft_free_stock(list);
	return (map);
}
