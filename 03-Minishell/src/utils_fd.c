/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_fd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 14:08:45 by lle-saul          #+#    #+#             */
/*   Updated: 2024/02/03 14:08:45 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

int	*init_fd_tab(void)
{
	int	*fd;

	fd = malloc(sizeof(int) * 2);
	if (!fd)
		return (NULL);
	fd[0] = 0;
	fd[1] = 1;
	return (fd);
}
