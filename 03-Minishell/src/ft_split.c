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

#include "minishell.h"
#include <stdlib.h>

int	ft_find_char(const char *s1, const char c)
{
	int	i;

	i = 0;
	while (s1[i] != '\0')
	{
		if (s1[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static void	ft_cote(int *val, char c)
{
	static char	quote = 0;

	if (quote == 0 && (c == '"' || c == '\''))
		c = quote;
	if (*val == 1 && c == quote)
	{
		*val = 0;
		quote = 0;
	}
	else if (*val == 0 && c == quote)
		*val = 1;
		
}

static int	ft_countwords(char const *s, char *c, int *trig_cote)
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
		if (trig == 0 && ft_find_char(c, s[i]) == 0)
		{
			count++;
			trig = 1;
		}
		else if (ft_find_char(c, s[i]) == 1 && *trig_cote == 0)
			trig = 0;
		i++;
	}
	*trig_cote = 0;
	return (count);
}

static char	*ft_splitword(char const *s, int *index, int i)
{
	char	*str;
	char	quote;
	int		j;

	quote = 0;
	if (s[i - 1] == '"' || s[i - 1] == '\'')
	{
		++*index;
		i--;
		quote = s[i];
	}
	str = malloc((i - *index + 1) * sizeof(char));
	j = 0;
	while (*index < i)
	{
		if (s[*index] != quote || quote == 0)
			str[j++] = s[*index];
		++*index;
	}
	str[j++] = '\0';
	*index = -1;
	return (str);
}

char	**ft_split(char *s, char *c)
{
	char	**tab;
	int		i;
	int		j;
	int		index;
	int		trig_cote;

	tab = malloc(sizeof(char *) * (ft_countwords(s, c, &trig_cote) + 1));
	if (!tab)
		return (NULL);
	i = -1;
	j = 0;
	index = -1;
	while (++i <= ft_strlen(s))
	{
		ft_cote(&trig_cote, s[i]);
		if (ft_find_char(c, s[i]) == 0 && index == -1)
			index = i;
		else if (((ft_find_char(c, s[i]) == 1 && trig_cote != 1) || i == ft_strlen(s)) && index != -1)
			tab[j++] = ft_splitword(s, &index, i);
	}
	tab[j] = NULL;
	return (tab);
}
