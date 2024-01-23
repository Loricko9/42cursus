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

/*void	get_input_heredoc(int *fd_in, char *line)
{
	
}*/
