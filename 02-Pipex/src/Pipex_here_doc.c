/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pipex_here_doc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 17:19:54 by lle-saul          #+#    #+#             */
/*   Updated: 2023/11/23 14:29:12 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pipex.h"

void	ft_reading_here_doc(char *end, int *fd)
{
	char	*line;

	close(fd[0]);
	while (1)
	{
		line = get_next_line(0);
		if (ft_strcmp(line, end) == 0)
			break ;
		ft_putstr(line, fd[1]);
		free(line);
	}
	get_next_line(-1);
	close(fd[1]);
	free(line);
	free(end);
	exit(0);
}

void	ft_here_doc2(int *fd)
{
	close(fd[1]);
	if (dup2(fd[0], STDIN_FILENO) == -1)
	{
		perror("pipex");
		exit(1);
	}
	close(fd[0]);
}

void	ft_here_doc(int	*a, char *end)
{
	int	fd[2];
	int	pid;

	*a = 1;
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
	if (pid == 0)
		ft_reading_here_doc(end, fd);
	else
		ft_here_doc2(fd);
}
