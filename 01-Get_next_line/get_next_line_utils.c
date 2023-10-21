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
	while (str[i] != '\0')
	{	
		i++;
	}
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
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*tab;
	size_t	size;

	if (!s1)
	{
		s1 = malloc(sizeof(char) * 1);
		s1[0] = '\0';
	}
	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	i = 0;
	tab = malloc(size * sizeof(char));
	if (!tab)
		return (NULL);
	while (s1[++i] != '\0')
		tab[i] = s1[i];
	j = 0;
	while (s2[j] != '\0')
		tab[i++] = s2[j++];
	tab[i] = '\0';
	free(s1);
	return (tab);
}
