/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 17:41:49 by lle-saul          #+#    #+#             */
/*   Updated: 2023/11/23 14:21:24 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pipex.h"
#include <stdlib.h>

static void	ft_cote(int *val, char c)
{
	if (*val == 1 && c == '"')
		*val = 0;
	else if (*val == 0 && c == '"')
		*val = 1;
}

size_t	ft_strlen_split(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (i);
	while (s[i] != '\0')
		i++;
	return (i);
}

static int	ft_countwords(char const *s, char c, int *trig_cote)
{
	int	i;
	int	count;
	int	trig;

	i = 0;
	count = 0;
	trig = 0;
	*trig_cote = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
	{
		ft_cote(trig_cote, s[i]);
		if (trig == 0 && s[i] != c)
		{
			count++;
			trig = 1;
		}
		else if (s[i] == c && *trig_cote == 0)
			trig = 0;
		i++;
	}
	*trig_cote = 0;
	return (count);
}

static char	*ft_splitword(char const *s, int *index, int i)
{
	char	*str;
	int		j;

	if (s[i - 1] == '"')
	{
		++*index;
		i--;
	}
	str = malloc((i - *index + 1) * sizeof(char));
	j = 0;
	while (*index < i)
	{
		str[j] = s[*index];
		++*index;
		j++;
	}
	str[j] = '\0';
	*index = -1;
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	size_t	i;
	size_t	j;
	int		index;
	int		trig_cote;

	tab = malloc(sizeof(char *) * (ft_countwords(s, c, &trig_cote) + 1));
	if (!tab)
		return (NULL);
	i = -1;
	j = 0;
	index = -1;
	while (++i <= ft_strlen_split(s))
	{
		ft_cote(&trig_cote, s[i]);
		if (s[i] != c && index == -1)
			index = i;
		else if ((s[i] == c || i == ft_strlen_split(s)) && index != -1
			&& trig_cote != 1)
			tab[j++] = ft_splitword(s, &index, i);
	}
	tab[j] = NULL;
	return (tab);
}
