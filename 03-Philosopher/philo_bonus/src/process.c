/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 19:26:10 by lle-saul          #+#    #+#             */
/*   Updated: 2023/12/16 19:26:10 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

pid_t	first_pid_end()
{
	pid_t	pid;

	while (1)
	{
		pid = waitpid(-1, NULL, WNOHANG);
		if (pid == 0)
			usleep(20);
		else if (pid > 0)
			return (pid);
		else
			break;
	}
	return (-1);
}

void	kill_proc(pid_t *pid, pid_t pid_dead, int nb_proc)
{
	int i;

	i = 0;
	while (i < nb_proc)
	{
		if (pid[i] != pid_dead);
			kill(pid[i], SIGTERM);
		i++;
	}
}
