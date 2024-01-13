/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_fd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 18:09:19 by lle-saul          #+#    #+#             */
/*   Updated: 2024/01/12 18:09:19 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	error_fd(char *path, int *fd)
{
	*fd = -2;
	ft_putstr("minishell: ", 1);
	ft_putstr(path, 1);
	ft_putstr(":", 1);
	perror("");
}

void	ft_redirect_fd(int fd_redir, int fd_to, int *fd)
{
	if (dup2(fd_redir, fd_to) == -1)
	{
		perror("minishell");
		if (fd)
			free(fd);
		exit(1);
	}
}

int	get_len_quote(char *str)
{
	char	trig;
	int		len;

	len = 0;
	trig = 0;
	while (str[len] != '\0' && (str[len] != ' ' || trig > 0))
	{
		if (trig == 0 && (str[len] == '"' || str[len] == '\''))
			trig = str[len];
		else if (trig > 0 && str[len] == trig)
			trig = 0;
		len++;
	}
	return (len);
}

void	get_input(int *fd_in, char *line)
{
	char	*path;
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (line[i] == ' ')
		i++;
	len = get_len_quote(line + i);
	path = ft_substr(line, i, len);
	if (*fd_in > -1)
		close(*fd_in);
	*fd_in = open(path, O_RDONLY);
	if (*fd_in < 0)
		error_fd(path, fd_in);
	free(path);
}

void	get_output(int *fd_out, char *line)
{
	char	*path;
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (line[i] == ' ')
		i++;
	len = get_len_quote(line + i);
	path = ft_substr(line, i, len);
	if (*fd_out > -1)
		close(*fd_out);
	if (access(path, F_OK) == 0)
	{
		if (access(path, W_OK) == -1)
			*fd_out = -2;
		else
			unlink(path);
	}
	if (*fd_out != -2)
		*fd_out = open(path, O_WRONLY | O_CREAT, 00777);
	if (*fd_out < 0)
		error_fd(path, fd_out);
	free(path); 
}
