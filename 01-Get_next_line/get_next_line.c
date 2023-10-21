/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 17:29:52 by lle-saul          #+#    #+#             */
/*   Updated: 2023/10/18 17:16:11 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_line(char *stock)
{
	char	*line;	
	int		i;
	int		len;

	i = 0;
	if (ft_find(stock) >= 0)
		len = ft_find(stock) + 1;
	else
		len = ft_strlen(stock);
	line = malloc(sizeof(char) * (len + 1));
	if (!line)
		return (NULL);
	while (i < len)
	{
		line[i] = stock[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

int	ft_find(char *stock)
{
	int	i;
	int	size;

	if (!stock)
		return (-1);
	i = 0;
	size = ft_strlen(stock);
	while (i <= size)
	{
		if (stock[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_read(int fd, char *stock)
{
	char	*buff;
	int		re;

	buff = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	re = BUFFER_SIZE;
	while (re == BUFFER_SIZE && ft_find(stock) < 0)
	{
		re = read(fd, buff, BUFFER_SIZE);
		buff[re] = '\0';
		stock = ft_strjoin(stock, buff);
		if (re < 0 || !stock)
			return (NULL);
	}
	free(buff);
	return (stock);
}

char	*ft_clear_stock(char *stock)
{
	char	*temp;
	int		i;
	int		j;

	if (ft_find(stock) < 0)
		free(stock);
	else
	{
		temp = ft_calloc(ft_strlen(stock) + 1);
		if (!temp)
			return (NULL);
		ft_strcpy(temp, stock, (ft_strlen(stock)));
		free(stock);
		stock = ft_calloc(ft_strlen(temp) - ft_find(temp));
		if (!stock)
			return (NULL);
		i = ft_find(temp) + 1;
		j = 0;
		while (i < ft_strlen(temp))
			stock[j++] = temp[i++];
		free(temp);
	}
	return (stock);
}

char	*get_next_line(int fd)
{
	static char		*stock;
	char			*line;

	if (!fd || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	stock = ft_read(fd, stock);
	if (!stock)
		return (NULL);
	line = ft_line(stock);
	if (!line)
		return (NULL);
	stock = ft_clear_stock(stock);
	if (!stock)
		return (NULL);
	return (line);
}
