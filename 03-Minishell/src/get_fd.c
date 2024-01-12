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

void	get_input(int *fd_in, char *line)
{
	char	*path;
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (line[i] == ' ')
		i++;
	while (line[i + len] != ' ' && line[i + len] != '\0')
		len++;
	path = ft_substr(line, i, len);
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
	while (line[i + len] != ' ' && line[i + len] != '\0')
		len++;
	path = ft_substr(line, i, len);
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
