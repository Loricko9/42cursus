/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 17:07:42 by lle-saul          #+#    #+#             */
/*   Updated: 2024/01/13 17:07:42 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	cmd_error(char *cmd)
{
	dup2(STDERR_FILENO, STDOUT_FILENO);
	printf("minishell: command not found: %s\n", cmd);
}

char	*ft_clean_line2(char *str, int i)
{
	int	index;

	index = i - 1;
	if (str[i] == '<' || str[i] == '>')
		i++;
	while (str[i] == ' ' && str[i] != '\0')
		i++;
	i = i + get_len_quote(str + i);
	if (str[i] == '\0')
		i--;
	return (ft_extract_str(str, index, i));
}

int	ft_path_env(char **env)
{
	int	i;

	i = 0;
	while (env[i] != NULL)
	{
		if (ft_strcmp("PATH=", env[i]) == 0)
			return (i);
		i++;
	}
	return (i);
}

void	ft_free_var(char **cmd, char **env_path, char *path)
{
	ft_free_tab(cmd);
	ft_free_tab(env_path);
	if (path)
		free(path);
}

char	*ft_get_path(char **path, char *cmd)
{
	int		i;
	char	*full_path;
	char	*new_cmd;

	i = 0;
	new_cmd = ft_strjoin("/", cmd);
	while (path[i] != NULL)
	{
		full_path = ft_strjoin(path[i], new_cmd);
		if (access(full_path, X_OK) == 0)
			return (free(new_cmd), full_path);
		free(full_path);
		i++;
	}
	return (free(new_cmd), NULL);
}
