/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 18:25:24 by lle-saul          #+#    #+#             */
/*   Updated: 2024/02/05 13:14:20 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	redirect_fd_pipe(int *fd_pipe, int *fd, int i)
{
	if (fd[0] == -1 || fd[1] == -1)
		(void)i;
	else if (i == 2 && fd[0] > 0)
		ft_redirect_fd(fd[0], STDIN_FILENO, NULL);
	else if (i == 3 && fd[1] > 1)
		ft_redirect_fd(fd[1], STDOUT_FILENO, NULL);
	else if (i == 1)
	{
		if (fd[1] > 1)
			ft_redirect_fd(fd[1], STDOUT_FILENO, NULL);
		else
			ft_redirect_fd(fd_pipe[1], STDOUT_FILENO, NULL);
	}
	else if (i == 0)
	{
		if (fd[0] > 0)
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
		exit(1);
	pid = fork();
	if (pid == -1)
		exit(1);
	if (pid == 0)
	{
		close(fd_pipe[0]);
		if ((*fd)[0] == -1 || (*fd)[1] == -1)
		{
			ft_free_var(cmd, NULL, *fd, env);
			exit(1);
		}
		redirect_fd_pipe(fd_pipe, *fd, 1);
		free(*fd);
		ft_case(env, ft_strdup(cmd[i]), cmd);
	}
	close(fd_pipe[1]);
	free(*fd);
	*fd = get_redirec(cmd[i + 1]);
	redirect_fd_pipe(fd_pipe, *fd, 0);
}

void	ft_master_pipe(char **cmd, char **env)
{
	int	i;
	int	*fd;

	i = 0;
	fd = get_redirec(cmd[i]);
	redirect_fd_pipe(NULL, fd, 2);
	while (cmd[i + 1] != NULL)
	{
		fork_pipe(cmd, env, i, &fd);
		i++;
	}
	if (fd[0] == -1 || fd[1] == -1)
	{
		ft_free_var(cmd, NULL, fd, env);
		exit(1);
	}
	redirect_fd_pipe(NULL, fd, 3);
	free(fd);
	ft_case(env, ft_strdup(cmd[i]), cmd);
}

void	ft_pipe(char **env, char **cmd)
{
	pid_t	pid;
	int		len;
	int		res_temp;

	pid = fork();
	if (pid == -1)
		perror("minishell");
	if (pid == 0)
	{
		recover_signal();
		ft_master_pipe(cmd, env);
	}
	len = ft_tablen(cmd);
	while (len > 0)
	{
		if (waitpid(-1, &res_temp, 0) == pid)
			g_res_error = WEXITSTATUS(res_temp);
		len--;
	}
	ft_free_tab(cmd);
}
