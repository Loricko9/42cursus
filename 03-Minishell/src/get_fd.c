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

void	get_input(char **fd_in, char *line)
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
	if (*fd_in != NULL)
		free(fd_in);
	*fd_in = path;
}

void	get_output(char **fd_out, char *line)
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
	if (*fd_out != NULL)
		free(fd_out);
	*fd_out = path;
}
