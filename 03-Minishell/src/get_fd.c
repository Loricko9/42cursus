/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_fd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 18:09:19 by lle-saul          #+#    #+#             */
/*   Updated: 2024/02/03 18:48:58 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	error_fd(char *path, int *fd)
{
	*fd = -1;
	ft_putstr("\033[1;91mminishell: \033[0m", 2);
	ft_putstr(path, 2);
	ft_putstr(":", 2);
	perror("");
}

void	get_output_append(int *fd_out, char *line, int *j)
{
	char	*path;
	int		i;

	i = 0;
	++*j;
	while (line[i] == ' ')
		i++;
	path = extract_path_fd(line + i);
	if (*fd_out > 1)
		close(*fd_out);
	if (access(path, F_OK) == 0 && access(path, W_OK) == -1)
		*fd_out = -1;
	if (*fd_out != -1)
		*fd_out = open(path, O_RDWR | O_CREAT | O_APPEND, 00777);
	if (*fd_out < 0)
		error_fd(path, fd_out);
	free(path);
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

	i = 0;
	while (line[i] == ' ')
		i++;
	path = extract_path_fd(line + i);
	if (*fd_in > 0)
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

	i = 0;
	while (line[i] == ' ')
		i++;
	path = extract_path_fd(line + i);
	if (*fd_out > 1)
		close(*fd_out);
	if (access(path, F_OK) == 0)
	{
		if (access(path, W_OK) == -1)
			*fd_out = -1;
		else
			unlink(path);
	}
	if (*fd_out != -1)
		*fd_out = open(path, O_RDWR | O_CREAT, 00777);
	if (*fd_out < 1)
		error_fd(path, fd_out);
	free(path);
}
