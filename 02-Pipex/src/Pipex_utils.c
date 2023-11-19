/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 15:17:54 by lle-saul          #+#    #+#             */
/*   Updated: 2023/11/19 15:17:54 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pipex.h"

void	ft_free_var(char **cmd, char **env_path, char *path)
{
	ft_free_tab(cmd);
	ft_free_tab(env_path);
	if (path)
		free(path);
}

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

char	*ft_get_path(char **path, char *cmd)
{
	int		i;
	char	*full_path;

	i = 0;
	while (path[i] != NULL)
	{
		full_path = ft_strjoin(path[i], cmd);
		if (access(full_path, X_OK) == 0)
			return (full_path);
		free(full_path);
		i++;
	}
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*tab;
	size_t	size;

	size = ft_strlen_split(s1) + ft_strlen_split(s2) + 1;
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
