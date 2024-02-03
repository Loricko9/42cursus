/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_signal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 12:14:36 by lle-saul          #+#    #+#             */
/*   Updated: 2024/02/03 16:51:17 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_signal(void)
{
	if (signal(SIGINT, exec_signal_print) == SIG_ERR)
	{
		perror("minishell");
		exit(1);
	}
	if (signal(SIGQUIT, SIG_IGN) == SIG_ERR)
	{
		perror("minishell");
		exit(1);
	}
}

void	exec_signal_print(int signum)
{
	(void)signum;
	close(0);
	if (g_res_sigint == 0)
		printf("\n");
	g_res_sigint = 1;
	g_res_error = 130;
}

void	recover_signal(void)
{
	if (signal(SIGINT, SIG_DFL) == SIG_ERR)
	{
		perror("minishell");
		exit(1);
	}
	if (signal(SIGQUIT, SIG_DFL) == SIG_ERR)
	{
		perror("minishell");
		exit(1);
	}
}

int	change_sigint(void)
{
	if (signal(SIGINT, exec_signal) == SIG_ERR)
	{
		perror("minishell");
		return (0);
	}
	return (1);
}

void	exec_signal(int signum)
{
	(void)signum;
}
