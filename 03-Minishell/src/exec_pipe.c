/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 18:25:24 by lle-saul          #+#    #+#             */
/*   Updated: 2024/01/23 12:48:21 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	redirect_fd_pipe(int *fd_pipe, int *fd, int i)
{
	if (i == 2 && fd[0] > -1)
		ft_redirect_fd(fd[0], STDIN_FILENO, NULL);
	else if (i == 3 && fd[1] > -1)
		ft_redirect_fd(fd[1], STDOUT_FILENO, NULL);
	else if (i == 1)
	{
		if (fd[1] > -1)
			ft_redirect_fd(fd[1], STDOUT_FILENO, NULL);	
		else
			ft_redirect_fd(fd_pipe[1], STDOUT_FILENO, NULL);
	}
	else if (i == 0)
	{
		if (fd[0] > -1)
			ft_redirect_fd(fd[0], STDIN_FILENO, NULL);
		else
			ft_redirect_fd(fd_pipe[0], STDIN_FILENO, NULL);
	}
}

void	fork_pipe(char **cmd, char **env, int i, int **fd)
{
	pid_t	pid;
	int		fd_pipe[2];

	if (pipe(fd_pipe) == -1)
	{
		perror("minishell");
		exit(1);
	}
	pid = fork();
	if (pid == -1)
	{
		perror("minishell");
		exit(1);
	}
	if (pid == 0)
	{
		close(fd_pipe[0]);
		redirect_fd_pipe(fd_pipe, *fd, 1);
		ft_case(env, cmd[i]);
	}
	close(fd_pipe[1]);
	*fd = get_redirec(cmd[i + 1]);
	redirect_fd_pipe(fd_pipe, *fd, 0);
	//waitpid(pid, &res_error, 0);
	//res_error = WEXITSTATUS(res_error);
}

void	ft_master_pipe(char **cmd, char **env)
{
	int	i;
	int	*fd;

	i = 0;
	fd = get_redirec(cmd[i]);
	if (fd[0] == -2 || fd[1] == -2)
	{
		free(fd);
		exit(1);
	}
	redirect_fd_pipe(NULL, fd, 2);
	while (cmd[i + 1] != NULL)
	{
		fork_pipe(cmd, env, i, &fd);
		if (fd[0] == -2 || fd[1] == -2)
		{
			free(fd);
			exit(1);
		}
		i++;
	}
	redirect_fd_pipe(NULL, fd, 3);
	ft_case(env, cmd[i]);
}

void	ft_pipe(char **env, char **cmd)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		perror("minishell");
	if (pid == 0)
	{
		recover_signal();
		ft_master_pipe(cmd, env);
	}
	waitpid(pid, &res_error, 0);
	res_error = WEXITSTATUS(res_error);
	ft_free_tab(cmd);
}
