/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 17:17:54 by lle-saul          #+#    #+#             */
/*   Updated: 2024/01/13 17:17:54 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i] != NULL)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	ft_check_redir(int *trig, int i, char *line)
{
	char	c;
	
	if (line[i] == '>' || line[i] == '<')
	{
		c = line[i];
		if (line[++i] == c)
			i++;
		if (line[i] == c)
		{
			*trig = 2;
			return ;
		}
		while (line[i] != '>' && line[i] != '<')
		{
			if (line[i] != ' ')
				return ;
			i++;
		}
		*trig = 2;
	}
}

int	ft_strcmp(char *src, char *dest)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		if (src[i] != dest[i])
			return (1);
		i++;
	}
	return (0);
}