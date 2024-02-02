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

char	*ft_clean_line(char *str)
{
	char	trig;
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
			str = ft_clean_line2(str, i + 1);
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
			if (fd[0] > -1)
				ft_redirect_fd(fd[0], STDIN_FILENO, fd);
			if (fd[1] > -1)
				ft_redirect_fd(fd[1], STDOUT_FILENO, fd);
			if (fd[0] != -2 && fd[1] != -2)
			{
				free(fd);
				ft_case(*env, line, NULL);
			}
			free(fd);
			exit(1);
		}
		waitpid(pid, &res_error, 0);
		res_error = WEXITSTATUS(res_error);
	}
}

int	ft_exec_prog(char **cmd, char **env, char *line)
{
	char	*pwd;
	char	*path;
	int		res;

	res = 0;
	free(line);
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
		return (free(cmd), res_error);
	env_path = ft_split(env[ft_path_env(env)], ":", 0);
	if (!env_path)
		return (perror("minishell"), ft_free_tab(env_path), ft_free_tab(cmd), ft_free_tab(env), 1);
	if (access(cmd[0], X_OK) == 0)
		path = ft_strdup(cmd[0]);
	else
		path = ft_get_path(env_path, cmd[0]);
	if (!path)
		return (cmd_error(cmd[0]), ft_free_tab(env_path), ft_free_tab(cmd), ft_free_tab(env), 127);
	res = execve(path, cmd, env);
	ft_free_var(cmd, env_path, path);
	if (res == -1)
		return (perror("minishell"), 1);
	return (res);
}
