/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_fd_heredoc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:44:50 by lle-saul          #+#    #+#             */
/*   Updated: 2024/01/23 17:42:26 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_malloc_path_fd(char *str, int len)
{
	char	*path;
	int		i;
	int		j;

	i = 0;
	j = 0;
	path = malloc(sizeof(char) * (len + 1));
	if (!path)
		return (NULL);
	while (j < len)
	{
		if (str[i] != '\'' && str[i] != '"')
			path[j++] = str[i];
		i++;
	}
	path[j++] = '\0';
	return (path);
}

char	*extract_path_fd(char *str)
{
	int		i;
	int		trig;
	int		len;

	i = 0;
	trig = 0;
	len = 0;
	while (str[i] != '\0' && (str[i] != ' ' || trig > 0))
	{
		ft_cote(&trig, str[i]);
		if (trig > 0 || str[i] != ' ')
			if (str[i] != '"' && str[i] != '\'')
				len++;
		i++;
	}
	return (ft_malloc_path_fd(str, len));
}

void	ft_reading_here_doc(char *end, int *fd_pipe, int *fd_tab)
{
	char	*line;

	close(fd_pipe[0]);
	while (1)
	{
		line = readline("> ");
		if (line == NULL || ft_strcmp(line, end) == 0)
			break ;
		ft_putstr_n(line, fd_pipe[1]);
		free(line);
	}
	close(fd_pipe[1]);
	free(fd_tab);
	free(line);
	free(end);
	exit(0);
}

void	ft_here_doc(char *end, int *fd_tab, int *fd_in)
{
	int	fd_pipe[2];
	int	pid;

	if (pipe(fd_pipe) == -1)
	{
		perror("minishell");
		*fd_in = -2;
		return ;
	}
	pid = fork();
	if (pid == -1)
	{
		close(fd_pipe[0]);
		close(fd_pipe[1]);
		perror("minishell");
		*fd_in = -1;
		return ;
	}
	if (pid == 0)
		ft_reading_here_doc(end, fd_pipe, fd_tab);
	waitpid(pid, NULL, 0);
	close(fd_pipe[1]);
	*fd_in = fd_pipe[0];
}

void	get_input_heredoc(int *fd_in, char *line, int *fd, int *j)
{
	char	*temp;
	char	*limiter;
	int		i;

	i = 0;
	++*j;
	while (line[i] == ' ')
		i++;
	temp = extract_path_fd(line + i);
	if (!temp)
	{
		*fd_in = -1;
		return ;
	}
	limiter = ft_strjoin(temp, "\n");
	free(temp);
	if (!limiter)
	{
		*fd_in = -1;
		return ;
	}
	ft_here_doc(limiter, fd, fd_in);
	free(limiter);
}
