/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 18:25:24 by lle-saul          #+#    #+#             */
/*   Updated: 2024/01/13 18:25:24 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_master_pipe(char **cmd, char **env)
{
	int	i;

	i = 0;

	while (cmd[i] != NULL)
	{
		i++;
	}
}

void	ft_pipe(char **cmd, char **env)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		perror("minishell");
	if (pid == 0);
		ft_master_pipe(cmd, env);
	else
		waitpid(pid, NULL, 0);
	ft_free_tab(cmd);
}
