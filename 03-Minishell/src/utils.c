/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 14:44:18 by lle-saul          #+#    #+#             */
/*   Updated: 2024/02/03 19:39:28 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(char *s)
{
	int		i;
	char	*str;

	i = 0;
	if (!s)
		return (NULL);
	str = malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!str)
		return (NULL);
	while (s[i] != '\0')
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

int	ft_strcmp_shell(const char *s1, const char *s2, int n)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s1)
		return (0);
	while (s1[j] == ' ')
		j++;
	while (s1[j] != '\0' && s1[j] == s2[i] && s2[i] != '\0')
	{
		i++;
		j++;
	}
	if (s2[i] == '\0' && (s1[j] == '\0' || s1[j] == ' ') && n == 0)
		return (1);
	if (s2[i] == '\0' && n == 1)
		return (1);
	if (s2[i] == '\0' && s1[j] == '=' && n == 2)
		return (1);
	return (0);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	j;

	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (j < len && s[i] != '\0')
	{
		if (i >= start)
		{
			str[j] = s[i];
			j++;
		}
		i++;
	}
	str[j] = '\0';
	return (str);
}

int	ft_find_char_quote(const char *s1, const char c)
{
	int		i;
	char	trig;

	i = 0;
	trig = 0;
	while (s1[i] != '\0')
	{
		if (trig == 0 && (s1[i] == '"' || s1[i] == '\''))
			trig = s1[i];
		else if (trig > 0 && s1[i] == trig)
			trig = 0;
		if (s1[i] == c && trig == 0)
			return (1);
		i++;
	}
	return (0);
}
