/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 13:23:21 by lle-saul          #+#    #+#             */
/*   Updated: 2024/01/12 13:23:21 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	fork_exec(char **env, char *line, int (*function)(char **, char **))
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		if (function(ft_split(line, " "), env) == 1)
			exit(1);
	}
	else
		wait(NULL);
}

int	ft_exec_prog(char **cmd, char **env)
{
	char	*pwd;
	char	*path;
	int		res;

	res = 0;
	if (!cmd)
		return(perror("minishell"), 1);
	pwd = getcwd(NULL, 1000);
	if (!pwd)
		return(perror("minishell"), ft_free_tab(cmd), 1);
	path = ft_strjoin(pwd, cmd[0] + 1);
	if (!path)
		return(perror("minishell"), ft_free_tab(cmd), free(pwd), 1);
	res = execve(path, cmd, env);
	if (res == -1)
		perror("minishell");
	free(pwd);
	free(path);
	ft_free_tab(cmd);
	exit(1);
}
