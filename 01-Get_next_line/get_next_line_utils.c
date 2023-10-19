/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 14:44:30 by lle-saul          #+#    #+#             */
/*   Updated: 2023/10/18 17:16:35 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}

char	*ft_calloc(size_t nmemb)
{
	char	*tab;
	size_t	i;

	tab = malloc(sizeof(char) * nmemb);
	if (!tab)
		return (NULL);
	i = 0;
	while (i < nmemb)
	{
		tab[i] = 0;
		i++;
	}
	return (tab);
}

char	*ft_strcpy(char *dest, char *src, int size)
{
	int	i;

	i = 0;
	if (!src)
		return (NULL);
	while (i < size)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}

char	*ft_strcat(char *buff, char *stock, int size, int re)
{
	char	*temp;
	int		i;
	int		j;

	temp = NULL;
	if (stock != NULL)
	{
		temp = ft_calloc(size - re);
		if (!temp)
			return (NULL);
		ft_strcpy(temp, stock, size - re);
		free(stock);
	}
	stock = ft_calloc(size);
	if (!stock)
		return (NULL);
	ft_strcpy(stock, temp, size - re);
	i = size - re;
	j = 0;
	while (j < re)
		stock[i++] = buff[j++];
	free(temp);
	return (stock);
}
