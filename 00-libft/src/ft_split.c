/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 17:41:49 by lle-saul          #+#    #+#             */
/*   Updated: 2023/09/15 17:41:49 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdlib.h>

int	ft_countwords(char const *s, char c)
{
	int	i;
	int	count;
	int	trig;

	i = 0;
	count = 0;
	trig = 0;
	while (s[i] != '\0')
	{
		if (trig == 0 && s[i] != c)
		{
			count++;
			trig = 1;
		}
		else if (s[i] == c)
			trig = 0;
		i++;
	}
	return (count);
}

char	*ft_splitword(char const *s, size_t index, size_t i)
{
	char	*str;
	size_t	j;

	str = malloc((i - index + 1) * sizeof(char));
	j = 0;
	while (index < i)
	{
		str[j] = s[index];
		index++;
		j++;
	}
	str[j] = '\0';
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	size_t	i;
	size_t	j;
	size_t	index;

	tab = malloc(sizeof(char *) * ft_countwords(s, c) + 1);
	if (!tab)
		return (NULL);
	i = 0;
	j = 0;
	index = -1;
	while (i != ft_strlen(s))
	{
		if (s[i] != c && index == -1)
			index = i;
		else if ((s[i] == c || i == ft_strlen(s)) && index != -1)
		{
			tab[j] = ft_splitword(s, index, i);
			j++;
			index = -1;
		}
		i++;
	}
	tab[j] = 0;
	return (tab);
}
