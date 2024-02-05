/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 15:58:59 by lle-saul          #+#    #+#             */
/*   Updated: 2024/02/05 11:35:50 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_tablen(char **tab)
{
	int	i;

	i = 0;
	while (tab[i] != NULL)
		i++;
	return (i);
}

char	**dup_tab(char **tab, int ac, char **av)
{
	char	**tab_copy;
	int		i;
	int		j;

	j = 0;
	tab_copy = malloc(sizeof(char *) * (ft_tablen(tab) + 1));
	(void)ac;
	(void)av;
	if (!tab_copy)
		return (NULL);
	while (tab[j] != NULL)
	{
		i = 0;
		tab_copy[j] = malloc(sizeof(char) * ft_strlen(tab[j]) + 1);
		while (tab[j][i] != '\0')
		{
			tab_copy[j][i] = tab[j][i];
			i++;
		}
		tab_copy[j][i] = '\0';
		j++;
	}
	tab_copy[j] = NULL;
	return (tab_copy);
}

char	*ft_extract_str(char *str, int start, int end)
{
	char	*new;
	int		i;
	int		j;

	i = 0;
	j = 0;
	new = malloc(sizeof(char) * ((ft_strlen(str) - ((end - start) + 1)) + 1));
	if (!new)
		return (NULL);
	while (str[i] != '\0')
	{
		if (i < start || i > end)
			new[j++] = str[i];
		i++;
	}
	new[j++] = '\0';
	str = NULL;
	return (new);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*tab;
	size_t	size;

	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	i = 0;
	tab = malloc(size * sizeof(char));
	if (!tab)
		return (NULL);
	while (s1[i] != '\0')
	{
		tab[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		tab[i] = s2[j];
		i++;
		j++;
	}
	tab[i] = '\0';
	return (tab);
}

int	find_slash(char *line)
{
	int	i;

	i = 0;
	while (line[i] == ' ')
		i++;
	while (line[i] != ' ' && line[i] != '\0')
	{
		if (line[i] == '/')
			return (1);
		i++;
	}
	return (0);
}
