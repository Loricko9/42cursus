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

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	if (!src)
		return (NULL);
	while (i < BUFFER_SIZE)
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

	if (stock)
	{
		temp = ft_calloc(size - re);
		if (!temp)
			return (NULL);
		ft_strcpy(temp, stock);
		free(stock);
	}
	if (!ft_calloc(size))
		return (NULL);
	ft_strcpy(stock, temp);
	i = size;
	j = 0;
	while (j < re)
	{
		stock[i] = buff[j];
		i++;
		j++;
	}
	free(temp);
	return (stock);
}
