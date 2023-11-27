/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 17:27:18 by lle-saul          #+#    #+#             */
/*   Updated: 2023/11/23 15:09:19 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pipex.h"

int	ft_exec_cmd(char **cmd, char **env)
{
	char	*path;
	char	**env_path;
	int		res;

	res = 0;
	env_path = ft_split(env[ft_path_env(env)], ':');
	if (!env_path)
		return (perror("pipex"), ft_free_tab(env_path), ft_free_tab(cmd), 1);
	path = ft_get_path(env_path, cmd[0]);
	if (!path)
		return (ft_putstr("pipex: command not found: ", 2), ft_putstr(cmd[0],
				2), ft_putchar('\n', 2), ft_free_tab(env_path),
			ft_free_tab(cmd), 1);
	res = execve(path, cmd, env);
	ft_free_var(cmd, env_path, path);
	if (res == -1)
		return (perror("pipex"), 1);
	return (0);
}

int	ft_redirect_fd(char *file1, char *file2, int i)
{
	int	fd;

	if (i == 0)
	{
		fd = open(file1, O_RDONLY);
		if (fd < 0)
			return (perror("pipex"), 1);
		if (dup2(fd, STDIN_FILENO) == -1)
			return (perror("pipex"), 1);
		close(fd);
		return (0);
	}
	else
	{
		fd = open(file2, O_WRONLY | O_CREAT, 00777);
		if (fd < 0)
			return (perror("pipex"), 1);
		if (dup2(fd, STDOUT_FILENO) == -1)
			return (perror("pipex"), 1);
		close(fd);
		return (0);
	}
}

void	ft_pipe_exec(int pid, int *fd, char *cmd, char **env)
{
	if (pid == 0)
	{
		if (dup2(fd[1], STDOUT_FILENO) == -1)
		{
			perror("pipex");
			exit(1);
		}
		if (ft_exec_cmd(ft_split(cmd, ' '), env) == 1)
			exit(1);
	}
	else
	{
		close(fd[1]);
		if (dup2(fd[0], STDIN_FILENO) == -1)
		{
			perror("pipex");
			exit(1);
		}
		close(fd[0]);
	}
}

void	ft_create_pid(char *cmd, char **env)
{
	int	fd[2];
	int	pid;

	if (pipe(fd) == -1)
	{
		perror("pipex");
		exit(1);
	}
	pid = fork();
	if (pid == -1)
	{
		close(fd[0]);
		close(fd[1]);
		perror("pipex");
		exit(1);
	}
	ft_pipe_exec(pid, fd, cmd, env);
}

int	main(int ac, char **av, char **env)
{
	int	i;
	int	a;

	i = -1;
	a = 0;
	if (ac < 6 && ft_strcmp(av[1], "here_doc") == 0)
		return (write(1,
				"pipex: minimum 6 arguments need with here_doc\n", 47));
	if (ac < 5)
		return (write(1, "pipex: minimum 5 arguments need\n", 32));
	if (check_file(av[1], av[ac - 1]) == 1)
		return (1);
	if (ft_strcmp(av[1], "here_doc") == 0)
		ft_here_doc(&a, ft_strjoin(av[2], "\n"));
	else
		if (ft_redirect_fd(av[1], av[ac - 1], 0) == 1)
			return (1);
	while (++i < ((ac - 4) - a))
		ft_create_pid(av[i + 2 + a], env);
	if (ft_redirect_fd(av[1], av[ac - 1], 1) == 1)
		return (1);
	ft_exec_cmd(ft_split(av[ac - 2], ' '), env);
}
