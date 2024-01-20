/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_fd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 17:11:36 by lle-saul          #+#    #+#             */
/*   Updated: 2024/01/20 17:11:36 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	error_fd(char *path, char **fd)
{
	ft_putstr("minishell: ", 1);
	ft_putstr(path, 1);
	ft_putstr(":", 1);
	perror("");
	ft_free_fd(fd);
	exit(1);
}

void	ft_free_fd(char **fd)
{
	if (fd[0])
		free(fd[0]);
	if (fd[1])
		free(fd[1]);
	free(fd);
}

int	ft_open_fd(char *fd_redir, char **fd, int nb_fd)
{
	int	fd_temp;

	if (nb_fd == 0)
	{
		fd_temp = open(fd_redir, O_RDONLY);
		if (fd_temp < 0)
			error_fd(fd_redir, fd);
	}
	else if (nb_fd == 1)
	{
		if (access(fd_redir, F_OK) == 0)
		{
			if (access(fd_redir, W_OK) == -1)
				error_fd(fd_redir, fd);
			else
				unlink(fd_redir);
		}
		fd_temp = open(fd_redir, O_RDWR | O_CREAT, 00777);
		if (fd_temp < 0)
			error_fd(fd_redir, fd);
	}
	return(fd_temp);
}

void	ft_redirect_fd(char *fd_redir, int fd_to, char **fd, int nb_fd)
{
	int	fd_temp;
	
	fd_temp = ft_open_fd(fd_redir, fd, nb_fd);
	if (dup2(fd_temp, fd_to) == -1)
	{
		perror("minishell");
		exit(1);
	}
}

void	ft_redirect_fd_pipe(int fd_redir, int fd_to, char **fd)
{
	if (dup2(fd_redir, fd_to) == -1)
	{
		perror("minishell");
		ft_free_fd(fd);
		exit(1);
	}
}
