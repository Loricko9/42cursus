/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 17:29:52 by lle-saul          #+#    #+#             */
/*   Updated: 2023/10/12 17:29:52 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_line(char *stock, int *size)
{
	char	*line;	
	int		i;
	int		len;

	i = 0;
	if (ft_find(stock, *size) >= 0)
		len = ft_find(stock, *size) + 1;
	else
		len = *size;
	line = malloc(sizeof(char) * len + 1);
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

int	ft_find(char *stock, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (stock[i] == '\n')
			return (i);
		if (stock[i] == 0)
			return (i - 1);
		i++;
	}
	return (-1);
}

char	*ft_read(int fd, char *stock, int *size)
{
	char	*buff;
	int		count;
	int		re;

	buff = ft_calloc(BUFFER_SIZE);
	if (!buff)
		return (NULL);
	re = read(fd, buff, BUFFER_SIZE);
	count = 1;
	*size = re;
	if (re < 0 || !ft_strcat(buff, stock, *size, re))
		return (NULL);
	while (re == BUFFER_SIZE && ft_find(stock, *size) < 0)
	{
		re = read(fd, buff, BUFFER_SIZE);
		*size = *size + re;
		if (re < 0 || !ft_strcat(buff, stock, *size, re))
			return (NULL);
		count++;
	}
	return (stock);
}

char	*ft_clear_stock(char *stock, int *size)
{
	char	*temp;
	int		i;
	int		j;

	if (ft_find(stock, *size) < 0)
		free(stock);
	else
	{
		temp = ft_calloc(*size);
		if (!temp)
			return (NULL);
		ft_strcpy(temp, stock);
		free(stock);
		stock = ft_calloc(*size - (ft_find(temp, *size) + 1));
		if (!stock)
			return (NULL);
		i = ft_find(temp, *size) + 1;
		j = -1;
		while (i < ft_find(temp, *size) + 1)
			stock[j++] = temp[i++];
		free(temp);
	}
	return (stock);
}

char	*get_next_line(int fd)
{
	static char		*stock;
	char			*line;
	int				size;

	if (!fd || BUFFER_SIZE <= 0)
		return (NULL);
	size = 0;
	if (!ft_read(fd, stock, &size))
		return (NULL);
	line = ft_line(stock, &size);
	if (!line)
		return (NULL);
	stock = ft_clear_stock(stock, &size);
	if (!stock)
		return (NULL);
	return (line);
}
