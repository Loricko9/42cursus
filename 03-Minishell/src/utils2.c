/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 15:58:59 by lle-saul          #+#    #+#             */
/*   Updated: 2024/01/12 15:58:59 by lle-saul         ###   ########.fr       */
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

char	**dup_tab(char **tab)
{
	char	**tab_copy;
	int		i;
	int		j;

	j = 0;
	tab_copy = malloc(sizeof(char *) * (ft_tablen(tab) + 1));
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

void	ft_check_quote2(int *trig, int *i, char *line)
{
	if (line[*i] == '"')
	{
		*trig = 1;
		++*i;
		while (line[*i] != '"' && line[*i] != '\0')
			++*i;
		if (line[*i] == '"')
			*trig = 0;
	}
	else if (line[*i] == '\'')
	{
		*trig = 1;
		++*i;
		while (line[*i] != '\'' && line[*i] != '\0')
			++*i;
		if (line[*i] == '\'')
			*trig = 0;
	}
}

int	ft_check_quote(char *line)
{
	int i;
	int	trig;

	i = 0;
	trig = 0;
	while (line[i] != '\0')
	{
		ft_check_quote2(&trig, &i, line);
		i++;
	}
	if (trig == 0)
		return (1);
	return (printf("minishell : undeterminated quote\n"), 0);
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
	free(str);
	return (new);
}
