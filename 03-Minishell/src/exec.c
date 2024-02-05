/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 13:23:21 by lle-saul          #+#    #+#             */
/*   Updated: 2024/02/05 13:29:36 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_clean_line(char *str)
{
	char	trig;
	char	*new;
	int		i;

	i = 0;
	trig = 0;
	while (str[i] != '\0')
	{
		if (trig == 0 && (str[i] == '"' || str[i] == '\''))
			trig = str[i];
		else if (trig > 0 && str[i] == trig)
			trig = 0;
		if ((str[i] == '>' || str[i] == '<') && trig == 0)
		{
			new = ft_clean_line2(str, i + 1);
			free(str);
			str = new;
			i = 0;
		}
		else
			i++;
	}
	return (str);
}

void	fork_exec(char ***env, char *line, int *fd)
{
	pid_t	pid;

	if (ft_case_change_env(env, line) == 1)
	{
		pid = fork();
		if (pid == -1)
			perror("minishell");
		if (pid == 0)
		{
			recover_signal();
			fd = get_redirec(line);
			if (fd[0] < 0 || fd[1] < 0)
			{
				free(fd);
				ft_free_tab(*env);
				exit(1);
			}
			ft_redirect_fd(fd[0], STDIN_FILENO, fd);
			ft_redirect_fd(fd[1], STDOUT_FILENO, fd);
			free(fd);
			ft_case(*env, line, NULL);
		}
		waitpid(pid, &g_res_error, 0);
		g_res_error = WEXITSTATUS(g_res_error);
	}
}

int	ft_exec_prog(char **cmd, char **env, char *line)
{
	int		res;

	res = 0;
	free(line);
	if (!cmd)
		return (perror("minishell"), ft_free_var(cmd, NULL, NULL, env), 1);
	if (access(cmd[0], X_OK) == -1)
		return (perror("minishell"), ft_free_var(cmd, NULL, NULL, env), 127);
	res = execve(cmd[0], cmd, env);
	if (res == -1)
		return (perror("minishell"), ft_free_var(cmd, NULL, NULL, env), 1);
	ft_free_tab(cmd);
	ft_free_tab(env);
	exit(res);
}

int	ft_exec_cmd(char **cmd, char **env, char *line)
{
	char	*path;
	char	**env_path;	
	int		res;

	res = 0;
	free(line);
	if (cmd[0] == NULL)
		return (free(cmd), ft_free_tab(env), g_res_error);
	if (access(cmd[0], X_OK) == 0)
		path = ft_strdup(cmd[0]);
	else
	{
		env_path = ft_split(env[ft_path_env(env, cmd[0])], ":", 0);
		if (!env_path)
			return (ft_free_var(cmd, env_path, NULL, env), 1);
		path = ft_get_path(env_path, cmd[0]);
	}
	if (!path)
		return (cmd_error(cmd[0]), ft_free_var(cmd, env_path, NULL, env), 127);
	res = execve(path, cmd, env);
	ft_free_var(cmd, env_path, path, env);
	if (res == -1)
		return (perror("minishell"), 1);
	return (res);
}
